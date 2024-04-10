#include <bits/stdc++.h>
#define N 1005
#define MOD 998244353
using namespace std;
typedef long long ll;
int n,m,k,a[N][N],r,c;
ll dp[N][N],sumx,sumy,sumsx,sumsy,sumdp;
struct str{int v,x,y;};
str st[N*N];
ll mypow(ll a,ll b)
{
    if(!b) return 1;
    ll t=mypow(a,b/2);
    if(b%2) return t*t%MOD*a%MOD;
    return t*t%MOD;
}
ll inv(ll a){return mypow(a,MOD-2);}
bool sortf(str p1,str p2)
{
    if(p1.v==p2.v){
        if(p1.x==p2.x) return p1.y<p2.y;
        return p1.x<p2.x;
    }
    return p1.v<p2.v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            st[++k]={a[i][j],i,j};
        }
    sort(st+1,st+1+k,sortf);
    for(int i=1;i<=k;i++){
        int j=i;
        while(j+1<=k&&st[i].v==st[j+1].v)
            j++;
        for(int p=i;p<=j;p++){
            dp[st[p].x][st[p].y]=(((ll)i-1LL)*st[p].x%MOD*st[p].x%MOD-2LL*st[p].x%MOD*sumx%MOD+sumsx
            +((ll)i-1LL)*st[p].y%MOD*st[p].y%MOD-2LL*st[p].y%MOD*sumy%MOD+sumsy+sumdp+10LL*MOD)%MOD*inv((ll)i-1LL)%MOD;
        }
        for(int p=i;p<=j;p++){
            (sumx+=st[p].x)%=MOD;
            (sumsx+=st[p].x*st[p].x%MOD)%=MOD;
            (sumy+=st[p].y)%=MOD;
            (sumsy+=st[p].y*st[p].y%MOD)%=MOD;
            (sumdp+=dp[st[p].x][st[p].y])%=MOD;
        }
        i=j;
    }
    cin>>r>>c;
    cout<<dp[r][c];
    return 0;
}