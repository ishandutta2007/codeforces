#include<iostream>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define F first
#define S second
#define MAXN 100001
int T,N,M,x,a[MAXN],ans[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M>>x;For(i,1,N)cin>>a[i];priority_queue<Pair,vector<Pair>,greater<Pair> >q;For(i,1,M)q.push({0,i});
		For(i,1,N){Pair u=q.top();q.pop();u={u.F+a[i],u.S};ans[i]=u.S;q.push(u);}cout<<"YES\n";For(i,1,N)cout<<ans[i]<<' ';cout<<endl;
	}
	return 0;
}