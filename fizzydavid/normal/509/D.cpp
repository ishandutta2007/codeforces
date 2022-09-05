//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,m;
ll a[111],mod,g[111][111],mx;
void failed()
{
    cout<<"NO"<<endl;
    exit(0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){cin>>g[i][j];mx=max(mx,g[i][j]);}
    for(int i=2;i<=n;i++)
    {
        int add=0,sub=0;
        a[i]=-1;
        for(int j=1;j<=m;j++)
        {
            if(g[i][j]>g[1][j])
            {
                if(add>0&&g[i][j]-g[1][j]!=add)failed();
                add=g[i][j]-g[1][j];
            }
            else if(g[i][j]<g[1][j])
            {
                if(sub>0&&g[1][j]-g[i][j]!=sub)failed();
                sub=g[1][j]-g[i][j];
            }
        }
        for(int j=1;j<=m;j++)if(g[i][j]==g[1][j]&&(add>0||sub>0))failed();
        if(mod>0&&add>0&&sub>0&&add+sub!=mod)failed();
        if(add>0&&sub>0)mod=add+sub;
        if(mod>0&&mod<=mx)failed();
        if(add==0)a[i]=-sub;else a[i]=add;
    }
    if(mod==0)mod=mx+1;
    cout<<"YES"<<endl;
    cout<<mod<<endl;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<0)a[i]+=mod;
        cout<<a[i]<<" ";
    }cout<<endl;
    for(int i=1;i<=m;i++)cout<<g[1][i]<<" ";cout<<endl;
    return 0;
}