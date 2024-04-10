#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
template<typename T>
struct merge_sort_tree {
    int n;
    vector<vector<T>> segtree;
    merge_sort_tree(int n = 0) : n(n){
        segtree.resize(n << 1);
    }
    void build() {
        for (int i = n - 1; i > 0; --i) {
            auto &a = segtree[(i<<1)];
            auto &b = segtree[(i<<1)|1];
            for(int i=0,j=0;i<a.size();i++){
                while(j < b.size() && a[i] > b[j]){
                    segtree[i].push_back(b[j]);
                    ++j;
                }
                segtree[i].push_back(a[i]);
            }
        }
    }
    merge_sort_tree(vector<T> seq) : n(seq.size()){
        segtree.resize(n << 1);
        for (int i = 0; i < n; i++) {
            segtree[n + i].push_back(seq[i]);
        }
        build();
    }
    void count(int idx, T ele){

    }
    T query(int l, int r, T ele) {
        int ans = 0;
        l += n;
        r += n + 1;
        while (l < r) {
            if (l & 1) {
                ans += count(l++, ele);
            }
            if (r & 1) {
                ans += count(--r, ele);
            }
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
    void add_element(int idx, T ele){
        idx += n;
        while(idx){
            segtree[idx].push_back(ele);
            idx >>= 1;
        }
    }
};
template<typename T>
struct segment_tree {
    int n;
    vector<T> segtree;
    function<T(const T&,const T&)> join;
    T base = T();
    segment_tree(int _n, function<T(const T&,const T&)> join, T base = T()) : n(_n), join(join), base(base){
        int k = 0;
        while((1<<k) < n){
            k++;
        }
        n = (1<<k);
        segtree.resize(n << 1, 1);
        build();
    }
    void build() {
        for (int i = n - 1; i > 0; --i) {
            segtree[i] = segtree[(i << 1)] + segtree[(i << 1) | 1];
        }
    }
    segment_tree(vector<T> seq, function<T(const T&,const T&)> join, T base = T()) : n(seq.size()), join(join), base(base){
        segtree.resize(n << 1, base);
        for (int i = 0; i < n; i++) {
            segtree[n + i] = seq[i];
        }
        build();
    }
    void calc(int pos){
        pos >>= 1;
        while (pos) {
            segtree[pos] = segtree[pos << 1] + segtree[(pos << 1) | 1];
            pos >>= 1;
        }
    }
    void set(int pos, T val){
        pos+=n;
        segtree[pos] = val;
        calc(pos);
    }
    void increment(int pos, T val){
        pos+=n;
        segtree[pos] = segtree[pos] + val;
        calc(pos);
    }
    T query(int l, int r) {
        T ans = 0;
        l += n;
        r += n + 1;
        while (l < r) {
            if (l & 1) {
                ans = ans + segtree[l++];
            }
            if (r & 1) {
                ans = segtree[--r] + ans;
            }
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
    int find(T val){
        if(segtree[1] < val) return -1;
        int idx = 1;
        int sum = 0;
        while(idx < n){
            if(sum + segtree[idx<<1] >= val){
                idx = (idx<<1);
            }
            else{
                sum += segtree[(idx<<1)];
                idx = ((idx<<1)|1);
            }
        }
        return idx - n;
    }
};
template<typename T>
struct node{
    T val = T();
    int left = -1;
    int right = -1;
};
node<int> mem[2300000];
template<typename T>
struct persistent_segment_tree{
    function<T(const T&,const T&)> join;
    int n;
    T base;
    int size = 0;
    vector<int> roots;
    persistent_segment_tree(int _n, function<T(const T&,const T&)> join, T base) : n(_n), join(join), base(base){
        n = 32 - __builtin_clz(n-1);
        n = (1<<n);
        size = 0;
        roots.push_back(build(0,n));
    }
    int build(int l,int r){
        int root = size;
        ++size;
        if(l+1==r){
            mem[root].val = base;
            mem[root].right = -1;
            mem[root].left = -1;
            return root;
        } 
        mem[root].left = build(l,(l+r)/2);
        mem[root].right = build((l+r)/2, r);
        mem[root].val = 0;
        return root;
    }
    void update(int pos, T val){
        int currnew = size;
        int currold = roots.back();
        roots.push_back(size);
        ++size;
        int l = 0, r = n;
        while(l + 1 < r){
            mem[currnew].val = mem[currold].val + 1;
            if(pos<(l+r)/2){
                mem[currnew].right = mem[currold].right;
                mem[currnew].left = size;
                ++size;
                currnew = mem[currnew].left;
                currold = mem[currold].left;
                r = (l+r)/2;
            }
            else{
                mem[currnew].left = mem[currold].left;
                mem[currnew].right = size;
                ++size;
                currnew = mem[currnew].right;
                currold = mem[currold].right;
                l = (l+r)/2;
            }   
        }
        mem[currnew].val = mem[currold].val + 1;
        mem[currnew].left = -1;
        mem[currnew].right = -1;
        //update(0,n, currnew, currold, pos, val);
    }
    int ql,qr;
    T query(int l,int r,int time){
        //assert(roots[time] != -1);
        ql = l;
        qr = r+1;
        return queryin(0,n,roots[time]);
    }
    T queryin(int l,int r, int curr){
        if(curr == -1 || l>=qr || r<=ql){
            return base;
        }
        if(ql <= l && r <= qr){
            return mem[curr].val;
        }
        return queryin(l,(l+r)/2, mem[curr].left) + queryin((l+r)/2, r, mem[curr].right);
    }
    int search(int k, int time){
        int l = 0, r = n;
        int curr = roots[time];
        int sum = 0;
        while(l + 1 < r){
            int ql = mem[mem[curr].left].val;
            if(sum + ql >= k){
                r = (l+r)/2;
                curr = mem[curr].left;
            }
            else{
                l = (l+r)/2;
                sum += ql;
                curr = mem[curr].right;
            }
        }
        return r - 1;
    }
};
const int SQRTN = 670;
void solve(){
    int n;
    //n = 1e5 + 7;
    cin>>n;
    vector<int> b(n);
    cin>>b;
    for(int i=0;i<n;i++){
        //b[i] = rand() % (i + 1);
        b[i] = i - b[i];
    }
    set<pair<int,int>> updates; 
    int q;
    //q = 1e5 + 7;
    cin>>q;
    persistent_segment_tree<int> pst(n, [&](int x,int y){
        return x+y;
    }, 0);
    vector<int> p(n);
    auto create = [&](){
        //cout<<"create"<<endl;
        //pst.clear();
        for(auto &[i,x] : updates){
            b[i] = x;
        }
        updates = set<pair<int,int>>();
        pst = persistent_segment_tree<int>(n, [&](int x,int y){
            return x+y;
        }, 0);
        //cout<<"cleared"<<endl;
        segment_tree<int> left(n, [&](int x,int y){
            return x+y;
        }, 0);
        for(int i=n-1;i>=0;--i){
            auto v = left.find(b[i] + 1);
            p[i] = v;
            left.set(v, 0);
        }
        for(auto &v : p) pst.update(v, 1);
        //cout<<"done"<<endl;
    };
    create();
    for(int i=0;i<q;i++){
        //cout<<i<<endl;
        int t;
        //t = (i % 2) + 1;
        cin>>t;
        if(t == 1){
            int i,x;
            cin>>i>>x;
            --i;x = i - x;
            //i = rand() % n;
            //x = rand() % (i + 1);
            auto pnt = updates.lower_bound({i, 0});
            if(pnt != updates.end() && (*pnt).first == i){
                updates.erase(pnt);
            }
            updates.insert({i,x});
        }
        if(t == 2){
            if(updates.size() > SQRTN) create();
            int i;
            cin>>i;
            --i;
            //i = 1;//rand() % n;
            auto pnt = updates.lower_bound({i, 0});
            int cval = p[i];
            if(pnt != updates.end() && (*pnt).first == i){
                int prev = b[i];
                int nxt = (*pnt).second;
                cval = pst.search(nxt+1, i+1);
            }
            for(auto it=pnt;it!=updates.end();it++){
                auto [j,x] = *it;
                if(j <= i) continue;
                int ord = pst.query(0, cval, j+1) - 1;
                if(b[j] < ord && ord <= x){
                    ord--;
                }
                if(b[j] > ord && ord >= x){
                    ord++;
                }
                cval = pst.search(ord+1, j+1);
            }
            cout<<cval + 1<<"\n";
        }
    }  
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
}