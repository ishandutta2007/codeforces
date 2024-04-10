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
#define pb push_back

#define N 100005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
map<long long,vector<long long> >mp;
map<long long,vector<long long> >::iterator it;
int i,j,m,p,k;
long long n,G[N],f[20005],g[20005]; 
void ins(long long x)
{
	  if (x<=1) return; 
	  int i;
	  long long ret=1,now=x;
	  for (i=2;1ll*i*i<=now;++i)
	      if (now%i==0)
	      { 
	            while (now%i==0) now/=i;
	            if (now==1) ret=i; else ret=-1;
	            break;
	      }
	  if (ret==-1) return;
	  if (now>1) ret=now;
	  mp[ret].push_back(x+1);
}
int Find(long long x)
{
	  if (x>G[G[0]]) return -1;
	  int id=lower_bound(G+1,G+G[0]+1,x)-G;
	  if (G[id]==x) return id;
	  return -1;
}
int main()
{
	scanf("%I64d",&n); 
	for (i=1;1ll*i*i<=n;++i)
	  if (n%i==0)
	{
		  G[++G[0]]=i; ins(i-1);
		  if (1ll*i*i!=n) G[++G[0]]=n/i,ins(n/i-1);
	}
	sort(G+1,G+G[0]+1); f[1]=1;
	for (it=mp.begin();it!=mp.end();++it)
	{
		   vector<long long> x=it->se;
		   sort(x.begin(),x.end());
		     for (j=G[0];j;--j)
		       if (f[j])
		        for (i=0;i<(int)x.size();++i)
		        {
		        	    long long now=x[i];
		        	    int id=Find(G[j]*now);
						if (id!=-1) f[id]+=f[j];  
		        }
	}
	printf("%I64d\n",f[G[0]]);
}