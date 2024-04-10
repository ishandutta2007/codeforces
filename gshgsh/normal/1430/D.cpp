#include<iostream>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define mp make_pair
#define F first
#define S second
#define MAXN 200001
int T,N,b[MAXN];string a;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>a;a=" "+a;int M=0,cnt=1;For(i,2,N)a[i]!=a[i-1]?b[++M]=cnt,cnt=1:cnt++;b[++M]=cnt;queue<Pair>q;For(i,1,M)if(b[i]>1)q.push(mp(b[i],i));
		int ans=0;For(i,1,M){while(!q.empty()&&(q.front().S<i||q.front().F==1))q.pop();if(q.empty())ans++,M--;else q.front().F--,ans++;}cout<<ans<<endl;
	}
	return 0;
}