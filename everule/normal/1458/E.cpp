#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<array<int, 2>> sp(n);
    for(auto &[x,y] : sp) cin>>x>>y;
    auto cmp = [&](array<int, 2> l, array<int, 2> r){
        return l[1] - l[0] < r[1] - r[0];
    };
    sort(sp.begin(), sp.end(), cmp);
    vector<segment_tree<array<int,2>>> st(2, segment_tree<array<int, 2>>(n, [&](array<int, 2> l, array<int, 2> r){
        if(l[0] < r[0]) return l;
        else return r;
    }, {INF, INF}));
    for(int i=0;i<n;i++){
        st[0].set(i, {sp[i][0], i});
        st[1].set(i, {sp[i][1], i});
    }
    vector<array<int, 2>> ans;
    ans.push_back(array<int, 2>({0,0}));
    int curr = 0;
    int d = 0;
    set<int> none;
    while(true){
        int l2 = upper_bound(sp.begin(), sp.end(), array<int, 2>({0,d}), cmp) - sp.begin();// y - x > d
        int l1 = lower_bound(sp.begin(), sp.end(), array<int, 2>({0,d}), cmp) - sp.begin() - 1;//y - x < d
        auto h1 = st[0].query(0,l1);
        auto h2 = st[1].query(l2,n-1);
        h2[0] -= d;
        if(h1[1] == INF && h2[1] == INF){
            break;
        }
        int x = min(h1[0], h2[0]);
        while(true){
            auto h = st[0].query(l1 + 1, l2 - 1);
            if(h[1] == INF || h[0] >= x) break;
            st[0].set(h[1], st[0].base);
            st[1].set(h[1], st[1].base);
        }
        while(x == h1[0]){
            auto h = st[0].query(0, l1);
            if(h[1] == INF || h[0] != x) break;
            st[0].set(h[1], st[0].base);
            st[1].set(h[1], st[1].base);
        }
        while(x == h2[0]){
            auto h = st[1].query(l2, n-1);
            if(h[1] == INF || h[0] - d != x) break;
            st[0].set(h[1], st[0].base);
            st[1].set(h[1], st[1].base);
        }
        if(st[0].query(l1 + 1, l2 - 1)[0] == x){
            while(true){
                auto h = st[0].query(l1 + 1, l2 - 1);
                if(h[1] == INF || h[0] > x) break;
                st[0].set(h[1], st[0].base);
                st[1].set(h[1], st[1].base);
            }
            continue;
        }
        if(x == h2[0]){
            ans.emplace_back(array<int, 2>({h2[0], ans.back()[1] + 1}));
            ++d;
        }
        if(x == h1[0]){
            none.insert(h1[0]);
            ans.emplace_back(array<int, 2>({h1[0], ans.back()[1] - 1}));
            --d;
        }
    } 
    //for(auto &[x,y] : ans) cout<<x<<" "<<y<<"\n";
    sort(sp.begin(), sp.end());
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(binary_search(sp.begin(), sp.end(), array<int, 2>({x,y}))){
            cout<<"LOSE\n";
            continue;
        }
        if(none.count(x)){
            cout<<"WIN\n";
            continue;
        }
        cout<<((x + (*(upper_bound(ans.begin(), ans.end(), array<int, 2>({x,INF}), [&](array<int, 2> l, array<int, 2> r){
            return l[0] < r[0];
        }) - 1))[1] == y) ? "LOSE\n" : "WIN\n");
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}