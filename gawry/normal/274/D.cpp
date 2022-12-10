#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int n,m;
vector<int> t[100001],q;
typedef pair<int,int> p2;
set<p2> next[100001];
bool seen[100001];
void dfs(int col){
	if(seen[col])return;
	seen[col]=true;
	for(int row=0;row<n;row++)if(t[row][col]>-1)while(1){
		set<p2>::iterator it=next[row].lower_bound(p2(t[row][col]+1,-1));
		if(it==next[row].end())break;
		int col2=it->second;
		next[row].erase(it);
		dfs(col2);
	}
	q.push_back(col);
}
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		t[i].resize(m);
		for(int j=0;j<m;j++)scanf("%d",&t[i][j]);
		for(int j=0;j<m;j++)if(t[i][j]!=-1){
			next[i].insert(p2(t[i][j],j));
		}
	}
	for(int i=0;i<m;i++)if(!seen[i]){
		dfs(i);
	}
	reverse(q.begin(),q.end());
	for(int i=0;i<n;i++){
		int prev=-2;
		for(int j=0;j<q.size();j++)if(t[i][q[j]]>-1){
			int cur=t[i][q[j]];
			if(cur<prev){
				puts("-1");
				return 0;
			}
			prev=cur;
		}
	}
	for(int i=0;i<q.size();i++)printf("%d ",q[i]+1);puts("");
}