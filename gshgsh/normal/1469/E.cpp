#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1000001
int T,N,K;string a;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>K>>a;int M=min(K,20);vector<bool>vis(1<<M);int con=0;For(i,0,N-M){if(con>=K-M){int now=0;For(j,i,i+M-1)now=now*2+(a[j]=='0');vis[now]=1;}a[i]=='1'?con++:con=0;}
		bool flag=0;For(i,0,(1<<M)-1)if(!vis[i]){cout<<"YES\n";For(j,1,K-M)cout<<0;For(j,1,M)cout<<((i>>M-j)&1);cout<<endl;flag=1;break;}if(!flag)cout<<"NO\n";
	}
	return 0;
}