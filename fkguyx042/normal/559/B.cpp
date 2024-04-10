#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
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
#define seed 133
#define Mo 998244353

using namespace std;
char c[M],s[M];
int i,j,m,n,p,k,Hash[M],hash[M],inv[M];
int get(int x,int y,int id)
{
	 if (id==0)  return 1ll*(Hash[x+y-1]-1ll*Hash[x-1]*inv[y]%Mo+Mo)%Mo;
	 else return 1ll*(hash[x+y-1]-1ll*hash[x-1]*inv[y]%Mo+Mo)%Mo;
}
bool check(int x,int y,int len)
{
	  if (get(x,len,0)==get(y,len,1)) return 1;
	  if (len&1) return 0;
	  if (get(x,len/2,0)==get(y,len/2,1)||get(x+len/2,len/2,0)==get(y+len/2,len/2,1)) return check(x+len/2,y+len/2,len/2)&&check(x,y,len/2);
	  if (get(x,len/2,0)==get(y+len/2,len/2,1)||get(x+len/2,len/2,0)==get(y,len/2,1)) return check(x+len/2,y,len/2)&&check(x,y+len/2,len/2);
	  return check(x,y+len/2,len/2)&&check(x+len/2,y,len/2)||check(x+len/2,y+len/2,len/2)&&check(x,y,len/2);
}
int power(int x,int y)
{
	  int sum=1;
	  for (;y;y>>=1)
	  {
	  	 if (y&1) sum=1ll*sum*x%Mo;
	  	 x=1ll*x*x%Mo;
	  }
	  return sum;
}
int main()
{
	 scanf("%s",c);
	 scanf("%s",s);
	 int len=strlen(c);
	 int nv=power(seed,Mo-2); inv[0]=1; for (i=1;i<=len;++i) inv[i]=1ll*inv[i-1]*seed%Mo;
	 for (i=len;i;--i) c[i]=c[i-1],s[i]=s[i-1];
	 for (i=1;i<=len;++i) Hash[i]=(1ll*Hash[i-1]*seed%Mo+c[i])%Mo,hash[i]=(1ll*hash[i-1]*seed%Mo+s[i])%Mo;
	 if (check(1,1,len)) printf("YES\n"); else printf("NO\n");
}