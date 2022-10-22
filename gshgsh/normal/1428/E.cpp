#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define Thair pair<ll,Pair>
#define mp make_pair
#define F first
#define S second
#define INF 0x3fffffffffffffff
int N,K,a;ll ans;ll f(int a,int b){if(a<b)return INF;return 1ll*a%b*(a/b+1)*(a/b+1)+1ll*(b-a%b)*(a/b)*(a/b);}
int main()
{
	cin>>N>>K;priority_queue<Thair>q;For(i,1,N)cin>>a,ans+=f(a,1),q.push(mp(f(a,1)-f(a,2),mp(a,2)));
	while(N<K){ans-=q.top().F;int x=q.top().S.F,y=q.top().S.S;q.pop();q.push(mp(f(x,y)-f(x,y+1),mp(x,y+1)));N++;}cout<<ans<<endl;return 0;
}