#include<iostream>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int N,M,s[2];map<int,int>E[MAXN];
int main()
{
	cin>>N>>M;
	For(i,1,M)
	{
		char opt;cin>>opt;if(opt=='+'){int u,v;char c;cin>>u>>v>>c;if(E[v][u])s[1]++,s[0]+=E[v][u]==c;E[u][v]=c;}
		else if(opt=='-'){int u,v;cin>>u>>v;if(E[v][u])s[1]--,s[0]-=E[v][u]==E[u][v];E[u][v]=0;}else{int x;cin>>x;cout<<(s[x&1]?"YES\n":"NO\n");}
	}
	return 0;
}