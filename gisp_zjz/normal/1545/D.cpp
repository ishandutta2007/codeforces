#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1111;
const int M=998244353;
int n,k,p;
ll s[maxn],s2[maxn],a[maxn][maxn],vr,S,S2;
ll solve(ll x,ll y,ll z){
    return 3*z+x-3*y;
}
ll sqr(ll x){return x*x;}
int main(){
    scanf("%d%d",&n,&k); k--;
    for (int i=0;i<=k;i++){
        for (int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            s[i]+=a[i][j];
            s2[i]+=sqr(a[i][j]);
        }
    }
    vr=(s[k]-s[0])/k;
    for (int i=1;i<k;i++) if (s[i]!=s[0]+vr*i) {p=i;break;}
    assert(p);
    S=s[0]+vr*p;
    if (p>=3) S2=solve(s2[p-3],s2[p-2],s2[p-1]); else S2=solve(s2[p+3],s2[p+2],s2[p+1]);
    for (int i=1;i<=n;i++){
        ll tmp=s2[p];
        tmp-=sqr(a[p][i]);
        tmp+=sqr(a[p][i]+(S-s[p]));
        if (tmp==S2){
            printf("%d %lld\n",p,a[p][i]+(S-s[p]));
            break;
        }
    }
    fflush(stdout);
    return 0;
}