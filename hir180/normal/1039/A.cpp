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
int n;
ll t;
ll a[200005];
ll mx[200005];
ll ans[200005];
int pos[200005];
int rui0[200005];
int rui1[200005];
int ruim1[200005];
void init(){
    for(int i=1;i<=n;i++){
        rui0[i] = rui0[i-1]+(mx[i]>=a[i]+t);
        rui1[i] = rui1[i-1]+(mx[i+1]>=a[i]+t);
        ruim1[i] = ruim1[i-1]+(mx[i-1]>=a[i]+t);
    }
}
bool ok0(int l,int r){
    if(l > r) return true;
    return (rui0[r]-rui0[l-1]) == (r-l+1);
}
bool ok1(int l,int r){
    if(l > r) return true;
    return (rui1[r]-rui1[l-1]) == (r-l+1);
}
bool okm1(int l,int r){
    if(l > r) return true;
    return (ruim1[r]-ruim1[l-1]) == (r-l+1);
}
int main(){
    scanf("%d%lld",&n,&t);
    repn(i,n){
        scanf("%lld",&a[i]);
    }
    repn(i,n) mx[i] = 3000000000000000000LL;
    repn(i,n){
        int mxpos;
        scanf("%d",&mxpos);
        pos[i] = mxpos;
        if(mxpos == n) continue;
        if(mxpos < i){
            mx[mxpos] = min(mx[mxpos],a[mxpos]+t-1);
        }
        else{
            mx[mxpos] = min(mx[mxpos],a[mxpos+1]+t-1);
        }
    }
    for(int i=n-1;i>=1;i--){
        mx[i] = min(mx[i],mx[i+1]-1);
    }
    init();
    repn(i,n){
        if(i<=pos[i]){
            bool pos1 = (mx[pos[i]] >= a[i]+t && ok0(1,i-1) && ok0(pos[i]+1,n) && okm1(i+1,pos[i]));
            bool pos2 = false;
            if(pos[i] != n) pos2 = (mx[pos[i]+1] >= a[i]+t && ok0(1,i-1) && ok0(pos[i]+2,n) && okm1(i+1,pos[i]+1));
            if(pos1 && !pos2);
            else{
                puts("No"); return 0;
            }
        }
        else{
            bool pos1 = (mx[pos[i]] >= a[i]+t && ok0(1,pos[i]-1) && ok0(i+1,n) && ok1(pos[i],i-1));
            bool pos2 = false;
            if(pos[i] != n) pos2 = (mx[pos[i]+1] >= a[i]+t && ok0(1,pos[i]) && ok0(i+1,n) && ok1(pos[i]+1,i-1));
            if(pos1 && !pos2);
            else{
                puts("No"); return 0;
            }
        }
    }
    puts("Yes");
    repn(i,n) printf("%lld ",mx[i]);
    puts("");
}