//by yjz
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
int preh[511][511],prec[511][511],w,h,q;
char g[511][511];
int main()
{
    scanf("%d%d",&w,&h);
    for(int i=0;i<w;i++)scanf("%s",g[i]);
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            if(j+1<h)preh[i][j]=(g[i][j]=='.'&&g[i][j+1]=='.');
            if(i+1<w)prec[i][j]=(g[i][j]=='.'&&g[i+1][j]=='.');
            if(j>0)preh[i][j]+=preh[i][j-1];
            if(i>0)prec[i][j]+=prec[i-1][j];
        }
    }
    scanf("%d",&q);
    while(q--)
    {
        int xa,ya,xb,yb;
        scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
        xa--;ya--;xb--;yb--;
        int ans=0;
        for(int i=xa;i<=xb;i++)ans+=(yb>0?preh[i][yb-1]:0)-(ya>0?preh[i][ya-1]:0);
        for(int i=ya;i<=yb;i++)ans+=(xb>0?prec[xb-1][i]:0)-(xa>0?prec[xa-1][i]:0);
        printf("%d\n",ans);
    }
        
    return 0;
}