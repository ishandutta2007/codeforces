#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
vector<long long> G;
long long T,a[100005];
int main(){
	cin>>T;
	while(T-->0)
	{
		long long n,k,ans=0,cnt=0;
		G.clear();
		cin>>n>>k;
		for(long long i=1;i<=n;++i)
		{
			cin>>a[i];
			if(a[i]>=k)
			{
				++ans;
				cnt+=a[i]-k;
			}
			else	G.push_back(a[i]);
		}
		sort(G.begin(),G.end());
		while(!G.empty())
		{
			long long now=G.size()-1;
			if(k-G[now]<=cnt)	++ans,cnt-=k-G[now],G.pop_back();
			else	break;
		}
		cout<<ans<<endl;
	}
	return 0;
}