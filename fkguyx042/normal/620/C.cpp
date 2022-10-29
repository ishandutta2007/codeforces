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

#define N 300005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,x,ansx[N],ansy[N],ans;
map<int,int>mp;
int main()
{
	  scanf("%d",&n); int last=1;
	  for (i=1;i<=n;++i)
	  {
	  	  scanf("%d",&x);
	  	  if(!mp[x]) mp[x]=1;
	  	  else 
	  	  {
	  	  	   ansx[++ans]=last;
	  	  	   ansy[ans]=i;
	  	  	   last=i+1;
	  	  	   mp.clear();
	  	  }
	  }
	  if (last!=n+1&&ans==0) { printf("-1\n"); return 0; }
	  ansy[ans]=n;
	  printf("%d\n",ans);
	  for (i=1;i<=ans;++i) printf("%d %d\n",ansx[i],ansy[i]); 
}