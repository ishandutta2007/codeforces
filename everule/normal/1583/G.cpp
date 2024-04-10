#include <bits/stdc++.h>
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
const int p = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    vector<int> time_to_come_back(2 * n);
    vector<int> events(n << 1);
    vector<array<int, 2>> tasks(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        --a;--b;
        events[a] = -i - 1;
        events[b] = i;
        tasks[i] = {a, b};
    }
    int t;
    cin>>t;
    vector<bool> to_complete(n);
    for(int i=0;i<t;i++){
        int x;
        cin>>x;
        --x;
        to_complete[x] = 1;
    }
    segment_tree<int> st(2 * n, [&](int x,int y){
        return (x + y) % p;
    }, 0);
    for(int i=0;i<2*n;i++){
        if(events[i] < 0) continue;
        time_to_come_back[i] = st.query(tasks[events[i]][0], tasks[events[i]][1]) + 1;
        st.increment(tasks[events[i]][0], time_to_come_back[i]);
    }
    auto cmpb = [&](int x,int y){
        return tasks[x][1] < tasks[y][1];
    };
    auto cmpa = [&](int x,int y){
        return tasks[x][0] < tasks[y][0];
    };
    set<int, decltype(cmpb)> st_b(cmpb);
    set<int, decltype(cmpa)> st_a(cmpa);
    for(int i=0;i<n;i++) st_a.insert(i), st_b.insert(i);
    ll ans = 0;
    int start = 0;
    segment_tree<int> time_to_reach(time_to_come_back, [&](int x,int y){
        return (x + y) % p;
    }, 0);
    while(st_b.size() > 0){
        while(st_a.size() > 0){
            auto it = st_a.begin();
            if(tasks[*it][0] < start){
                time_to_reach.set(tasks[*it][1], 0);
                st_b.erase(*it);
                st_a.erase(*it);
            }
            else{
                break;
            }
        }
        while(st_b.size() > 0){
            auto it = st_b.rbegin();
            if(!to_complete[*it]){
                st_a.erase(*it);
                st_b.erase(*it);
            }
            else break;
        }
        if(st_b.size() == 0) break;
        int end = tasks[*st_b.rbegin()][1];
        //for(auto &x : st_a) cout<<x<<" ";
        //cout<<'\n';
        //for(auto &x : st_b) cout<<x<<" ";
        //cout<<"\n";
        //cout<<start<<" "<<end<<" "<<time_to_reach.query(start, end - 1)<<"\n";
        //cout<<"\n";
        ans += time_to_reach.query(start, end - 1) + 1;
        start = tasks[*st_b.rbegin()][0];
        st_a.erase(*st_b.rbegin());
        st_b.erase(*st_b.rbegin());
    }
    cout<<ans % p<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}