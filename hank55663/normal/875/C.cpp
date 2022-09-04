#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
vector<int> v[100005];
vector<int> s[100005];
int indegree[100005];
int main(){
	MEM(indegree);
	int n,m;
	scanf("%d %d",&n,&m);
	int ok=1;
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			int a;
			scanf("%d",&a);
			s[i].pb(a);
		}
		if(i!=0)
		for(int j=0;j<s[i-1].size();j++){
			if(j>=s[i].size()){
				ok=0;
				break;
			}
			if(s[i-1][j]!=s[i][j]){
				v[s[i-1][j]].pb(s[i][j]);
			//	printf("%d %d",s[i-1][j],s[i][j]);
				indegree[s[i][j]]++;
				break;
			}
		} 
	}
	if(!ok){
		printf("No\n");
	}
	else{
		priority_queue<int,vector<int>,greater<int> > pq,pq1;
		for(int i=1;i<=m;i++){
			if(indegree[i]==0)
			pq.push(i);
		}
		vector<int> ans;
		ans.pb(0);
		while(!pq.empty()){
			int x=pq.top();
			pq.pop();
		//	printf("%d\n",x);
			if(x<ans.back()){
				pq1.push(x);
				continue;
			}
			else
			ans.pb(x);
			for(auto it=v[x].begin();it!=v[x].end();it++){
				if(--indegree[*it]==0){
					pq.push(*it);
				}
			}
		}
	//	printf("?");
		vector<int> ans2;
		ans2.pb(0);
		int ok=1;
		while(!pq1.empty()){
			int x=pq1.top();
			pq1.pop();
			if(x<ans2.back()){
				ok=0;
				break;
			}
			ans2.pb(x);
			for(auto it=v[x].begin();it!=v[x].end();it++){
				if(--indegree[*it]==0){
					pq1.push(*it);
				}
			}
		}
		if(ok&&ans.size()+ans2.size()==m+2){
			printf("Yes\n%d\n",ans.size()-1);
			for(int i=1;i<ans.size();i++)
			printf("%d ",ans[i]);
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}