#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define Pair pair<int,int>
#define mp make_pair
#define F first
#define S second
#define MAXN 100001
int N,a[MAXN],cnt,ans[MAXN*2][2];queue<Pair>q[3];
int main()
{
	cin>>N;For(i,1,N)cin>>a[i];int M=N;
	FOR(i,N,1)if(a[i])
	{
		if(a[i]==1)q[0].push(mp(M,i)),ans[++cnt][0]=M--,ans[cnt][1]=i;
		else if(a[i]==2){if(q[0].empty()){cout<<-1<<endl;return 0;}int x=q[0].front().F;q[0].pop();q[1].push(mp(x,i)),ans[++cnt][0]=x,ans[cnt][1]=i;}
		else
		{
			if(q[0].empty()&&q[1].empty()&&q[2].empty()){cout<<-1<<endl;return 0;}
			FOR(j,2,0)if(!q[j].empty()){int x=q[j].front().S;q[j].pop();q[2].push(mp(M,i));ans[++cnt][0]=M,ans[cnt][1]=i,ans[++cnt][0]=M--,ans[cnt][1]=x;break;}
		}
	}
	cout<<cnt<<endl;For(i,1,cnt)cout<<ans[i][0]<<' '<<ans[i][1]<<endl;return 0;
}