pub mod solution {

use crate::collections::arr2d::Arr2dRead;
use crate::collections::min_max::MinimMaxim;
use crate::collections::segment_tree::{SegmentTree, SegmentTreeNode};
use crate::io::input::Input;
use crate::io::output::output;
use crate::misc::recursive_function::{Callable3, RecursiveFunction3};
use crate::out_line;

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.read_usize();
    let q = input.read_usize();
    let a = input.read_table::<i64>(3, n);
    let mut offers: Vec<(usize, usize, i64)> = input.read_vec(q);

    offers.sort();
    let mut sb = 0;
    for i in 0..n {
        sb += a[(1, i)];
    }
    let mut switch_up = vec![0; n];
    switch_up[0] = a[(0, 0)];
    for i in 1..n {
        switch_up[i] = switch_up[i - 1] + a[(0, i)] - a[(1, i - 1)];
    }
    let mut switch_down = vec![0; n];
    switch_down[n - 1] = a[(2, n - 1)];
    for i in (0..n - 1).rev() {
        switch_down[i] = switch_down[i + 1] + a[(2, i)] - a[(1, i + 1)];
    }

    const INFTY: i64 = i64::MIN / 2;
    #[derive(Copy, Clone)]
    struct Node(i64);
    impl SegmentTreeNode for Node {
        fn new(_left: usize, _right: usize) -> Self {
            Self(INFTY)
        }

        fn join(&mut self, left: &Self, right: &Self) {
            self.0 = left.0.max(right.0)
        }

        fn accumulate(&mut self, _value: &Self) {}

        fn reset_delta(&mut self) {}
    }

    let mut up_tree = SegmentTree::from_generator(n, |i| Node(switch_up[i]));
    let mut down_tree = SegmentTree::from_generator(n, |i| Node(switch_down[i]));

    let mut ans = None;
    let mut v = vec![INFTY; 4 * n];
    for &(mut l, r, k) in &offers {
        l -= 1;
        let mut query = RecursiveFunction3::new(|f, root, from, to| -> i64 {
            if from >= r || to <= l {
                INFTY
            } else if from >= l && to <= r {
                v[root]
            } else {
                let mid = (from + to) >> 1;
                let lv = f.call(2 * root + 1, from, mid);
                let rv = f.call(2 * root + 2, mid, to);
                lv.max(rv)
            }
        });
        let mut cv = query.call(0, 0, n) - k;
        // ans.maxim(cv + down_tree.query(l, r).0);
        if r < n {
            cv.maxim(up_tree.query(l, r).0 - k);
            switch_up[r].maxim(cv);
            let mut update = RecursiveFunction3::new(|f, root: usize, from, to| {
                v[root].maxim(cv);
                if from + 1 == to {
                    return;
                }
                let mid = (from + to) >> 1;
                if mid > r {
                    f.call(2 * root + 1, from, mid);
                } else {
                    f.call(2 * root + 2, mid, to);
                }
            });
            update.call(0, 0, n);
        }
    }

    let mut res = vec![INFTY; 4 * n];
    let mut up = vec![INFTY; 4 * n];
    let mut down = vec![INFTY; 4 * n];
    let mut init = RecursiveFunction3::new(|f, root: usize, from, to| {
        if from + 1 == to {
            res[root] = switch_up[from] + switch_down[from];
            up[root] = switch_up[from];
            down[root] = switch_down[from];
            return;
        }
        let mid = (from + to) >> 1;
        f.call(2 * root + 1, from, mid);
        f.call(2 * root + 2, mid, to);
        up[root] = up[2 * root + 1].max(up[2 * root + 2]);
        down[root] = down[2 * root + 1].max(down[2 * root + 2]);
        res[root] = res[2 * root + 1]
            .max(res[2 * root + 2])
            .max(up[2 * root + 1] + down[2 * root + 2]);
    });
    init.call(0, 0, n);
    for (mut l, r, k) in offers {
        l -= 1;
        let mut query = RecursiveFunction3::new(|f, root: usize, from, to| -> (i64, i64, i64) {
            if from >= r || to <= l {
                (INFTY, INFTY, INFTY)
            } else if from >= l && to <= r {
                (res[root], up[root], down[root])
            } else {
                let mid = (from + to) >> 1;
                let (lr, lu, ld) = f.call(2 * root + 1, from, mid);
                let (rr, ru, rd) = f.call(2 * root + 2, mid, to);
                (lr.max(rr).max(lu + rd), lu.max(ru), ld.max(rd))
            }
        });
        ans.maxim(query.call(0, 0, n).0 - k);
    }
    out_line!(ans.unwrap() + sb);
}

pub(crate) fn run(mut input: Input) -> bool {
    #[allow(dead_code)]
    enum TestType {
        Single,
        MultiNumber,
        MultiEof,
    }
    let test_type = TestType::Single;
    match test_type {
        TestType::Single => solve(&mut input, 1),
        TestType::MultiNumber => {
            let t = input.read();
            for i in 0usize..t {
                solve(&mut input, i + 1);
            }
        }
        TestType::MultiEof => {
            let mut i = 1usize;
            while input.peek().is_some() {
                solve(&mut input, i);
                i += 1;
            }
        }
    }
    output().flush();
    input.skip_whitespace();
    !input.peek().is_some()
}

}
pub mod collections {
pub mod arr2d {
use crate::collections::legacy_fill::LegacyFill;
use crate::io::input::{Input, Readable};
use crate::io::output::{Output, Writable};
use std::ops::{Index, IndexMut};
use std::vec::IntoIter;

#[derive(Clone, Eq, PartialEq)]
pub struct Arr2d<T> {
    d1: usize,
    d2: usize,
    data: Vec<T>,
}

impl<T: Clone> Arr2d<T> {
    pub fn new(d1: usize, d2: usize, value: T) -> Self {
        Self {
            d1,
            d2,
            data: vec![value; d1 * d2],
        }
    }
}

impl<T> Arr2d<T> {
    pub fn generate<F>(d1: usize, d2: usize, mut gen: F) -> Self
    where
        F: FnMut(usize, usize) -> T,
    {
        let mut data = Vec::with_capacity(d1 * d2);
        for i in 0usize..d1 {
            for j in 0usize..d2 {
                data.push(gen(i, j));
            }
        }
        Self { d1, d2, data }
    }

    pub fn d1(&self) -> usize {
        self.d1
    }

    pub fn d2(&self) -> usize {
        self.d2
    }

    pub fn iter(&self) -> impl Iterator<Item = &T> {
        self.data.iter()
    }

    pub fn iter_mut(&mut self) -> impl Iterator<Item = &mut T> {
        self.data.iter_mut()
    }

    pub fn column(&self, col: usize) -> impl Iterator<Item = &T> {
        assert!(col < self.d2);
        self.data.iter().skip(col).step_by(self.d2)
    }

    pub fn column_mut(&mut self, col: usize) -> impl Iterator<Item = &mut T> {
        assert!(col < self.d2);
        self.data.iter_mut().skip(col).step_by(self.d2)
    }
}

impl<T: Clone> Arr2d<T> {
    pub fn fill(&mut self, elem: T) {
        self.data.legacy_fill(elem);
    }
}

impl<T> Index<(usize, usize)> for Arr2d<T> {
    type Output = T;

    fn index(&self, (row, col): (usize, usize)) -> &Self::Output {
        assert!(row < self.d1);
        assert!(col < self.d2);
        &self.data[self.d2 * row + col]
    }
}

impl<T> Index<usize> for Arr2d<T> {
    type Output = [T];

    fn index(&self, index: usize) -> &Self::Output {
        &self.data[self.d2 * index..self.d2 * (index + 1)]
    }
}

impl<T> IndexMut<(usize, usize)> for Arr2d<T> {
    fn index_mut(&mut self, (row, col): (usize, usize)) -> &mut T {
        assert!(row < self.d1);
        assert!(col < self.d2);
        &mut self.data[self.d2 * row + col]
    }
}

impl<T> IndexMut<usize> for Arr2d<T> {
    fn index_mut(&mut self, index: usize) -> &mut [T] {
        &mut self.data[self.d2 * index..self.d2 * (index + 1)]
    }
}

impl<T: Writable> Writable for Arr2d<T> {
    fn write(&self, output: &mut Output) {
        let mut at = 0usize;
        for i in 0usize..self.d1 {
            if i != 0 {
                output.put(b'\n');
            }
            for j in 0usize..self.d2 {
                if j != 0 {
                    output.put(b' ');
                }
                self.data[at].write(output);
                at += 1;
            }
        }
    }
}

impl<T> IntoIterator for Arr2d<T> {
    type Item = T;
    type IntoIter = IntoIter<T>;

    fn into_iter(self) -> Self::IntoIter {
        self.data.into_iter()
    }
}

pub trait Arr2dRead {
    fn read_table<T: Readable>(&mut self, d1: usize, d2: usize) -> Arr2d<T>;
}

impl Arr2dRead for Input<'_> {
    fn read_table<T: Readable>(&mut self, d1: usize, d2: usize) -> Arr2d<T> {
        Arr2d::generate(d1, d2, |_, _| self.read())
    }
}

pub trait Arr2dCharWrite {
    fn print_table(&mut self, table: &Arr2d<char>);
}

impl Arr2dCharWrite for Output {
    fn print_table(&mut self, table: &Arr2d<char>) {
        let mut at = 0usize;
        for _ in 0..table.d1 {
            for _ in 0..table.d2 {
                self.print(&table.data[at]);
                at += 1;
            }
            self.put(b'\n');
        }
    }
}

impl<T: Readable> Readable for Arr2d<T> {
    fn read(input: &mut Input) -> Self {
        let d1 = input.read();
        let d2 = input.read();
        input.read_table(d1, d2)
    }
}
}
pub mod legacy_fill {
// 1.50
pub trait LegacyFill<T> {
    fn legacy_fill(&mut self, val: T);
}

impl<T: Clone> LegacyFill<T> for [T] {
    fn legacy_fill(&mut self, val: T) {
        for el in self.iter_mut() {
            *el = val.clone();
        }
    }
}

impl<T: Clone> LegacyFill<T> for Vec<T> {
    fn legacy_fill(&mut self, val: T) {
        for el in self.iter_mut() {
            *el = val.clone();
        }
    }
}
}
pub mod min_max {
pub trait MinimMaxim<Rhs = Self>: PartialOrd + Sized {
    fn minim(&mut self, other: Rhs) -> bool;

    fn maxim(&mut self, other: Rhs) -> bool;
}

impl<T: PartialOrd + Sized> MinimMaxim for T {
    fn minim(&mut self, other: Self) -> bool {
        if other < *self {
            *self = other;
            true
        } else {
            false
        }
    }

    fn maxim(&mut self, other: Self) -> bool {
        if other > *self {
            *self = other;
            true
        } else {
            false
        }
    }
}

impl<T: PartialOrd + Sized> MinimMaxim<T> for Option<T> {
    fn minim(&mut self, other: T) -> bool {
        match self {
            None => {
                *self = Some(other);
                true
            }
            Some(v) => v.minim(other),
        }
    }

    fn maxim(&mut self, other: T) -> bool {
        match self {
            None => {
                *self = Some(other);
                true
            }
            Some(v) => v.maxim(other),
        }
    }
}
}
pub mod segment_tree {
use crate::misc::direction::Direction;
use std::marker::PhantomData;

pub trait SegmentTreeNode {
    fn new(left: usize, right: usize) -> Self;
    fn join(&mut self, left: &Self, right: &Self);
    fn accumulate(&mut self, value: &Self);
    fn reset_delta(&mut self);
}

#[derive(Clone)]
pub struct SegmentTree<Node> {
    n: usize,
    nodes: Vec<Node>,
}

impl<Node: SegmentTreeNode> SegmentTree<Node> {
    pub fn new(n: usize) -> Self {
        Self::from_generator(n, |left| Node::new(left, left + 1))
    }

    pub fn from_array(arr: Vec<Node>) -> Self {
        let n = arr.len();
        let mut iter = arr.into_iter();
        Self::from_generator(n, |_| iter.next().unwrap())
    }

    pub fn from_generator<F>(n: usize, gen: F) -> Self
    where
        F: FnMut(usize) -> Node,
    {
        if n == 0 {
            panic!("Empty seg trees not allowed");
        }
        let mut res = Self {
            n,
            nodes: Vec::with_capacity(2 * n - 1),
        };
        res.init(gen);
        res
    }

    fn init<F>(&mut self, mut f: F)
    where
        F: FnMut(usize) -> Node,
    {
        self.init_impl(2 * self.n - 2, 0, self.n, &mut f);
    }

    fn init_impl<F>(&mut self, root: usize, left: usize, right: usize, f: &mut F)
    where
        F: FnMut(usize) -> Node,
    {
        if left + 1 == right {
            self.nodes.push(f(left));
        } else {
            let mid = left + ((right - left) >> 1);
            let left_child = root - 2 * (right - mid);
            let right_child = root - 1;
            self.init_impl(left_child, left, mid, f);
            self.init_impl(right_child, mid, right, f);
            let mut node = Node::new(left, right);
            node.join(&self.nodes[left_child], &self.nodes[right_child]);
            self.nodes.push(node);
        }
    }

    pub fn point_query(&mut self, at: usize) -> &Node {
        assert!(at < self.n);
        self.do_point_query(2 * self.n - 2, 0, self.n, at)
    }

    fn do_point_query(&mut self, root: usize, left: usize, right: usize, at: usize) -> &Node {
        if left + 1 == right {
            &self.nodes[root]
        } else {
            let mid = (left + right) >> 1;
            self.push_down(root, mid, right);
            let left_child = root - 2 * (right - mid);
            let right_child = root - 1;
            if at < mid {
                self.do_point_query(left_child, left, mid, at)
            } else {
                self.do_point_query(right_child, mid, right, at)
            }
        }
    }

    pub fn point_update(&mut self, at: usize, val: &Node) {
        assert!(at < self.n);
        self.do_point_update(2 * self.n - 2, 0, self.n, at, val);
    }

    fn do_point_update(&mut self, root: usize, left: usize, right: usize, at: usize, val: &Node) {
        if left + 1 == right {
            self.nodes[root].accumulate(val);
        } else {
            let mid = (left + right) >> 1;
            self.push_down(root, mid, right);
            let left_child = root - 2 * (right - mid);
            let right_child = root - 1;
            if at < mid {
                self.do_point_update(left_child, left, mid, at, val);
            } else {
                self.do_point_update(right_child, mid, right, at, val);
            }
            self.join(root, mid, right);
        }
    }

    pub fn point_operation<Args, Res>(
        &mut self,
        op: &mut dyn PointOperation<Node, Args, Res>,
        args: Args,
    ) -> Res {
        self.do_point_operation(op, 2 * self.n - 2, 0, self.n, args)
    }

    fn do_point_operation<Args, Res>(
        &mut self,
        op: &mut dyn PointOperation<Node, Args, Res>,
        root: usize,
        left: usize,
        right: usize,
        args: Args,
    ) -> Res {
        if left + 1 == right {
            op.adjust_leaf(&mut self.nodes[root], left, args)
        } else {
            let mid = (left + right) >> 1;
            self.push_down(root, mid, right);
            let left_child = root - 2 * (right - mid);
            let right_child = root - 1;
            let (l, r) = self.nodes.split_at_mut(root);
            let (l, m) = l.split_at_mut(right_child);
            let direction = op.select_branch(
                &mut r[0],
                &mut l[left_child],
                &mut m[0],
                &args,
                left,
                mid,
                right,
            );
            let res = match direction {
                Direction::Left => self.do_point_operation(op, left_child, left, mid, args),
                Direction::Right => self.do_point_operation(op, right_child, mid, right, args),
            };
            self.join(root, mid, right);
            res
        }
    }

    pub fn update(&mut self, from: usize, to: usize, val: &Node) {
        self.do_update(2 * self.n - 2, 0, self.n, from, to, val)
    }

    pub fn do_update(
        &mut self,
        root: usize,
        left: usize,
        right: usize,
        from: usize,
        to: usize,
        val: &Node,
    ) {
        if left >= to || right <= from {
            // Do nothing
        } else if left >= from && right <= to {
            self.nodes[root].accumulate(val);
        } else {
            let mid = (left + right) >> 1;
            self.push_down(root, mid, right);
            let left_child = root - 2 * (right - mid);
            let right_child = root - 1;
            self.do_update(left_child, left, mid, from, to, val);
            self.do_update(right_child, mid, right, from, to, val);
            self.join(root, mid, right);
        }
    }

    pub fn operation<Args, Res>(
        &mut self,
        from: usize,
        to: usize,
        op: &mut dyn Operation<Node, Args, Res>,
        args: &Args,
    ) -> Res {
        self.do_operation(2 * self.n - 2, 0, self.n, from, to, op, args)
    }

    pub fn do_operation<Args, Res>(
        &mut self,
        root: usize,
        left: usize,
        right: usize,
        from: usize,
        to: usize,
        op: &mut dyn Operation<Node, Args, Res>,
        args: &Args,
    ) -> Res {
        if left >= to || right <= from {
            op.empty_result(left, right, args)
        } else if left >= from && right <= to {
            op.process_result(&mut self.nodes[root], args)
        } else {
            let mid = (left + right) >> 1;
            self.push_down(root, mid, right);
            let left_child = root - 2 * (right - mid);
            let right_child = root - 1;
            let left_result = self.do_operation(left_child, left, mid, from, to, op, args);
            let right_result = self.do_operation(right_child, mid, right, from, to, op, args);
            self.join(root, mid, right);
            op.join_results(left_result, right_result, args)
        }
    }

    fn join(&mut self, root: usize, mid: usize, right: usize) {
        let left_child = root - 2 * (right - mid);
        let right_child = root - 1;
        let (left, right) = self.nodes.split_at_mut(root);
        right[0].join(&left[left_child], &left[right_child]);
    }

    fn do_push_down(&mut self, parent: usize, to: usize) {
        let (left, right) = self.nodes.split_at_mut(parent);
        left[to].accumulate(&right[0]);
    }

    fn push_down(&mut self, root: usize, mid: usize, right: usize) {
        self.do_push_down(root, root - 2 * (right - mid));
        self.do_push_down(root, root - 1);
        self.nodes[root].reset_delta();
    }
}

impl<Node: SegmentTreeNode + Copy> SegmentTree<Node> {
    pub fn query(&mut self, from: usize, to: usize) -> Node {
        self.do_query(2 * self.n - 2, 0, self.n, from, to)
    }

    fn do_query(&mut self, root: usize, left: usize, right: usize, from: usize, to: usize) -> Node {
        if left >= to {
            Node::new(to, to)
        } else if right <= from {
            Node::new(from, from)
        } else if left >= from && right <= to {
            self.nodes[root]
        } else {
            let mid = (left + right) >> 1;
            self.push_down(root, mid, right);
            let left_child = root - 2 * (right - mid);
            let right_child = root - 1;
            let left_res = self.do_query(left_child, left, mid, from, to);
            let right_res = self.do_query(right_child, mid, right, from, to);
            let mut res = Node::new(left, right);
            res.join(&left_res, &right_res);
            res
        }
    }
}

pub trait PointOperation<Node: SegmentTreeNode, Args, Res = Node> {
    fn adjust_leaf(&mut self, leaf: &mut Node, at: usize, args: Args) -> Res;
    fn select_branch(
        &mut self,
        root: &mut Node,
        left_child: &mut Node,
        right_child: &mut Node,
        args: &Args,
        left: usize,
        mid: usize,
        right: usize,
    ) -> Direction;
}

pub struct PointOperationClosure<'s, Node: SegmentTreeNode, Args, Res = Node> {
    adjust_leaf: Box<dyn FnMut(&mut Node, usize, Args) -> Res + 's>,
    select_branch: Box<
        dyn FnMut(&mut Node, &mut Node, &mut Node, &Args, usize, usize, usize) -> Direction + 's,
    >,
    phantom_node: PhantomData<Node>,
    phantom_args: PhantomData<Args>,
    phantom_res: PhantomData<Res>,
}

impl<'s, Node: SegmentTreeNode, Args, Res> PointOperationClosure<'s, Node, Args, Res> {
    pub fn new<F1, F2>(adjust_leaf: F1, select_branch: F2) -> Self
    where
        F1: FnMut(&mut Node, usize, Args) -> Res + 's,
        F2: FnMut(&mut Node, &mut Node, &mut Node, &Args, usize, usize, usize) -> Direction + 's,
    {
        Self {
            adjust_leaf: Box::new(adjust_leaf),
            select_branch: Box::new(select_branch),
            phantom_node: Default::default(),
            phantom_args: Default::default(),
            phantom_res: Default::default(),
        }
    }
}

impl<'s, Node: SegmentTreeNode, Args, Res> PointOperation<Node, Args, Res>
    for PointOperationClosure<'s, Node, Args, Res>
{
    fn adjust_leaf(&mut self, leaf: &mut Node, at: usize, args: Args) -> Res {
        (self.adjust_leaf)(leaf, at, args)
    }

    fn select_branch(
        &mut self,
        root: &mut Node,
        left_child: &mut Node,
        right_child: &mut Node,
        args: &Args,
        left: usize,
        mid: usize,
        right: usize,
    ) -> Direction {
        (self.select_branch)(root, left_child, right_child, args, left, mid, right)
    }
}

pub trait Operation<Node: SegmentTreeNode, Args, Res = Node> {
    fn process_result(&mut self, node: &mut Node, args: &Args) -> Res;
    fn join_results(&mut self, left_res: Res, right_res: Res, args: &Args) -> Res;
    fn empty_result(&mut self, left: usize, right: usize, args: &Args) -> Res;
}

pub struct OperationClosure<'s, Node: SegmentTreeNode, Args, Res = Node> {
    process_result: Box<dyn FnMut(&mut Node, &Args) -> Res + 's>,
    join_results: Box<dyn FnMut(Res, Res, &Args) -> Res + 's>,
    empty_result: Box<dyn FnMut(usize, usize, &Args) -> Res + 's>,
    phantom_node: PhantomData<Node>,
    phantom_args: PhantomData<Args>,
    phantom_res: PhantomData<Res>,
}

impl<'s, Node: SegmentTreeNode, Args, Res> OperationClosure<'s, Node, Args, Res> {
    pub fn new<F1, F2, F3>(process_result: F1, join_results: F2, empty_result: F3) -> Self
    where
        F1: FnMut(&mut Node, &Args) -> Res + 's,
        F2: FnMut(Res, Res, &Args) -> Res + 's,
        F3: FnMut(usize, usize, &Args) -> Res + 's,
    {
        Self {
            process_result: Box::new(process_result),
            join_results: Box::new(join_results),
            empty_result: Box::new(empty_result),
            phantom_node: Default::default(),
            phantom_args: Default::default(),
            phantom_res: Default::default(),
        }
    }
}

impl<'s, Node: SegmentTreeNode, Args, Res> Operation<Node, Args, Res>
    for OperationClosure<'s, Node, Args, Res>
{
    fn process_result(&mut self, node: &mut Node, args: &Args) -> Res {
        (self.process_result)(node, args)
    }

    fn join_results(&mut self, left_res: Res, right_res: Res, args: &Args) -> Res {
        (self.join_results)(left_res, right_res, args)
    }

    fn empty_result(&mut self, left: usize, right: usize, args: &Args) -> Res {
        (self.empty_result)(left, right, args)
    }
}
}
}
pub mod io {
pub mod input {
use crate::numbers::num_traits::add_sub::AddSub;
use crate::numbers::num_traits::from_u8::FromU8;
use crate::numbers::num_traits::mul_div_rem::Multable;
use crate::numbers::num_traits::sign::IsSigned;
use crate::numbers::num_traits::zero_one::ZeroOne;
use std::fmt::Display;
use std::io::Read;
use std::marker::PhantomData;

macro_rules! read_impl {
    ($t: ty, $read_name: ident, $read_vec_name: ident) => {
        pub fn $read_name(&mut self) -> $t {
            self.read()
        }

        pub fn $read_vec_name(&mut self, len: usize) -> Vec<$t> {
            self.read_vec(len)
        }
    };

    ($t: ty, $read_name: ident, $read_vec_name: ident, $read_pair_vec_name: ident) => {
        read_impl!($t, $read_name, $read_vec_name);

        pub fn $read_pair_vec_name(&mut self, len: usize) -> Vec<($t, $t)> {
            self.read_vec(len)
        }
    };
}

pub struct Input<'s> {
    input: &'s mut dyn Read,
    buf: Vec<u8>,
    at: usize,
    buf_read: usize,
}

impl<'s> Input<'s> {
    const DEFAULT_BUF_SIZE: usize = 4096;

    pub fn new(input: &'s mut dyn Read) -> Self {
        Self {
            input,
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            buf_read: 0,
        }
    }

    pub fn new_with_size(input: &'s mut dyn Read, buf_size: usize) -> Self {
        Self {
            input,
            buf: vec![0; buf_size],
            at: 0,
            buf_read: 0,
        }
    }

    pub fn get(&mut self) -> Option<u8> {
        if self.refill_buffer() {
            let res = self.buf[self.at];
            self.at += 1;
            Some(res)
        } else {
            None
        }
    }

    pub fn peek(&mut self) -> Option<u8> {
        if self.refill_buffer() {
            Some(self.buf[self.at])
        } else {
            None
        }
    }

    pub fn skip_whitespace(&mut self) {
        while let Some(b) = self.peek() {
            if !char::from(b).is_whitespace() {
                return;
            }
            self.get();
        }
    }

    pub fn next_token(&mut self) -> Option<Vec<u8>> {
        self.skip_whitespace();
        let mut res = Vec::new();
        while let Some(c) = self.get() {
            if char::from(c).is_whitespace() {
                break;
            }
            res.push(c);
        }
        if res.is_empty() {
            None
        } else {
            Some(res)
        }
    }

    //noinspection RsSelfConvention
    pub fn is_exhausted(&mut self) -> bool {
        self.peek().is_none()
    }

    pub fn read<T: Readable>(&mut self) -> T {
        T::read(self)
    }

    pub fn read_vec<T: Readable>(&mut self, size: usize) -> Vec<T> {
        let mut res = Vec::with_capacity(size);
        for _ in 0usize..size {
            res.push(self.read());
        }
        res
    }

    pub fn read_line(&mut self) -> String {
        let mut res = String::new();
        while let Some(c) = self.get() {
            if c == b'\n' {
                break;
            }
            if c == b'\r' {
                if self.peek() == Some(b'\n') {
                    self.get();
                }
                break;
            }
            res.push(c.into());
        }
        res
    }

    pub fn iter<'t, T: Readable + 't + 's>(&'t mut self) -> InputIterator<'t, 's, T>
    where
        's: 't,
    {
        InputIterator {
            input: self,
            phantom: Default::default(),
        }
    }

    fn read_integer<T: IsSigned + ZeroOne + FromU8 + AddSub + Multable + Display>(&mut self) -> T {
        self.skip_whitespace();
        let mut c = self.get().unwrap();
        let sgn = if c == b'-' {
            if !T::SIGNED {
                panic!("negative integer")
            }
            c = self.get().unwrap();
            true
        } else if c == b'+' {
            c = self.get().unwrap();
            false
        } else {
            false
        };
        let mut res = T::zero();
        loop {
            if !c.is_ascii_digit() {
                panic!(
                    "expected integer, found {}{}{}",
                    if sgn { "-" } else { "" },
                    res,
                    c as char
                );
            }
            res *= T::from_u8(10);
            res += T::from_u8(c - b'0');
            match self.get() {
                None => {
                    break;
                }
                Some(ch) => {
                    if char::from(ch).is_whitespace() {
                        break;
                    } else {
                        c = ch;
                    }
                }
            }
        }
        if sgn {
            debug_assert!(T::SIGNED);
            res = T::zero() - res
        }
        res
    }

    pub fn read_string(&mut self) -> String {
        match self.next_token() {
            None => {
                panic!("Input exhausted");
            }
            Some(res) => unsafe { String::from_utf8_unchecked(res) },
        }
    }

    pub fn read_char(&mut self) -> char {
        self.skip_whitespace();
        self.get().unwrap().into()
    }

    read_impl!(u8, read_u8, read_u8_vec);
    read_impl!(u16, read_u16, read_u16_vec);
    read_impl!(u32, read_unsigned, read_unsigned_vec);
    read_impl!(u64, read_u64, read_u64_vec);
    read_impl!(u128, read_u128, read_u128_vec);
    read_impl!(usize, read_usize, read_usize_vec, read_usize_pair_vec);
    read_impl!(i8, read_i8, read_i8_vec);
    read_impl!(i16, read_i16, read_i16_vec);
    read_impl!(i32, read_int, read_int_vec, read_int_pair_vec);
    read_impl!(i64, read_long, read_long_vec, read_long_pair_vec);
    read_impl!(i128, read_i128, read_i128_vec);
    read_impl!(isize, read_isize, read_isize_vec);
    read_impl!(f64, read_float, read_float_vec);

    fn read_float_impl(&mut self) -> f64 {
        self.read::<String>().parse().unwrap()
    }

    fn refill_buffer(&mut self) -> bool {
        if self.at == self.buf_read {
            self.at = 0;
            self.buf_read = self.input.read(&mut self.buf).unwrap();
            self.buf_read != 0
        } else {
            true
        }
    }
}

pub struct InputIterator<'t, 's: 't, T: Readable + 't + 's> {
    input: &'t mut Input<'s>,
    phantom: PhantomData<T>,
}

impl<'t, 's: 't, T: Readable + 't + 's> Iterator for InputIterator<'t, 's, T> {
    type Item = T;

    fn next(&mut self) -> Option<Self::Item> {
        self.input.skip_whitespace();
        self.input.peek().map(|_| self.input.read())
    }
}

pub trait Readable {
    fn read(input: &mut Input) -> Self;
}

impl Readable for String {
    fn read(input: &mut Input) -> Self {
        input.read_string()
    }
}

impl Readable for char {
    fn read(input: &mut Input) -> Self {
        input.read_char()
    }
}

impl Readable for f64 {
    fn read(input: &mut Input) -> Self {
        input.read_float_impl()
    }
}

impl<T: Readable> Readable for Vec<T> {
    fn read(input: &mut Input) -> Self {
        let size = input.read();
        input.read_vec(size)
    }
}

macro_rules! read_integer {
    ($t:ident) => {
        impl Readable for $t {
            fn read(input: &mut Input) -> Self {
                input.read_integer()
            }
        }
    };
}

read_integer!(i8);
read_integer!(i16);
read_integer!(i32);
read_integer!(i64);
read_integer!(i128);
read_integer!(isize);
read_integer!(u8);
read_integer!(u16);
read_integer!(u32);
read_integer!(u64);
read_integer!(u128);
read_integer!(usize);

macro_rules! tuple_readable {
    ( $( $name:ident )+ ) => {
        impl<$($name: Readable), +> Readable for ($($name,)+) {
            fn read(input: &mut Input) -> Self {
                ($($name::read(input),)+)
            }
        }
    }
}

tuple_readable! {T}
tuple_readable! {T U}
tuple_readable! {T U V}
tuple_readable! {T U V X}
tuple_readable! {T U V X Y}
tuple_readable! {T U V X Y Z}
tuple_readable! {T U V X Y Z A}
tuple_readable! {T U V X Y Z A B}
tuple_readable! {T U V X Y Z A B C}
tuple_readable! {T U V X Y Z A B C D}
tuple_readable! {T U V X Y Z A B C D E}
tuple_readable! {T U V X Y Z A B C D E F}
}
pub mod output {
use std::io::Write;

pub struct Output {
    output: Box<dyn Write>,
    buf: Vec<u8>,
    at: usize,
    auto_flush: bool,
}

impl Output {
    const DEFAULT_BUF_SIZE: usize = 4096;

    pub fn new(output: Box<dyn Write>) -> Self {
        Self {
            output,
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            auto_flush: false,
        }
    }

    pub fn new_with_auto_flush(output: Box<dyn Write>) -> Self {
        Self {
            output,
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            auto_flush: true,
        }
    }

    pub fn flush(&mut self) {
        if self.at != 0 {
            self.output.write_all(&self.buf[..self.at]).unwrap();
            self.output.flush().unwrap();
            self.at = 0;
        }
    }

    pub fn print<T: Writable>(&mut self, s: &T) {
        s.write(self);
    }

    pub fn put(&mut self, b: u8) {
        self.buf[self.at] = b;
        self.at += 1;
        if self.at == self.buf.len() {
            self.flush();
        }
    }

    pub fn maybe_flush(&mut self) {
        if self.auto_flush {
            self.flush();
        }
    }

    pub fn print_per_line<T: Writable>(&mut self, arg: &[T]) {
        for i in arg {
            i.write(self);
            self.put(b'\n');
        }
    }

    pub fn print_iter<T: Writable, I: Iterator<Item = T>>(&mut self, iter: I) {
        let mut first = true;
        for e in iter {
            if first {
                first = false;
            } else {
                self.put(b' ');
            }
            e.write(self);
        }
    }

    pub fn print_iter_ref<'a, T: 'a + Writable, I: Iterator<Item = &'a T>>(&mut self, iter: I) {
        let mut first = true;
        for e in iter {
            if first {
                first = false;
            } else {
                self.put(b' ');
            }
            e.write(self);
        }
    }
}

impl Write for Output {
    fn write(&mut self, buf: &[u8]) -> std::io::Result<usize> {
        let mut start = 0usize;
        let mut rem = buf.len();
        while rem > 0 {
            let len = (self.buf.len() - self.at).min(rem);
            self.buf[self.at..self.at + len].copy_from_slice(&buf[start..start + len]);
            self.at += len;
            if self.at == self.buf.len() {
                self.flush();
            }
            start += len;
            rem -= len;
        }
        if self.auto_flush {
            self.flush();
        }
        Ok(buf.len())
    }

    fn flush(&mut self) -> std::io::Result<()> {
        self.flush();
        Ok(())
    }
}

pub trait Writable {
    fn write(&self, output: &mut Output);
}

impl Writable for &str {
    fn write(&self, output: &mut Output) {
        output.write_all(self.as_bytes()).unwrap();
    }
}

impl Writable for String {
    fn write(&self, output: &mut Output) {
        output.write_all(self.as_bytes()).unwrap();
    }
}

impl Writable for char {
    fn write(&self, output: &mut Output) {
        output.put(*self as u8);
    }
}

impl<T: Writable> Writable for &[T] {
    fn write(&self, output: &mut Output) {
        output.print_iter_ref(self.iter());
    }
}

impl<T: Writable> Writable for &T {
    fn write(&self, output: &mut Output) {
        T::write(self, output)
    }
}

impl<T: Writable> Writable for Vec<T> {
    fn write(&self, output: &mut Output) {
        (&self[..]).write(output);
    }
}

macro_rules! write_to_string {
    ($t:ident) => {
        impl Writable for $t {
            fn write(&self, output: &mut Output) {
                self.to_string().write(output);
            }
        }
    };
}

write_to_string!(u8);
write_to_string!(u16);
write_to_string!(u32);
write_to_string!(u64);
write_to_string!(u128);
write_to_string!(usize);
write_to_string!(i8);
write_to_string!(i16);
write_to_string!(i32);
write_to_string!(i64);
write_to_string!(i128);
write_to_string!(isize);
write_to_string!(f32);
write_to_string!(f64);

impl<T: Writable, U: Writable> Writable for (T, U) {
    fn write(&self, output: &mut Output) {
        self.0.write(output);
        output.put(b' ');
        self.1.write(output);
    }
}

impl<T: Writable, U: Writable, V: Writable> Writable for (T, U, V) {
    fn write(&self, output: &mut Output) {
        self.0.write(output);
        output.put(b' ');
        self.1.write(output);
        output.put(b' ');
        self.2.write(output);
    }
}

impl<T: Writable> Writable for Option<T> {
    fn write(&self, output: &mut Output) {
        match self {
            None => (-1).write(output),
            Some(t) => t.write(output),
        }
    }
}

impl Writable for bool {
    fn write(&self, output: &mut Output) {
        if *self {
            output.print(&"YES");
        } else {
            output.print(&"NO");
        }
    }
}

pub static mut OUTPUT: Option<Output> = None;

pub fn output() -> &'static mut Output {
    unsafe {
        match &mut OUTPUT {
            None => {
                panic!("Panic");
            }
            Some(output) => output,
        }
    }
}

#[macro_export]
macro_rules! out {
    ($first: expr $(,$args:expr )*) => {
        $crate::io::output::output().print(&$first);
        $($crate::io::output::output().put(b' ');
        $crate::io::output::output().print(&$args);
        )*
        $crate::io::output::output().maybe_flush();
    }
}

#[macro_export]
macro_rules! out_line {
    ($first: expr $(, $args:expr )* ) => {
        $crate::out!($first $(,$args)*);
        $crate::io::output::output().put(b'\n');
        $crate::io::output::output().maybe_flush();
    };
    () => {
        output().put(b'\n');
        output().maybe_flush();
    };
}
}
}
pub mod misc {
pub mod direction {
pub enum Direction {
    Left,
    Right,
}
}
pub mod recursive_function {
use std::marker::PhantomData;

macro_rules! recursive_function {
    ($name: ident, $trait: ident, ($($type: ident $arg: ident,)*)) => {
        pub trait $trait<$($type, )*Output> {
            fn call(&mut self, $($arg: $type,)*) -> Output;
        }

        pub struct $name<F, $($type, )*Output>
        where
            F: FnMut(&mut dyn $trait<$($type, )*Output>, $($type, )*) -> Output,
        {
            f: std::cell::UnsafeCell<F>,
            $($arg: PhantomData<$type>,
            )*
            phantom_output: PhantomData<Output>,
        }

        impl<F, $($type, )*Output> $name<F, $($type, )*Output>
        where
            F: FnMut(&mut dyn $trait<$($type, )*Output>, $($type, )*) -> Output,
        {
            pub fn new(f: F) -> Self {
                Self {
                    f: std::cell::UnsafeCell::new(f),
                    $($arg: Default::default(),
                    )*
                    phantom_output: Default::default(),
                }
            }
        }

        impl<F, $($type, )*Output> $trait<$($type, )*Output> for $name<F, $($type, )*Output>
        where
            F: FnMut(&mut dyn $trait<$($type, )*Output>, $($type, )*) -> Output,
        {
            fn call(&mut self, $($arg: $type,)*) -> Output {
                unsafe { (&mut *self.f.get())(self, $($arg, )*) }
            }
        }
    }
}

recursive_function!(RecursiveFunction0, Callable0, ());
recursive_function!(RecursiveFunction, Callable, (Arg arg,));
recursive_function!(RecursiveFunction2, Callable2, (Arg1 arg1, Arg2 arg2,));
recursive_function!(RecursiveFunction3, Callable3, (Arg1 arg1, Arg2 arg2, Arg3 arg3,));
recursive_function!(RecursiveFunction4, Callable4, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4,));
recursive_function!(RecursiveFunction5, Callable5, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5,));
recursive_function!(RecursiveFunction6, Callable6, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6,));
recursive_function!(RecursiveFunction7, Callable7, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7,));
recursive_function!(RecursiveFunction8, Callable8, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7, Arg8 arg8,));
recursive_function!(RecursiveFunction9, Callable9, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7, Arg8 arg8, Arg9 arg9,));
}
}
pub mod numbers {
pub mod num_traits {
pub mod add_sub {
use std::ops::{Add, AddAssign, Sub, SubAssign};

pub trait Addable: Add<Output = Self> + AddAssign + Copy {}
impl<T: Add<Output = Self> + AddAssign + Copy> Addable for T {}

pub trait AddSub: Addable + Sub<Output = Self> + SubAssign {}
impl<T: Addable + Sub<Output = Self> + SubAssign> AddSub for T {}
}
pub mod from_u8 {
pub trait FromU8 {
    fn from_u8(val: u8) -> Self;
}

macro_rules! from_u8_impl {
    ($t: ident) => {
        impl FromU8 for $t {
            fn from_u8(val: u8) -> Self {
                val as $t
            }
        }
    };
}

from_u8_impl!(i128);
from_u8_impl!(i64);
from_u8_impl!(i32);
from_u8_impl!(i16);
from_u8_impl!(i8);
from_u8_impl!(isize);
from_u8_impl!(u128);
from_u8_impl!(u64);
from_u8_impl!(u32);
from_u8_impl!(u16);
from_u8_impl!(u8);
from_u8_impl!(usize);
from_u8_impl!(f32);
from_u8_impl!(f64);
}
pub mod mul_div_rem {
use std::ops::{Div, DivAssign, Mul, MulAssign, Rem, RemAssign};

pub trait Multable: Mul<Output = Self> + MulAssign + Copy {}
impl<T: Mul<Output = Self> + MulAssign + Copy> Multable for T {}

pub trait MulDiv: Multable + Div<Output = Self> + DivAssign {}
impl<T: Multable + Div<Output = Self> + DivAssign> MulDiv for T {}

pub trait MulDivRem: MulDiv + Rem<Output = Self> + RemAssign {}
impl<T: MulDiv + Rem<Output = Self> + RemAssign> MulDivRem for T {}
}
pub mod sign {
pub trait IsSigned {
    const SIGNED: bool;
}

pub trait Signed: IsSigned {}

pub trait Unsigned: IsSigned {}

macro_rules! unsigned_impl {
    ($t: ident) => {
        impl Unsigned for $t {}

        impl IsSigned for $t {
            const SIGNED: bool = false;
        }
    };
}

unsigned_impl!(u128);
unsigned_impl!(u64);
unsigned_impl!(u32);
unsigned_impl!(u16);
unsigned_impl!(u8);
unsigned_impl!(usize);

macro_rules! signed_impl {
    ($t: ident) => {
        impl Signed for $t {}

        impl IsSigned for $t {
            const SIGNED: bool = true;
        }
    };
}

signed_impl!(i128);
signed_impl!(i64);
signed_impl!(i32);
signed_impl!(i16);
signed_impl!(i8);
signed_impl!(isize);
signed_impl!(f64);
signed_impl!(f32);
}
pub mod zero_one {
pub trait ZeroOne {
    fn zero() -> Self;
    fn one() -> Self;
}

macro_rules! zero_one_integer_impl {
    ($t: ident) => {
        impl ZeroOne for $t {
            fn zero() -> Self {
                0
            }

            fn one() -> Self {
                1
            }
        }
    };
}

zero_one_integer_impl!(i128);
zero_one_integer_impl!(i64);
zero_one_integer_impl!(i32);
zero_one_integer_impl!(i16);
zero_one_integer_impl!(i8);
zero_one_integer_impl!(isize);
zero_one_integer_impl!(u128);
zero_one_integer_impl!(u64);
zero_one_integer_impl!(u32);
zero_one_integer_impl!(u16);
zero_one_integer_impl!(u8);
zero_one_integer_impl!(usize);

macro_rules! zero_one_float_impl {
    ($t: ident) => {
        impl ZeroOne for $t {
            fn zero() -> Self {
                0.
            }

            fn one() -> Self {
                1.
            }
        }
    };
}

zero_one_float_impl!(f32);
zero_one_float_impl!(f64);
}
}
}
fn main() {
    let mut sin = std::io::stdin();
    let input = crate::io::input::Input::new(&mut sin);
    unsafe {
        crate::io::output::OUTPUT = Some(crate::io::output::Output::new(Box::new(std::io::stdout())));
    }
    crate::solution::run(input);
}