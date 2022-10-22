#include<bits/stdc++.h>
#define F fflush(stdout)
using namespace std;
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
vector<int> G[1005];
int n,cnt,maxn,a[10005];
void dfs(int now,int pre)
{
	a[++cnt]=now;
	for(auto st:G[now])	if(st!=pre)	dfs(st,now),a[++cnt]=now;
}
int quest(int l,int r)
{
	set<int> S;
	for(int i=l;i<=r;++i)	S.insert(a[i]);
	printf("? %d",int(S.size()));
	for(auto st:S)	printf(" %d",st);
	puts(""),F;
	return read();
}
bool check(int l,int r){return quest(l,r)==maxn;}
int main(){
	n=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	int l=1,r=cnt;
	maxn=quest(1,cnt);
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(check(l,mid))	r=mid;
		else	l=mid;
	}
	printf("! %d %d\n",a[l],a[r]),F;
	return 0;
}