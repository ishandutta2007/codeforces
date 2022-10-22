#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 301
int T,N,cnt[3];char mp[MAXN][MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,0,2)cnt[i]=0;For(i,1,N)For(j,1,N)cin>>mp[i][j],cnt[(i+j)%3]+=mp[i][j]=='X';int id=0;For(i,1,2)if(cnt[i]<cnt[id])id=i;
		For(i,1,N)For(j,1,N)if((i+j)%3==id&&mp[i][j]=='X')mp[i][j]='O';For(i,1,N){For(j,1,N)cout<<mp[i][j];cout<<endl;}
	}
	return 0;
}