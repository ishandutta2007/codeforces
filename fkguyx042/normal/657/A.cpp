#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 100005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,d,h,tot;
int main()
{
       scanf("%d%d%d",&n,&d,&h);
	   if (2*h<d||(d==1&&h==1&&n!=2)) puts("-1");
	   else 
	   {
	         tot=2;
			 if (d==h)
			 {
			 	    for (i=1;i<=h;++i,++tot) printf("%d %d\n",tot-1,tot);
			 	    while (n-tot+1>0) printf("2 %d\n",tot++);
		     }
		     else 
		     {
	         for (i=1;i<=h;++i,++tot) printf("%d %d\n",tot-1,tot);
	         d=d-h;
	         while (n-tot+1>0)
	         {
	         	    int Next=min(n-tot+1,d);
	         	    printf("1 %d\n",tot); ++tot;
	         	    for (i=1;i<Next;++i,++tot) printf("%d %d\n",tot-1,tot);
	         }
	         }
	   }
}