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
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    auto find = [&](int x){
        for(int i=0;i<n;i++) if(seq[i]==x) return i;
        return -1;
    };
    if(n==1){
        cout<<"0\n";
        return;
    }
    auto finished = [&](bool pre){
        if(pre){
            for(int i=0;i<n;i++){
                if(seq[i]!=i+1) return i;
            }
            return n;
        }
        else{
            for(int i=n-1;i>=0;--i){
                if(seq[i]!=n-i) return n-i-1;
            }
            return n;
        }
        return -1;
    };
    bool pre = 0;
    auto op = [&](vector<int> opr){
        int k = opr.size();
        int idx = 0;
        vector<vector<int>> now(k);
        for(int i=0;i<k;i++){
            for(int j=0;j<opr[i];j++){
                now[i].pb(seq[idx]);
                ++idx;
            }
        }
        reverse(now.begin(), now.end());
        seq.clear();
        for(const auto &v : now){
            for(const auto &x : v){
                seq.pb(x);
            }
        }
    };
    vector<vector<int>> ops;
    int p1 = find(1);
    if(n&1){
        pre = 1;
        if(p1){
            ops.pb({p1, n-p1});
            op(ops.back());
        }
    }
    else{
        if(p1!=n-1){
            ops.pb({p1+1, n-p1-1});
            op(ops.back());
        }
    }
    for(int i=0;i<n;i++){
        int solved = finished(pre);
        if(solved==n) break;
        int pos = find(solved + 1);
        if(pre){
            ops.pb({});
            for(int i=0;i<solved;i++) ops.back().pb(1);
            pos-=solved;     
            ops.back().pb(pos+1);
            if(n-solved-pos-1) ops.back().pb(n-solved-pos-1);
            op(ops.back());
        }
        else{
            ops.pb({});
            if(pos) ops.back().pb(pos);
            ops.back().pb(n-solved-pos);
            for(int i=0;i<solved;i++) ops.back().pb(1);
            op(ops.back());
        }
        pre^=1;
    }
    if(!pre){
        ops.pb({});
        for(int i=0;i<n;i++) ops.back().pb(1);
        op(ops.back());
    }
    assert(ops.size()<=n);
    for(int i=0;i<n;i++) assert(seq[i]==i+1);
    cout<<ops.size()<<"\n";
    for(const auto &v : ops){
        cout<<v.size()<<" ";
        for(const auto &x : v) cout<<x<<" ";
        cout<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}