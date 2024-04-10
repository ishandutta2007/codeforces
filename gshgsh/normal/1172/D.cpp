#include<iostream>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define PPair pair<Pair,Pair>
#define F first
#define S second
#define MAXN 1001
int N,a[MAXN],b[MAXN],c[MAXN],d[MAXN];vector<PPair>ans;
int main()
{
	cin>>N;For(i,1,N)cin>>a[i],c[a[i]]=i;For(i,1,N)cin>>b[i],d[b[i]]=i;
	For(i,1,N-1)if(c[i]!=i||d[i]!=i)
	{
		if(c[i]==N||d[i]==N)ans.push_back({{c[i],i},{i,d[i]}}),c[a[c[i]]=a[i]]=c[i],d[b[d[i]]=b[i]]=d[i];
		else{ans.push_back({{c[i],i},{i,N}}),ans.push_back({{i,d[i]},{N,i}});int A=c[i],B=d[i];c[a[A]=a[N]]=A,d[b[B]=b[N]]=B,c[a[N]=a[i]]=N,d[b[N]=b[i]]=N;}
	}
	cout<<ans.size()<<endl;for(auto i:ans)cout<<i.F.F<<' '<<i.F.S<<' '<<i.S.F<<' '<<i.S.S<<endl;return 0;
}