#include <iostream>
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
struct segment_tree{
    vector<int> segtree;
    int n;
    function<int(int,int)> join;
    int base;
    segment_tree(vector<int> &a, function<int(int,int)> join, int base) : join(join), base(base), n(a.size()){
        segtree.resize(2*n);
        for(int i=0;i<n;i++){
            segtree[n+i]=a[i];
        }
        for(int i=n-1;i>=1;i--){
            segtree[i]=join(segtree[2*i], segtree[2*i + 1]);
        }
    }
    void update(int pos, int val){
        pos+=n;
        segtree[pos]=val;
        pos>>=1;
        while(pos){
            segtree[pos]=join(segtree[2*pos],segtree[2*pos+1]);
            pos>>=1;
        }
    }
    int query(int x, int y){
        int ans = base;
        x+=n;
        y+=n+1;
        while(x<y){
            if(x&1){
                ans=join(ans, segtree[x++]);
            }
            if(y&1){
                ans=join(segtree[--y], ans);
            }
            x>>=1;
            y>>=1;
        }
        return ans;
    }
};
void solve(){
    int n,l,t;
    cin>>n>>l>>t;
    vector<int> seq(n);
    cin>>seq;
    sort(seq.begin(), seq.end());
    for(int i=0;i<n;i++){
        seq.pb(seq[i] + l);
    }
    long double ans = (ll)n*(n-1)/2* (t/l);
    t%=l;
    ans*=4;
    for(int i=0,j=0;i<n;i++){
        while(j+1 < 2*n && (seq[j+1] - seq[i]) <= 2*t){
            ++j;
        }
        ans+=(j-i);
    }
    cout<<fixed<<setprecision(10)<<ans/4<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}