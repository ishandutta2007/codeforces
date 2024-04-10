#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define L long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,t[100010],w[100010],l[100010],r[100010];
long long ll=0,rr=100000000000000000ll;
struct point
{
    int x,y;
}a[100010];
inline bool cmp(point a,point b)
{
    return a.x<b.x;
}
inline bool pd(long long p)
{
    if((L)(a[n].x-a[1].x)*(a[n].x-a[1].x)<=p || (L)(w[n]-t[n])*(w[n]-t[n])<=p)
      return 1;
    int i,j,k,u,ly,ry,xx,yy;
    for(u=1;u<=2;u++)
      {
       for(k=1;k<=n && a[k].x<=0;k++);
       for(i=1;i<k && a[i].x*a[i].x>p;i++);
       //if(p==2500 && n==1000)
       //cout<<i<<" "<<k<<"\n";
       for(j=i;i<k;i++)
         {
          while(j<n && (L)(a[j+1].x-a[i].x)*(a[j+1].x-a[i].x)<=p && a[j+1].x<=-a[i].x)
            j++;
          while(j>=k && a[j].x>-a[i].x)
            j--;
          ly=min(t[i-1],l[j+1]);
          ry=max(w[i-1],r[j+1]);
          xx=max(abs(a[i].x),abs(a[j].x));
          yy=max(-ly,ry);
          //if(p==2500 && n==1000)
          //cout<<i<<" "<<j<<" "<<a[i].x<<" "<<a[j].x<<" "<<ly<<" "<<ry<<"\n";
          if((ly>ry || (L)(ry-ly)*(ry-ly)<=p) && (yy<0 || (L)xx*xx+(L)yy*yy<=p))
            break;
         }
       if(u==1 && i<k)
         return 1;
       for(j=1;j<=n;j++)
         a[j].x=-a[j].x;
       for(j=1;j+j<=n;j++)
         swap(a[j],a[n+1-j]);
       for(j=1;j<=n;j++)
         {
          swap(t[j],l[n+1-j]);
          swap(w[j],r[n+1-j]);
         }
       if(u==2 && i<k)
         return 1;
      }
    return 0;
}
int main()
{
	//freopen("game.in","r",stdin);
	//freopen("game.out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	t[0]=l[n+1]=200000000;
    w[0]=r[n+1]=-200000000;
	for(i=1;i<=n;i++)
	  {
	   t[i]=min(t[i-1],a[i].y);
	   w[i]=max(w[i-1],a[i].y);
      }
    for(i=n;i>0;i--)
      {
       l[i]=min(l[i+1],a[i].y);
       r[i]=max(r[i+1],a[i].y);
      }
	while(ll<rr)
	  if(pd(ll+rr>>1))
	    rr=(ll+rr>>1);
	  else
	    ll=(ll+rr>>1)+1;
	cout<<ll<<"\n";
	//if(ll==4356)
	//  cout<<pd(2500);
	//if(ll==9999217615303744ll)
	  //cout<<pd(ll)<<" "<<pd(ll-1)<<" "<<pd(9990603033983604ll)<<"\n";
	return 0;
}