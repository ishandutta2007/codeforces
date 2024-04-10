#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define abs(x) (x>0?x:-(x))
int T,N,M,x;
int sol(vector<int>a,vector<int>b)
{
	if(a.empty()||b.empty())return 0;int N=b.size();vector<int>sum(N+1);FOR(i,N-1,0)sum[i]=sum[i+1]+binary_search(a.begin(),a.end(),b[i]);
	int ans=0;For(i,0,N-1){int cnt=upper_bound(a.begin(),a.end(),b[i])-a.begin(),tot=upper_bound(b.begin(),b.end(),b[i]-cnt)-b.begin();ans=max(ans,i-tot+1+sum[i+1]);}return ans;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;vector<int>a[2],b[2];For(i,1,N)cin>>x,a[x>0].push_back(abs(x));For(i,1,M)cin>>x,b[x>0].push_back(abs(x));
		reverse(a[0].begin(),a[0].end());reverse(b[0].begin(),b[0].end());cout<<sol(a[0],b[0])+sol(a[1],b[1])<<endl;
	}
	return 0;
}