#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001

int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	int N=get();vector<pair<int,int>>ans;
	if(N==1||N==2){cout<<"1\n1 1\n";return 0;}if(N==3){cout<<"2\n1 1\n1 2\n";return 0;}
	if(N==4){cout<<"3\n1 1\n1 2\n1 3\n";return 0;}
	int a=N%3;
	if(a==0){ans.push_back({1,1});ans.push_back({2,2});For(i,3,N/3+1)ans.push_back({i,i*2-2});}
	if(a==1){ans.push_back({1,1});ans.push_back({1,2});For(i,2,N/3)ans.push_back({i,i*2});}
	if(a==2)For(i,1,N/3+1)ans.push_back({i,i*2-1});
	a=(N-1)%3;
	if(a==0)For(i,N/3+1,N/3+N/3)ans.push_back({i,(i-N/3)*2-1});
	if(a==1)For(i,N/3+2,N/3+N/3+1)ans.push_back({i,(i-N/3-1)*2});
	if(a==2)For(i,N/3+2,N/3+N/3)ans.push_back({i,(i-N/3-1)*2+1});
	cout<<ans.size()<<'\n';for(auto i:ans)cout<<i.first<<' '<<i.second<<'\n';
}