#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,j,a[3][303030],p1[3][303030],p2[3][303030],has,b[3][303030],tam,p3[3][303030];
void jalan(ll aa,ll bb,ll cc,ll dd)
{
    has=max(has,cc);
    if(bb==n+1)
        return ;
    b[aa][bb]=1;
    ll tom=n-bb+dd+1;
  //  cout<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<" "<<tom<<" "<<has<<"\n";
   // cout<<aa<<" "<<bb<<" ";
    if(aa==1)
    {
        if(b[2][bb]==1)
        {
      //      cout<<cc+((p1[1][n]-p1[1][bb-1])*(dd-bb+1)+p2[1][n]-p2[1][bb-1])+((p1[2][n]-p1[2][bb])*tom+p3[2][n]-p3[2][bb])<<"\n";
      //      tom-()
            if(bb<n)
                has=max(has,cc+((p1[1][n]-p1[1][bb-1])*(dd-bb+1)+p2[1][n]-p2[1][bb-1])+((p1[2][n]-p1[2][bb])*tom+p3[2][n]-p3[2][bb]));
            jalan(1,bb+1,cc+a[1][bb]*dd,dd+1);
        }
        else
        {
      //      cout<<cc+((p1[1][n]-p1[1][bb-1])*(dd-bb+1)+p2[1][n]-p2[1][bb-1])+((p1[2][n]-p1[2][bb-1])*tom+p3[2][n]-p3[2][bb-1])<<"\n";
            if(bb<n)
                has=max(has,cc+((p1[1][n]-p1[1][bb-1])*(dd-bb+1)+p2[1][n]-p2[1][bb-1])+((p1[2][n]-p1[2][bb-1])*tom+p3[2][n]-p3[2][bb-1]));
            jalan(2,bb,cc+a[1][bb]*dd,dd+1);
        }
    }
    else
    {
        if(b[1][bb]==1)
        {
            //cout<<cc+((p1[2][n]-p1[2][bb-1])*(dd-bb+1)+p2[2][n]-p2[2][bb-1])+((p1[1][n]-p1[1][bb])*tom+p3[1][n]-p3[1][bb])<<"\n";
            if(bb<n)
                has=max(has,cc+((p1[2][n]-p1[2][bb-1])*(dd-bb+1)+p2[2][n]-p2[2][bb-1])+((p1[1][n]-p1[1][bb])*tom+p3[1][n]-p3[1][bb]));
            jalan(2,bb+1,cc+a[2][bb]*dd,dd+1);
        }
        else
        {
       //     cout<<cc+((p1[2][n]-p1[2][bb-1])*(dd-bb+1)+p2[2][n]-p2[2][bb-1])+((p1[1][n]-p1[1][bb-1])*tom+p3[1][n]-p3[1][bb-1])<<"\n";
          //  if(aa==2&&bb==2)
            //    cout<<(p1[2][n]-p1[2][bb-1])<<" "<<(cc-bb+1)<<" "<<p2[2][n]-p2[2][bb-1]<<" "<<(p1[1][n]-p1[1][bb-1])*tom<<" "<<p3[1][n]-p3[1][bb-1]<<"\n";
            if(bb<n)
                has=max(has,cc+((p1[2][n]-p1[2][bb-1])*(dd-bb+1)+p2[2][n]-p2[2][bb-1])+((p1[1][n]-p1[1][bb-1])*tom+p3[1][n]-p3[1][bb-1]));
            jalan(1,bb,cc+a[2][bb]*dd,dd+1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=2;i++)
        for(j=1;j<=n;j++)
            cin>>a[i][j];
    for(i=1;i<=2;i++)
        for(j=1;j<=n;j++)
            p1[i][j]=p1[i][j-1]+a[i][j];
    for(i=1;i<=2;i++)
        for(j=1;j<=n;j++)
            p2[i][j]=p2[i][j-1]+a[i][j]*(j-1);
    for(i=1;i<=2;i++)
        for(j=1;j<=n;j++)
            p3[i][j]=p3[i][j-1]+a[i][j]*(n-j);
    //cout<<p1[1][n]-p1[1][1]<<"\n";
    jalan(1,1,0,0);
    cout<<has<<"\n";
}