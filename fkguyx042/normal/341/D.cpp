#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

#define N 1005
using namespace std;
long long tree[4][N][N],ans,v;
int i,j,m,n,p,k,type,x,y,x2,y2;
int get(int x,int y) { return (x&1)+(y&1)*2; }
int lowbit(int x) {   return x&-x; }
void change(int x,int y)
{
	   int wh=get(x,y),z;
	   for (;x<=n;x+=lowbit(x))
	     for (z=y;z<=n;z+=lowbit(z))
	       tree[wh][x][z]^=v;
}
long long ask(int x,int y)
{
	  int wh=get(x,y),z; long long sum=0;
	  for (;x;x-=lowbit(x))
	    for (z=y;z;z-=lowbit(z)) sum^=tree[wh][x][z];
	  return sum;
}
int main()
{
	 scanf("%d%d",&n,&m);
	 for (;m--;)
	{
		 scanf("%d%d%d%d%d",&type,&x,&y,&x2,&y2);
		 if (type==2)
		 {
		  cin>>v;
		 change(x,y); change(x2+1,y2+1);
		 change(x,y2+1); change(x2+1,y);
	     }
	     else 
	     {
	     	 ans=0;
	     	 ans^=ask(x2,y2); ans^=ask(x-1,y2);
	     	 ans^=ask(x2,y-1); ans^=ask(x-1,y-1);
	     	 cout<<ans<<endl;
	     }
	}
}