#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,m,q,na,nb,a[100010],b[100010],v,p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,sx,sy,tx,ty;
	scanf("%d%d%d%d%d",&n,&m,&na,&nb,&v);
	for(i=1;i<=na;i++)
	  scanf("%d",&a[i]);
	for(i=1;i<=nb;i++)
	  scanf("%d",&b[i]);
	sort(a+1,a+na+1);
	sort(b+1,b+nb+1);
	scanf("%d",&q);
	while(q--)
	  {
       scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
       p=1e9;
       if(na)
         {
          i=lower_bound(a+1,a+na+1,sy)-a;
          if(i>0 && i<=na)
            p=min(p,abs(a[i]-sy)+abs(a[i]-ty)+abs(sx-tx));
          i--;
          if(i>0 && i<=na)
            p=min(p,abs(a[i]-sy)+abs(a[i]-ty)+abs(sx-tx));
         }
       if(nb)
         {
          i=lower_bound(b+1,b+nb+1,sy)-b;
          if(i>0 && i<=nb)
            p=min(p,abs(b[i]-sy)+abs(b[i]-ty)+(abs(sx-tx)-1)/v+1);
          i--;
          if(i>0 && i<=nb)
            p=min(p,abs(b[i]-sy)+abs(b[i]-ty)+(abs(sx-tx)-1)/v+1);
         }
       if(sx==tx)
         p=abs(ty-sy);
       printf("%d\n",p);
      }
	return 0;
}