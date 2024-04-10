#include<iostream>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1501
int N,K,a[MAXN][MAXN],v[MAXN],fa[MAXN];
int sol(vector<int>b)
{
	if(b.size()==1)return b[0];
	int mx=0;int N=b.size();For(i,0,N-1)For(j,0,N-1)mx=max(mx,a[b[i]][b[j]]);int rt=++K;v[rt]=mx;
	vector<vector<int> >s;For(i,0,N-1){int j=-1;if(!s.empty())For(k,0,(int)s.size()-1)if(a[b[i]][s[k][0]]!=v[rt]){j=k;break;}if(j==-1)j=s.size(),s.push_back({});s[j].push_back(b[i]);}
	For(i,0,s.size()-1)fa[sol(s[i])]=rt;return rt;
}
int main()
{
	cin>>N,K=N;For(i,1,N)For(j,1,N)cin>>a[i][j];For(i,1,N)v[i]=a[i][i];vector<int>a(N);For(i,0,N-1)a[i]=i+1;
	sol(a);cout<<K<<endl;For(i,1,K)cout<<v[i]<<(i==K?'\n':' ');cout<<N+1<<endl;For(i,1,K)if(i!=N+1)cout<<i<<' '<<fa[i]<<endl;return 0;
}