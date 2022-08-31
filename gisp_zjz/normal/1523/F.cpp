#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
const int M=998244353;
ll t[1<<14][105];
ll d[105][105],d2[105][14],d22[14][14];
ll mind[1<<14][105],mind2[1<<14][14];
ll xa[105],ya[105],xb[105],yb[105],T[105],ans;
struct node{
    ll x,y,t;
}A[205];
bool cmp(node u,node v){return u.t<v.t;}
void Min(ll &x,ll y){if (y<x)x=y;}
int n,m,f[1<<14][105];
const ll inf=1e14;
int main(){
    cin >> m >> n;
    for (int i=0;i<m;i++) cin >> xb[i] >> yb[i];
    for (int i=0;i<n;i++) cin >> A[i].x >> A[i].y >> A[i].t;
    sort(A,A+n,cmp);
    for (int i=0;i<n;i++) xa[i]=A[i].x,ya[i]=A[i].y,T[i]=A[i].t;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            d[i][j]=abs(xa[i]-xa[j])+abs(ya[i]-ya[j]);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            d2[i][j]=abs(xa[i]-xb[j])+abs(ya[i]-yb[j]);
    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++)
            d22[i][j]=abs(xb[i]-xb[j])+abs(yb[i]-yb[j]);
    for (int i=0;i<n;i++)
    for (int j=0;j<(1<<m);j++){
        mind[j][i]=inf;
        for (int k=0;k<m;k++) if ((j>>k)&1) Min(mind[j][i],d2[i][k]);
    }
    for (int i=0;i<m;i++)
    for (int j=0;j<(1<<m);j++){
        mind2[j][i]=inf;
        for (int k=0;k<m;k++) if ((j>>k)&1) Min(mind2[j][i],d22[i][k]);
    }
    memset(f,-1,sizeof(f));
    for (int i=0;i<n;i++) f[0][i]=1;
    for (int i=0;i<=n;i++)
        for (int j=0;j<(1<<m);j++)
            t[j][i]=inf;
    for (int i=0;i<m;i++) t[1<<i][0]=0;
    int ans=0;
    for (int mask=0;mask<(1<<m);mask++){
        for (int j=0;j<=n;j++) if (t[mask][j]<inf){
            for (int i=0;i<m;i++) if (!((mask>>i)&1)){
                Min(t[mask|1<<i][j],t[mask][j]+mind2[mask][i]);
            }
            for (int i=0;i<n;i++) if (t[mask][j]+mind[mask][i]<=T[i]){
                f[mask][i]=max(f[mask][i],j+1);
            }
        }
        for (int i=0;i<n;i++) if (f[mask][i]!=-1){
            int k=f[mask][i];
            ans=max(ans,k);
            for (int j=0;j<m;j++) if (!((mask>>j)&1)){
                Min(t[mask|1<<j][k],T[i]+min(d2[i][j],mind2[mask][j]));
            }
            for (int j=i+1;j<n;j++) if (min(d[i][j],mind[mask][j])+T[i]<=T[j]){
                f[mask][j]=max(f[mask][j],k+1);
            }
        }
    }
    cout << ans << endl;
}