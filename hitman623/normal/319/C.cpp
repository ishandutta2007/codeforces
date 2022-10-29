#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
#define int         long long 
// gives max y for an x
const int inf=1ll<<60;
int mode;
struct point{
    mutable int a,b,k;
    bool operator<(const point &p)const{return mode?k<p.k:a<p.a;}
};
struct hull{
    multiset<point> s;
    int div(int x,int y){return x/y-((x^y)<0&&x%y);}
    template<class T>bool test(T x,T y){
        if(y==s.end()){x->k=inf;return 0;}
        if(x->a==y->a)x->k=(x->b>=y->b?inf:-inf);
        else x->k=div(x->b-y->b,y->a-x->a);
        return x->k>=y->k;
    }
    void add(int a,int b){
        auto z=s.insert({a,b,0}),x=z++,y=x;
        while(test(x,z))z=s.erase(z);
        if(x!=s.begin()&&test(--x,y))test(x,s.erase(y));
        while((y=x)!=s.begin()&&test(--x,y))test(x,s.erase(y));
    }
    int query(int x){
        mode=1;
        auto pos=s.lower_bound({0,0,x});
        mode=0;
        return pos->a*x+pos->b;
    }
}cht;
int n,a[100005],b[100005],cur;
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,n+1) cin>>b[i];
    cht.add(-a[n],0);
    for(int i=n-1;i>=1;i--){
        cur=-cht.query(b[i]);
        cht.add(-a[i],-cur);
    }
    cout<<cur<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}