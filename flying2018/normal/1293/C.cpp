#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
bool mp[3][N];
int check(int x,int y)
{
	x=3-x;
	int ans=0;
	ans+=mp[x][y-1];
	ans+=mp[x][y];
	ans+=mp[x][y+1];
	return ans;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	int cnt=0;
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(mp[x][y]) mp[x][y]=false,cnt-=check(x,y);
		else mp[x][y]=true,cnt+=check(x,y);
		if(!cnt && !mp[1][1] && !mp[2][n]) puts("Yes");
		else puts("No");
	}
	return 0;
}