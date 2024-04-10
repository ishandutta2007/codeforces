#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll d[11][11][4][102][110],mi,n,m,i,j,a[11][11],dx[10][10],dy[10][10];
pair<ll,ll> sat;
ll depe(ll aa,ll bb,ll cc,ll dd,ll ee)
{
    if(aa<=0||bb<=0||aa>n||bb>n||ee<0)return 1e18;
    if(a[aa][bb]==(n*n)&&dd==(n*n))
    {
        if(ee==0)return 0;
        else return 1e18;
    }
    if(d[aa][bb][cc][dd][ee]==-1)
    {
        ll ii,K;
        if(cc==0)K=8;
        else K=4;
        d[aa][bb][cc][dd][ee]=1e18;
        for(ii=0;ii<K;ii++)d[aa][bb][cc][dd][ee]=min(d[aa][bb][cc][dd][ee],1+depe(aa+dx[cc][ii],bb+dy[cc][ii],cc,dd+(a[aa][bb]==dd),ee));
        if(K==4)
        {
            ll jj;
            for(jj=2;jj<=n;jj++)for(ii=0;ii<K;ii++)d[aa][bb][cc][dd][ee]=min(d[aa][bb][cc][dd][ee],1+depe(aa+jj*dx[cc][ii],bb+dy[cc][ii]*jj,cc,dd+(a[aa][bb]==dd),ee));
        }
        for(ii=0;ii<3;ii++)
            if(ii!=cc)
                d[aa][bb][cc][dd][ee]=min(d[aa][bb][cc][dd][ee],1+depe(aa,bb,ii,dd,ee-1));
     //   cout<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<" "<<ee<<" "<<d[aa][bb][cc][dd][ee]<<"\n";
    }
    return d[aa][bb][cc][dd][ee];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    dx[0][0]=1;dy[0][0]=2;
    dx[0][1]=1;dy[0][1]=-2;
    dx[0][2]=-1;dy[0][2]=2;
    dx[0][3]=-1;dy[0][3]=-2;
    dx[0][4]=2;dy[0][4]=1;
    dx[0][5]=2;dy[0][5]=-1;
    dx[0][6]=-2;dy[0][6]=1;
    dx[0][7]=-2;dy[0][7]=-1;

    dx[1][0]=1;dy[1][0]=0;
    dx[1][1]=-1;dy[1][1]=0;
    dx[1][2]=0;dy[1][2]=1;
    dx[1][3]=0;dy[1][3]=-1;

    dx[2][0]=-1;dy[2][0]=-1;
    dx[2][1]=-1;dy[2][1]=1;
    dx[2][2]=1;dy[2][2]=-1;
    dx[2][3]=1;dy[2][3]=1;

    memset(d,-1,sizeof(d));
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==1)
                sat=mp(i,j);
        }
    mi=1e18;
    //for(i=0;i<=(n*n);i++)
    for(i=0;i<=(n*n);i++)
    {
        mi=min(mi,depe(sat.fi,sat.se,0,1,i));
        mi=min(mi,depe(sat.fi,sat.se,1,1,i));
        mi=min(mi,depe(sat.fi,sat.se,2,1,i));
   //     cout<<depe(sat.fi,sat.se,0,1,i)<<"\n";
    }
    for(i=0;i<=(n*n);i++)
    {
        if(mi==depe(sat.fi,sat.se,0,1,i)||mi==depe(sat.fi,sat.se,1,1,i)||mi==depe(sat.fi,sat.se,2,1,i))
        {
            cout<<mi<<" "<<i<<"\n";
            return 0;
        }
    }
}