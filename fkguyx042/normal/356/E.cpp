#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

#define N 100005
#define M 25
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,hash[N],sum[26][N],f[N],pow[N],two[M];
long long sol[M],ans[N],num[26][N],Ans[N];
char c[N],s,r[N];
int gethash(int x,int y,int z,int p)
{
	  int so=(hash[y]-1ll*hash[x-1]*pow[y-x+1]%Mo+Mo)%Mo;
	  if (x<=z&&z<=y) so=(so+1ll*(p-(int)r[z]+Mo)*pow[y-z]%Mo)%Mo;
	  return so;
}
int getmax(int x,int y)
{
	 int l=0,r=min(n-x+1,n-y+1)+1,mid=0;
	 while ((l+r)>>1!=mid)
	 {
	 	mid=(l+r)>>1;
	 	if (gethash(x,x+mid-1,0,0)==gethash(y,y+mid-1,0,0)) l=mid; else r=mid;
     }
     return l+1;
}
long long getans(int x,int y) { return sol[y]-sol[x]; }
void Find(int x,int y,char p)
{
	   int j;
	   char last=c[y];
	   c[y]=p;
	  for (j=f[x]+1;x+two[j+1]-2<=n;++j)
	          if (gethash(x,x+two[j]-2,y,(int)p)==gethash(x+two[j],x+two[j+1]-2,y,(int)p))
	          {
			      int g=sum[c[i+two[j]-1]-'a'][i+two[j+1]-2]-sum[c[i+two[j]-1]-'a'][i-1];
			      if (y>=i&&y<=i+two[j+1]-2)
			      {
			      	   if (p==c[i+two[j]-1]) g++;
			      	   if (last==c[i+two[j]-1]) g--;
			      }
			      if (g!=1) break;
			  }
			  else break;
	  c[y]=last;
	  num[p-'a'][y]+=getans(f[x],j-1);
}
long long sqr(int x) { 
return 1ll*x*x; }
void get(int x)
{
	 int j=f[x]+1; if (x==12) 
	    x=12;
	 if (x+two[j+1]-2>n) return;
	 if (gethash(x,x+two[j]-2,0,0)==gethash(x+two[j],x+two[j+1]-2,0,0))
	 {
	 	  for (s='a';s<'z';++s) Find(x,x+two[j]-1,s);
	 }
	 else 
	 {
	 	  int len=getmax(x,x+two[j]);
	 	  if (getmax(x+len,x+two[j]+len)+len>two[j]-1) 
	 	    Find(x,x+len-1,c[x+two[j]+len-1]),Find(x,x+two[j]+len-1,c[x+len-1]);
	 }
}
int main()
{
	  scanf("%s",c);
	  pow[0]=1; for (i=1;i<N;++i) pow[i]=1ll*pow[i-1]*seed%Mo;
	  two[0]=1; for (i=1;i<M;++i) two[i]=1ll*two[i-1]*2%Mo;
	  sol[0]=1; for (i=1;i<M;++i) sol[i]=sol[i-1]+sqr(two[i+1]-1);
	  n=strlen(c);
	  for (i=n;i;--i) c[i]=c[i-1];
	  for (i=1;i<=n;++i) r[i]=c[i];
	  for (i=1;i<=n;++i) hash[i]=(1ll*hash[i-1]*seed%Mo+c[i])%Mo;
	  for (i=1;i<=n;++i)
	     for (j=0;j<26;++j)
	       sum[j][i]+=sum[j][i-1]+(c[i]-'a'==j);
	  for (i=1;i<=n;++i)
	  {
	      for (j=1;i+two[j+1]-2<=n;++j)
	          if (gethash(i,i+two[j]-2,0,0)==gethash(i+two[j],i+two[j+1]-2,0,0)
			  &&sum[c[i+two[j]-1]-'a'][i+two[j+1]-2]-sum[c[i+two[j]-1]-'a'][i-1]==1)
		    	   j=j;
		    	else break;
		  f[i]=j-1;
	  }
      for (i=1;i<=n;++i) get(i);
	  long long An=0; 
      for (i=1;i<=n;++i) An+=sol[f[i]];
	  for (i=1;i<=n;++i) 
	     for (j=1;j<=f[i];++j) 
		 {
		    Ans[i]-=sqr(two[j+1]-1),Ans[i+two[j]-1]+=sqr(two[j+1]-1),Ans[i+two[j]]-=sqr(two[j+1]-1),Ans[i+two[j+1]-1]+=sqr(two[j+1]-1);
		    for (k=0;k<26;++k) if (sum[k][i+two[j+1]-2]-sum[k][i-1]>1) num[k][i+two[j]-1]-=sqr(two[j+1]-1);
	     }
	  for (i=1;i<=n;++i) Ans[i]+=Ans[i-1];
	  for (i=1;i<=n;++i) for (j=0;j<26;++j) ans[i]=max(ans[i],num[j][i]);
	  long long OP=An;
	  for (i=1;i<=n;++i) OP=max(OP,An+ans[i]+Ans[i]);
	  cout<<OP<<endl;
}