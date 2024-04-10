#include<iostream>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 51
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i];map<int,bool>vis;
		int cnt=0;For(i,1,N)For(j,i+1,N)!vis[a[j]-a[i]]?cnt++,vis[a[j]-a[i]]=1:0;cout<<cnt<<endl;
	}
	return 0;
}