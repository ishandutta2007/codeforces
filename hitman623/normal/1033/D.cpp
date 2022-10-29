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
#define endl        '\n'
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
bool isPrime(int N){
    for(int i=2;i*i<=N;++i){
        if(N%i==0) return false;
    }
    return true;
}
int n;
mi mp,pq,vis;
int cbrt(int x){
    int lo=1,hi=min(2000000LL,x);
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(mid*mid*mid<x){
            lo=mid;
        }
        else hi=mid;
    }
    if(hi*hi*hi<=x) return hi;
    else return lo;
}
void solve(){
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        int SQRT=sqrt(x);
        if(SQRT*SQRT==x){
            if(isPrime(SQRT)){
                mp[SQRT]+=2;
                continue;
            }
            int fthroot=sqrt(SQRT);
            if(fthroot*fthroot==SQRT){
                if(isPrime(fthroot)){
                    mp[fthroot]+=4;
                }
            }
            continue;
        }
        int CBRT=cbrt(x);
        bool f=0;
        if(CBRT*CBRT*CBRT==x){
            if(isPrime(CBRT)){
                mp[CBRT]+=3;
                f=1;
                continue;
            }
        }
        if(f==0){
            pq[x]++;
        }
    }
    for(auto i:pq){
        for(auto j:pq){
            if(j.x!=i.x){
                int d=__gcd(i.x,j.x);
                if(d>1 and mp.count(d)==0){
                    mp[d]=0;
                }
            }
        }
    }
    mi f=mp;
    for(auto i:mp){
        for(auto j:pq){
            if(vis[j.x]) continue;
            if(j.x%i.x==0){
                f[i.x]+=j.y;
                f[j.x/i.x]+=j.y;
                vis[j.x]=1;
            }
        }
    }
    int ans=1;
    for(auto i:f){
        ans=ans*(i.y+1)%hell;
    }
    for(auto i:pq){
        if(!vis[i.x]) ans=ans*(i.y+1)*(i.y+1)%hell;
    }
    cout<<ans<<endl;
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