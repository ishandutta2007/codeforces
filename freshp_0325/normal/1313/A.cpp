#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
bool invit[8];
int ans;
int ope[9][5]={{0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1},{0,1,1,0},{0,1,0,1},{0,0,1,1},{0,1,1,1}};
void dfs(int a,int b,int c,int now)
{
	ans=max(ans,now);
	for(int i=1;i<=7;++i)
	{
		if(invit[i])	continue;
		a-=ope[i][1],b-=ope[i][2],c-=ope[i][3];
		invit[i]=true;
		if(a>=0 && b>=0 && c>=0)	dfs(a,b,c,now+1);
		a+=ope[i][1],b+=ope[i][2],c+=ope[i][3];
		invit[i]=false;
	}
}
int main(){
	int T;
	cin>>T;
	while(T-->0)
	{
		ans=0;
		int a,b,c;
		cin>>a>>b>>c;
		dfs(a,b,c,0);
		cout<<ans<<endl;
	}
	return 0;
}