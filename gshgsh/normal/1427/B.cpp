#include<iostream>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define mp make_pair
#define MAXN 100001
int T,N,K,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>K;int s=0;For(i,1,N){char c;cin>>c;a[i]=c=='W';s+=a[i];}priority_queue<Pair>q;if(!s){cout<<max(2*min(N,K)-1,0)<<endl;continue;}
		int l=1,r=N;while(!a[l])l++;while(!a[r])r--;int id=l;For(i,l,r)if(a[i])id=i;else{while(!a[i])i++;i--;q.push(mp(-(i-id),(i-id)*2+1));}int ans=0;For(i,1,N)if(a[i])ans+=a[i]+a[i-1];
		while(!q.empty()&&K){int l=-q.top().first,val=q.top().second;q.pop();if(K>=l)K-=l,ans+=val;else ans+=K*2,K=0;}ans+=2*min(N-r+l-1,K);cout<<ans<<endl;
	}
	return 0;
}