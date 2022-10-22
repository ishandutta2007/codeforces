#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 301
int T,N,K,cnt[2][3];char mp[MAXN][MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;K=0;For(i,0,1)For(j,0,2)cnt[i][j]=0;For(i,1,N)For(j,1,N)cin>>mp[i][j],cnt[0][(i+j)%3]+=mp[i][j]=='X',cnt[1][(i+j)%3]+=mp[i][j]=='O',K+=mp[i][j]=='X'||mp[i][j]=='O';
		For(x,0,2){bool flag=0;For(y,0,2)if(x!=y&&(cnt[0][x]+cnt[1][y])*3<=K){For(i,1,N)For(j,1,N)if((mp[i][j]=='X'&&(i+j)%3==x)||(mp[i][j]=='O'&&(i+j)%3==y))mp[i][j]='X'+'O'-mp[i][j];flag=1;break;}if(flag)break;}For(i,1,N){For(j,1,N)cout<<mp[i][j];cout<<endl;}
	}
	return 0;
}