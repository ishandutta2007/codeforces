#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=1e6+200;
const int M=1000000007;
bool f[5005][5005];
ll t[5005],x[5005],r1[5005],r2[5005];
int n;
void Max(ll &x,ll y){
    if (x==-1||x<y) x=y;
}
ll dis(ll x,ll l,ll r){
    if (x<l) return l-x;
    if (x>r) return x-r;
    return 0;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld%lld",&t[i],&x[i]);
    memset(r1,-1,sizeof(r1));
    memset(r2,-1,sizeof(r2));
    f[0][0]=1;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<=n;j++) f[i][0]|=f[i][j];
        if (abs(x[i]-x[i+1])<=t[i+1]-t[i]){
            for (int j=i+2;j<=n;j++) f[i+1][j]|=f[i][j];
        }
        for (int j=i+2;j<=n;j++){
            if (abs(x[i]-x[j])+abs(x[j]-x[i+1])<=t[i+1]-t[i]) f[i+1][j]|=f[i][0];
        }
        if (f[i][i+1]) Max(r2[i+1],t[i+1]-t[i]);
        if (f[i][0]&&abs(x[i]-x[i+1])<=t[i+1]-t[i]) Max(r1[i+1],t[i+1]-t[i]-abs(x[i]-x[i+1]));
        if (r1[i]!=-1){
            ll L=x[i]-r1[i],R=x[i]+r1[i];
            if (dis(x[i+1],L,R)<=t[i+1]-t[i]){
                Max(r1[i+1],t[i+1]-t[i]-dis(x[i+1],L,R));
                f[i+1][0]=1;
            }
            for (int j=i+2;j<=n;j++){
                if (dis(x[j],L,R)+abs(x[j]-x[i+1])<=t[i+1]-t[i]) f[i+1][j]=1;
            }
        }
        if (r2[i]!=-1){
            ll L=x[i-1]-r2[i],R=x[i-1]+r2[i];
            if (dis(x[i+1],L,R)<=t[i+1]-t[i]){
                Max(r1[i+1],t[i+1]-t[i]-dis(x[i+1],L,R));
                f[i+1][0]=1;
            }
            for (int j=i+2;j<=n;j++){
                if (dis(x[j],L,R)+abs(x[j]-x[i+1])<=t[i+1]-t[i]) f[i+1][j]=1;
            }
        }
    }
    for (int j=1;j<=n;j++) f[n][0]|=f[n][j];
    if (f[n][0]||r1[n]!=-1||r2[n]!=-1) puts("YES"); else puts("NO");
    return 0;
}