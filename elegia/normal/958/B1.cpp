#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 1005
#define MAXM 205
#define INF 0x7FFFFFFF
#define LL long long
#define NN 100
#define P 19260817
using namespace std;

int N;
vector<int> Adj[MAXN];


int main(){
	//ios::sync_with_stdio(0);
	//freopen("1.txt","r",stdin);
	
	cin>>N;
	int u,v;
	for(int i=1;i<=N-1;i++){
		cin>>u>>v;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
	int ans = 0;
	for(int i=1;i<=N;i++){
		if(Adj[i].size()==1) ans++;
	}
	cout<<ans;
	return 0;
}