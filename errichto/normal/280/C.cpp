#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#define pb push_back
#define ll long long
using namespace std;

const int st=100005;
int n,a,b,h[st];
vector<int> w[st];
double RES;

int DFS(int x)
{
	for(int i=0;i<w[x].size();++i)
		if(!h[w[x][i]]){
			h[w[x][i]]=h[x]+1;
			DFS(w[x][i]);
		}
	return 0;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;++i){
		scanf("%d%d",&a,&b);
		w[a].pb(b);
		w[b].pb(a);
	}
	h[1]=1;
	DFS(1);
	for(int i=1;i<=n;++i) RES+=1.0/((double)h[i]);
	printf("%lf",RES);
	return 0;
}