#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll n; int k; //ll pos;
int main(){
    srand((unsigned)time(NULL));
    scanf("%lld%d",&n,&k);
    ll L = 1,R = n;
    while(1){
        //pos += rand()%(2*k+1)-k;
        if(R-L <= 65){
            ll x = 1LL*rand()*rand();
            ll rng = (R-L+1);
            x = (x%rng+rng)%rng;
            cout<<L+x<<" "<<L+x<<endl;
            fflush(stdout);
            string ret;
            //if(L+x<=pos && pos<=L+x) ret = "Yes";
            //else ret = "No";
            cin>>ret;
            if(ret == "Yes"){
                return 0;
            }
            else if(ret == "No"){
                L = max(1LL,L-1LL*k);
                R = min(n,R+1LL*k);
                continue;
                
            }
        }
        cout<<L<<" "<<(L+R)/2<<endl;
        fflush(stdout);
        string ret;
        cin>>ret;
        //if(L<=pos && pos<=(L+R)/2) ret = "Yes";
        //else ret = "No";
        if(ret == "Yes"){
            R = (L+R)/2;
            L = max(1ll,L-1LL*k);
            R = min(n,R+1LL*k);
        }
        else if(ret == "No"){
            L = (L+R)/2;
            L = max(1ll,L-1LL*k);
            R = min(n,R+1LL*k);
        }
    }
}