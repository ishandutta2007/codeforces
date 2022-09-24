#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int from,to,value;
	Edge(){
		value=-1;
	}
}e[100005];
int d[100005];
vector<int> g[100005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>e[i].from>>e[i].to,++d[e[i].from],++d[e[i].to];
		g[e[i].from].push_back(i),g[e[i].to].push_back(i);
	}
	for(int i=1;i<=n;i++)if(d[i]>=3){
		for(int j=0;j<3;j++)e[g[i][j]].value=j;
		int tt=2;
		for(int j=1;j<=n;j++)if(-1==e[j].value)e[j].value=++tt;
		for(int j=1;j<n;j++)printf("%d\n",e[j].value);
		return 0;
	}
	for(int j=1;j<n;j++)printf("%d\n",j-1);
}