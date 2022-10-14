#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

const int N = 300000;

struct range{int l, r;};

int n, q, operation[N], parameter[N][2];

int list_size, list[N];

int heap_size;
range heap[N];

int root, tree_size, key[N], priority[N], child[N][2], total[N];

int place[N];

int compare_int(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int compare_range(range &a, range &b){
	if(a.r - a.l == b.r - b.l)
		return a.l - b.l;
	return (a.r - a.l) - (b.r - b.l);
}

int compare_heap(int i, int j){
	return compare_range(heap[i], heap[j]);
}

void swap_heap(int i, int j){
	range temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}

void push_heap(int l, int r){
	if(l > r)
		return;
	range temp = {l, r};
	heap[heap_size ++] = temp;
	int i = heap_size - 1;
	while(i > 0){
		int j = (i - 1) >> 1;
		if(compare_heap(j, i) >= 0)
			break;
		swap_heap(j, i);
		i = j;
	}
}

void pop_heap(){
	heap[0] = heap[-- heap_size];
	int i = 0;
	while(1){
		int j = i;
		if(i + i + 1 < heap_size && compare_heap(i + i + 1, j) > 0)
			j = i + i + 1;
		if(i + i + 2 < heap_size && compare_heap(i + i + 2, j) > 0)
			j = i + i + 2;
		if(i == j)
			break;
		swap_heap(j, i);
		i = j;
	}
}

void relabel(int a[], int &n){
	if(n == 0)
		return;
	qsort(a, n, sizeof(int), compare_int);
	int m = 1;
	for(int i = 1; i != n; ++ i)
		if(a[m - 1] != a[i])
			a[m ++] = a[i];
	n = m;
}

int label(int a[], int n, int x){
	return (int *)bsearch(&x, a, n, sizeof(int), compare_int) - a;
}

void update(int x){
	total[x] = total[child[x][0]] + 1 + total[child[x][1]];
}

void rotate(int &x, int t){
	int y = child[x][t];
	child[x][t] = child[y][1 - t];
	child[y][1 - t] = x;
	update(x);
	update(y);
	x = y;
}

void insert(int &x, int a){
	if(x == 0){
		x = ++ tree_size;
		key[x] = a;
		priority[x] = rand();
	}else{
		int t = key[x] < a;
		insert(child[x][t], a);
		if(priority[child[x][t]] < priority[x])
			rotate(x, t);
	}
	update(x);
}

void remove(int &x, int a){
	if(key[x] != a){
		remove(child[x][key[x] < a], a);
	}else{
		if(child[x][0] + child[x][1] == 0){
			x = 0;
			return;
		}else{
			rotate(x, priority[child[x][0]] > priority[child[x][1]]);
			remove(x, a);
		}
	}
	update(x);
}

int find_tree(int &x, int a, int b){
	if(x == 0)
		return -1;
	if(a * b < key[x] * b)
		return find_tree(child[x][b == -1], a, b);
	int tmp = find_tree(child[x][b != -1], a, b);
	return tmp == -1? key[x]: tmp;
}

int count(int &x, int a){
	if(x == 0)
		return 0;
	if(a < key[x])
		return count(child[x][0], a);
	return total[child[x][0]] + 1 + count(child[x][1], a);
}

int find_l(int x){
	return find_tree(root, x, 1) + 1;
}

int find_r(int x){
	return find_tree(root, x, -1) - 1;
}

int check(range x){
	if(find_l(x.r) != x.l)
		return 0;
	if(find_r(x.l) != x.r)
		return 0;
	return 1;
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 0; i != q; ++ i){
		scanf("%d", &operation[i]);
		if(operation[i] == 0)
			scanf("%d%d", &parameter[i][0], &parameter[i][1]);
	}

	for(int i = 0; i != q; ++ i)
		if(operation[i] != 0)
			list[list_size ++] = operation[i];
	relabel(list, list_size);
	for(int i = 0; i != q; ++ i)
		if(operation[i] != 0)
			operation[i] = label(list, list_size, operation[i]) + 1;

	priority[tree_size] = INT_MAX;
	insert(root, 0);
	insert(root, n + 1);
	push_heap(1, n);
	for(int i = 0; i != q; ++ i)
		if(operation[i] == 0){
			printf("%d\n", count(root, parameter[i][1]) - count(root, parameter[i][0] - 1));
		}else{
			int id = operation[i];
			int &p = place[id];
			if(p == 0){
				while(!check(heap[0]))
					pop_heap();
				p = (heap[0].l + heap[0].r + 1) >> 1;
				pop_heap();
				push_heap(find_l(p), p - 1);
				push_heap(p + 1, find_r(p));
				insert(root, p);
			}else{
				remove(root, p);
				push_heap(find_l(p), find_r(p));
				p = 0;
			}
		}

	return 0;
}