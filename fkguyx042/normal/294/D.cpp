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
int i,j,m,n,p,k,rest;
char We[3];
long long ans;
struct Node{int x,y,pos;}A;
map<pair<int,int>,int>mp[4],Mp;
int P(char *a)
{
	  if (a[0]=='U'&&a[1]=='L') return 0;
	  if (a[0]=='U'&&a[1]=='R') return 1;
	  if (a[0]=='D'&&a[1]=='L') return 2;
	  if (a[0]=='D'&&a[1]=='R') return 3;
}
Node get(Node A)
{
	if (A.pos==0)
	{
		 int w=min(A.x,A.y)-1;
		 ans+=w;
		 A.x-=w; A.y-=w;
		 if (A.x==1&&A.y==1) A.pos=3;
		 else if (A.x==1) A.pos=2;
		 else A.pos=1;
	}
	else if (A.pos==1)
    { 
         int w=min(A.x-1,m-A.y);
         ans+=w;
         A.x-=w; A.y+=w;
         if (A.x==1&&A.y==m) A.pos=2;
         else if (A.x==1) A.pos=3;
         else A.pos=0;
    }
    else if (A.pos==2)
    {
    	 int w=min(n-A.x,A.y-1);
    	 ans+=w;
    	 A.x+=w; A.y-=w;
    	 if (A.x==n&&A.y==1) A.pos=1;
    	 else if (A.x==n) A.pos=0;
    	 else A.pos=3;
    }
    else 
    {
    	  int w=min(n-A.x,m-A.y);
    	  ans+=w;
    	  A.x+=w; A.y+=w;
    	  if (A.x==n&&A.y==m) A.pos=0;
    	  else if (A.x==n) A.pos=1;
    	  else A.pos=2;
    }
    return A;
}
int main()
{
	  scanf("%d%d",&n,&m);
	  scanf("%d%d%s",&A.x,&A.y,We);
	  A.pos=P(We),rest=0; if (A.x==1||A.y==1||A.x==n||A.y==m) --rest,mp[A.pos][mk(A.x,A.y)]=1,Mp[mk(A.x,A.y)]=1; 
	  Node B=get(A); if (A.x==B.x&&A.y==B.y) A=B;
	  ans=1;
	  for (i=1;i<=m;++i)
	  {
	    if (((1+i)&1)==((A.x+A.y)&1)) ++rest;
		if (((n+i)&1)==((A.x+A.y)&1)) ++rest;
	  }
	  for (i=2;i<n;++i)
	  {
	    if (((1+i)&1)==((A.x+A.y)&1)) ++rest;
		if (((m+i)&1)==((A.x+A.y)&1)) ++rest;
	  }
	  for (;;)
	  {
	  	    A=get(A);
	        if(mp[A.pos][mk(A.x,A.y)]) { printf("-1\n"); return 0; }
            if (!Mp[mk(A.x,A.y)]) Mp[mk(A.x,A.y)]=1,--rest; mp[A.pos][mk(A.x,A.y)]=1;
            if (!rest) break;
      }
      cout<<ans<<endl;
}