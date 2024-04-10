#include <bits/stdc++.h>
 
#define int         long long
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
#define hell        1000000000000000000
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
bool p[10001];
vi primes;
void process_seive(int n){
    memset(p,1,sizeof p);
    rep(i,2,n+1){
        if(p[i]==0) continue;
        primes.pb(i);
        for(int j=2*i;j<=n;j+=i){
            p[j]=0;
        }
    }
}
vii ranges;
vi vals;
void pre(){
    process_seive(1000);
    int prod=1,last=0;
    rep(i,0,sz(primes)){
        if(prod<=hell/primes[i]) prod*=primes[i];
        else{
            vals.pb(prod);
            ranges.pb({last,i-1});
            prod=primes[i];
            last=i;
        }
        if(sz(vals)>=17){
            break;
        }
    }
}
int n=4194304,q;
int query(int x){
    assert(x<=hell);
    q++;
    cout<<"? "<<x<<endl;
    cin>>x;
    return x;
}
void solve(){
    q=0;
    vi ps;
    rep(i,0,sz(vals)){
        int x=query(vals[i]);
        rep(j,ranges[i].x,ranges[i].y+1){
            if(x%primes[j]==0){
                ps.pb(primes[j]);
            }
        }
    }
    int w=1,divs=1;
    rep(i,0,sz(ps)-1){
        int a=ps[i];
        int b=ps[i+1];
        int num=1;
        while(num<=1000000000/a) num*=a;
        while(num<=hell/b) num*=b;
        int x=query(num);
        int ca=0;
        while(x%a==0){
            x/=a;
            w*=a;
            ca++;
        }
        int cb=0;
        while(x%b==0){
            x/=b;
            w*=b;
            cb++;
        }
        divs*=(1+ca)*(1+cb);
        i++;
    }
    if(sz(ps)%2){
        int a=ps.back();
        int num=1;
        while(num<=1000000000/a) num*=a;
        int x=query(num);
        int ca=0;
        while(x%a==0){
            x/=a;
            w*=a;
            ca++;
        }
        divs*=(1+ca);
    }
    assert(sz(ps)<=9);
    assert(q<=22);
    if(w<=3) cout<<"! "<<4*divs<<endl;
    else cout<<"! "<<2*divs<<endl;
}
 
signed main(){
    pre();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}