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
struct segment_tree {
    int n;
    vector<T> segtree;
    function<T(const T&,const T&)> join;
    T base = T();
    segment_tree(int n, function<T(const T&,const T&)> join, T base = T()) : n(n), join(join), base(base){
        segtree.resize(n << 1, base);
    }
    void build() {
        for (int i = n - 1; i > 0; --i) {
            segtree[i] = join(segtree[(i << 1)], segtree[(i << 1) | 1]);
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
            segtree[pos] = join(segtree[pos << 1], segtree[(pos << 1) | 1]);
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
        segtree[pos] = join(segtree[pos], val);
        calc(pos);
    }
    T query(int l, int r) {
        T ansl = base;
        T ansr = base;
        l += n;
        r += n + 1;
        while (l < r) {
            if (l & 1) {
                ansl = join(ansl, segtree[l++]);
            }
            if (r & 1) {
                ansr = join(segtree[--r], ansr);
            }
            l >>= 1;
            r >>= 1;
        }
        return join(ansl, ansr);
    }
};
const int INF = 1e9;
struct query{
    array<int, 3> t_min;
    array<int, 3> t_max;
    string ans;
};
template<typename T>
struct merge_sort_tree{
    int n;
    int cnt = 0;
    vector<indexed_set<pair<T, int>>> mt;
    merge_sort_tree(int _n) : n(_n), mt(_n << 1) {}
    void add_element(int pos, T val){
        pos += n;
        while(pos){
            mt[pos].insert(make_pair(val, cnt));
            pos >>= 1;
        }
        cnt++;
    }
    int query_node(int u,int l,int r){
        return mt[u].order_of_key(make_pair(r, 1e9)) - mt[u].order_of_key(make_pair(l, -1));
    }
    int query(int l,int r, int vl, int vr){
        if(r < 0) return 0;
        int ans = 0;
        l += n;
        r += n + 1;
        while(l < r){
            if(l & 1){
                ans += query_node(l++, vl, vr);
            }
            if(r & 1){
                ans += query_node(--r, vl, vr);
            }
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
};
void solve(){
    array<int, 3> t_max;
    int n,m,k;
    cin>>t_max[0]>>t_max[1]>>t_max[2]>>n>>m>>k;
    array<int, 3> must_open_min = t_max, must_open_max = {0, 0, 0};
    for(int i=0;i<n;i++){
        array<int, 3> open_time;
        cin>>open_time[0]>>open_time[1]>>open_time[2];
        for(int i=0;i<3;i++) must_open_min[i] = min(must_open_min[i], open_time[i]);
        for(int i=0;i<3;i++) must_open_max[i] = max(must_open_max[i], open_time[i]);
    }
    vector<array<int, 3>> close_times(m);
    for(auto &[x,y,z] : close_times) cin>>x>>y>>z;
    vector<query> queries(k);
    for(auto &[t_min, t_max, ans] : queries){
        array<int, 3> q_time;
        cin>>q_time[0]>>q_time[1]>>q_time[2];
        t_min = must_open_min;
        t_max = must_open_max;
        for(int i=0;i<3;i++) t_min[i] = min(t_min[i], q_time[i]);
        for(int i=0;i<3;i++) t_max[i] = max(t_max[i], q_time[i]);
        if(t_min == must_open_min && t_max == must_open_max) ans = "OPEN";
    }
    sort(close_times.begin(), close_times.end());
    vector<array<int, 2>> qt;
    qt.reserve(k << 1);
    int _ = 1;
    for(auto &[t_min, t_max, ans] : queries){
        qt.push_back(array<int, 2>({t_min[0] - 1, -_}));
        qt.push_back(array<int, 2>({t_max[0], _}));
        _++;
    }
    vector<int> ans(k);
    merge_sort_tree<int> mt(t_max[1] + 1);
    sort(qt.begin(), qt.end());
    int qt_ptr = 0;
    for(auto &[x,y,z] : close_times){
        while(qt_ptr < 2 * k && qt[qt_ptr][0] < x){
            auto &[t_min, t_max, c_ans] = queries[abs(qt[qt_ptr][1]) - 1];
            ans[abs(qt[qt_ptr][1]) - 1] += mt.query(t_min[1], t_max[1], t_min[2], t_max[2]) * (qt[qt_ptr][1] > 0 ? 1 : -1);
            ++qt_ptr;
        }
        mt.add_element(y, z);
    }
    while(qt_ptr < 2 * k){
        auto &[t_min, t_max, c_ans] = queries[abs(qt[qt_ptr][1]) - 1];
        ans[abs(qt[qt_ptr][1]) - 1] += mt.query(t_min[1], t_max[1], t_min[2], t_max[2]) * (qt[qt_ptr][1] > 0 ? 1 : -1);
        ++qt_ptr;
    }
    for(auto &[x, y, z] : close_times){
        if(must_open_min[0] <= x && x <= must_open_max[0] && must_open_min[1] <= y && y <= must_open_max[1] && must_open_min[2] <= z && z <= must_open_max[2]){
            cout<<"INCORRECT\n";
            return;
        }
    }
    cout<<"CORRECT\n";
    _ = 0;
    for(auto &[t_min, t_max, c_ans] : queries){
        if(c_ans != ""){
            cout<<c_ans<<"\n";
        }
        else if(ans[_] > 0){
            cout<<"CLOSED\n";
        }
        else{
            cout<<"UNKNOWN\n";
        }
        _++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}