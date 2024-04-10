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
#define fi first
#define se second
#define mk make_pair

#define N 100005
#define M 20
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,len,pow[N],lenx[N],start[N],hash[N],Hash[N],ans[5],Ans[5],an,ST[M][N],Log[N*2],id[M][N];
char c[N];
void build()
{
	  int i,j;
	  for (i=1;i<=len;++i) ST[0][i]=lenx[i],id[0][i]=i;
	  for (j=1;j<M;++j)
	    for (i=1;i<=len;++i)
	      if (i+(1<<j)-1<=len)
	    {
	    	  ST[j][i]=max(ST[j-1][i],ST[j-1][i+(1<<(j-1))]);
	    	  id[j][i]=(lenx[id[j-1][i]]>lenx[id[j-1][i+(1<<(j-1))]]?id[j-1][i]:id[j-1][i+(1<<(j-1))]);
	    }
}
pair<int,int> ask(int x,int y)
{
	  pair<int,int> e;
	  int i=Log[y-x+1];
	  e.fi=max(ST[i][x],ST[i][y-(1<<i)+1]);
	  e.se=(lenx[id[i][x]]>lenx[id[i][y-(1<<i)+1]]?id[i][x]:id[i][y-(1<<i)+1]);
	  return e;
}
int gethash(int x,int y)
{
	  return (hash[y]-1ll*hash[x-1]*pow[y-x+1]%Mo+Mo)%Mo;
}
int getHash(int x,int y)
{
	  return (Hash[x]-1ll*Hash[y+1]*pow[y-x+1]%Mo+Mo)%Mo;
}
int main()
{
	  pow[0]=1; for (i=1;i<N;++i) pow[i]=1ll*pow[i-1]*seed%Mo;
	  for (i=1,j=0;i<N;++j,i<<=1) Log[i]=j;
	  for (i=1;i<N;++i) if (!Log[i]) Log[i]=Log[i-1];
	  scanf("%s",c); len=strlen(c); for (i=len;i;--i) c[i]=c[i-1];
	  for (i=1;i<=len;++i) hash[i]=(1ll*hash[i-1]*seed+c[i])%Mo;
	  for (i=len;i;--i) Hash[i]=(1ll*Hash[i+1]*seed+c[i])%Mo;
	  for (i=1;i<=len;++i)
	  {
	  	       int l=1,r=min(i,len-i+1)+1,mid=0;
	  	       while (mid!=(l+r)>>1)
	  	       {
	  	       	  mid=(l+r)>>1;
	  	       	  if (gethash(i-mid+1,i)==getHash(i,i+mid-1)) l=mid; else r=mid;
	  	       }
	  	       lenx[i]=l*2-1;
	  }
	  int l=1;
	  for (i=1;i<=len;++i)
	  {
	  	   while (l+i-1<=len-i&&gethash(l,l+i-1)!=getHash(len-i+1,len)) ++l;
	  	   if (l+i-1>len-i) break;
	  	   start[i]=l;
	  }
	  int lim=i-1; build();
	  for (i=0;i<=lim;++i)
	  {
	  	    int L=max(1,start[i]+i),R=len-i;
	  	    if (L>R) continue;
	  	    int l=1,r=len+1,mid=0,rec;
	  	    while ((l+r)>>1!=mid)
	  	    {
	  	    	  mid=(l+r)>>1;
	  	    	  if (L+mid-1<=R-mid+1)
	  	    	  {
	  	    	  	  pair<int,int> x=ask(L+mid-1,R-mid+1);
	  	    	  	  if (x.fi>=mid*2-1) l=mid,rec=x.se; else r=mid;
	  	    	  } else r=mid;
	  	    }
	  	   if (i*2+l*2-1>an)
	  	   {
	  	   	  an=i*2+l*2-1; k=0;
	  	   	  if (i) ans[++k]=start[i],Ans[k]=i;
	  	   	  ans[++k]=rec-l+1,Ans[k]=l*2-1;
	  	   	  if (i) ans[++k]=len-i+1,Ans[k]=i;
	  	   }
	  }
	  printf("%d\n",k);
	  for (i=1;i<=k;++i) printf("%d %d\n",ans[i],Ans[i]);
}