#include<iostream>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,M,cnt[MAXN],ans[MAXN];vector<int>id[MAXN],pos[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,1,N)cnt[i]=0,pos[i].clear();For(i,1,M)ans[i]=0,id[i].clear();
		For(i,1,M){int K;cin>>K;while(K--){int x;cin>>x;id[i].push_back(x);}ans[i]=id[i][0];cnt[id[i][0]]++;pos[id[i][0]].push_back(i);}
		int x=0;For(i,1,N)if(cnt[i]>(M+1)/2){x=i;break;}if(!x){cout<<"YES\n";For(i,1,M)cout<<ans[i]<<' ';cout<<endl;continue;}
		for(auto i:pos[x]){if(id[i].size()>1)cnt[x]--,cnt[id[i][1]]++,ans[i]=id[i][1];if(cnt[x]<=(M+1)/2)break;}
		if(cnt[x]>(M+1)/2)cout<<"NO\n";else{cout<<"YES\n";For(i,1,M)cout<<ans[i]<<' ';cout<<endl;}
	}
	return 0;
}