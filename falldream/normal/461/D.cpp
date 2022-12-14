#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#define MN 200005
#define pa pair<int,int> 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,s[MN+5],tot,ans=1;
inline int getfa(int x){return s[x]?s[x]=getfa(s[x]):x;}
void Merge(int x,int y)
{
//	cout<<"Merge"<<x<<" "<<y<<endl;
	if(getfa(x)!=getfa(y))	
		s[getfa(x)]=getfa(y),--tot;
}

int main()
{
	n=read();m=read();tot=n<<1;
	for(int i=1;i<=m;++i)
	{
		int x,y;char c;	
		x=read();y=read();cin>>c;
		if(x>n>>1) x=n+1-x,y=n+1-y;		
		if(y>n+1-x) {int z=n+1-x;x-=y-(n+1-x);y=z;} 		
		if(y<x) swap(x,y);
		int l=(y-(x-1)),r=y+(x-1)+2;
		Merge(l*2,r*2+(c=='o')),Merge(l*2+1,r*2+(c=='x'));
	}
	for(int i=1;i<=n+2;++i) if(getfa(i*2)==getfa(i*2+1)) return 0*puts("0"); 
	for(int i=1;i<=tot/2;++i) ans=2*ans%1000000007;
	printf("%d\n",ans);
	return 0;
}