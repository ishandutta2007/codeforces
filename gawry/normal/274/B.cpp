#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=100001;
vector<int> s[MAX];
int n,v[MAX];
long long best_plus[MAX],best_minus[MAX];
void dfs(int x,int y=0){
//printf("%d %d %d\n",x,cur_plus,cur_minus);
	for(int i=0;i<s[x].size();i++)if(s[x][i]!=y){
		dfs(s[x][i],x);
		int diff=v[x]-v[s[x][i]];
		long long tmp_plus=best_plus[s[x][i]],tmp_minus=best_minus[s[x][i]];
		if(diff>0)tmp_plus+=diff;else tmp_minus-=diff;
		best_plus[x]=max(best_plus[x],tmp_plus);
		best_minus[x]=max(best_minus[x],tmp_minus);
	}
}
main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		s[x].push_back(y);
		s[y].push_back(x);
	}
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	dfs(1);
	long long final=v[1]-best_plus[1]+best_minus[1];
//	cout<<best_plus[1]<<" "<<best_minus[1]<<" "<<final<<endl;
	cout<<best_plus[1]+best_minus[1]+abs(final)<<endl;
}