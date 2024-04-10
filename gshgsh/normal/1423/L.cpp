#include<algorithm>
#include<iostream>
#include<random>
#include<bitset>
#include<vector>
#include<cstdio>
#include<unordered_map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,S,D;bitset<1000>a[MAXN];vector<pair<bitset<1000>,int>>v;unordered_map<bitset<1000>,int>mn;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),S=get(),D=get();For(i,0,S-1){int c=get();while(c--)a[i][get()-1]=1;}int B=max(S/2-2,0);
	For(i,0,(1<<B)-1){int cnt=__builtin_popcount(i);bitset<1000>x;For(j,0,B-1)if(i>>j&1)x^=a[j];if(!mn.count(x))mn[x]=cnt;else mn[x]=min(mn[x],cnt);}
	for(auto i:mn)v.push_back(i);mn.clear();
	For(i,0,(1<<S-B)-1){int cnt=__builtin_popcount(i);bitset<1000>x;For(j,0,S-B-1)if(i>>j&1)x^=a[j+B];if(!mn.count(x))mn[x]=cnt;else mn[x]=min(mn[x],cnt);}
	while(D--)
	{
		int k=get();bitset<1000>x;while(k--)x[get()-1]=1;int ans=S+1;
		for(auto i:v){auto y=i.first^x;if(mn.count(y))ans=min(ans,mn[y]+i.second);}cout<<(ans==S+1?-1:ans)<<'\n';
	}
}