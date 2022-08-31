#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define mp make_pair
#define xx first
#define yy second
using namespace std;
int n,m,x[2010],y[2010];
L s;
pi a[2010],b[4000010];
inline L cha(pi a,pi b)
{
    return (L)a.xx*b.yy-(L)a.yy*b.xx;
}
inline pi operator-(pi a,pi b)
{
    return mp(a.xx-b.xx,a.yy-b.yy);
}
inline bool cmp(pi i,pi j)
{
    return cha(a[i.yy]-a[i.xx],a[j.yy]-a[j.xx])>0;
}
inline void pri(int i,int j,int k)
{
    printf("Yes\n");
    printf("%d %d\n",a[i].xx,a[i].yy);
    printf("%d %d\n",a[j].xx,a[j].yy);
    printf("%d %d\n",a[k].xx,a[k].yy);
}
inline void ef(int l,int r,int i,int j,int k)
{
    int m;
    while(l<=r)
      {
       m=(l+r>>1);
       L p=abs(cha(a[i]-a[x[m]],a[j]-a[x[m]]));
       //cout<<x[m]<<" "<<i<<" "<<j<<" "<<p<<"!!!\n";
       if(p==s)
         {
          pri(x[m],i,j);
          exit(0);
         }
       if((p<s)^k)
         r=m-1;
       else
         l=m+1;
      }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%lld",&n,&s);
	s*=2;
	for(i=1;i<=n;i++)
	  scanf("%d%d",&a[i].xx,&a[i].yy);
	sort(a+1,a+n+1);
	for(i=1;i<n;i++)
	  for(j=i+1;j<=n;j++)
	    if(a[i].xx!=a[j].xx)
	      b[++m]=mp(i,j);
	sort(b+1,b+m+1,cmp);
	for(i=1;i<=n;i++)
	  x[i]=y[i]=i;
	for(k=1;k<=m;k++)
	  {
       i=b[k].xx;
       j=b[k].yy;
       if(y[j]!=y[i]+1)
         while(1);
       ef(1,y[i]-1,i,j,0);
       ef(y[i]+1,n,i,j,1);
       /*cout<<k<<"!!!\n";
       cout<<i<<" "<<j<<"\n";
       for(int l=1;l<=n;l++)
         cout<<x[l]<<" ";
         cout<<"\n";
       for(int l=1;l<=n;l++)
         cout<<y[l]<<" ";
         cout<<"\n";*/
       swap(x[y[i]],x[y[j]]);
       swap(y[i],y[j]);
      }
    for(i=1;i<n;i++)
      if(a[i].xx==a[i+1].xx)
        {
         j=i+1;
       if(y[j]!=y[i]+1)
         while(1);
       ef(1,y[i]-1,i,j,0);
       ef(y[i]+1,n,i,j,1);
        }
    printf("No\n");
	return 0;
}