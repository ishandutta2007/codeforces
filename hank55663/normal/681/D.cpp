#include<bits/stdc++.h>
using namespace std;
#define N 505
vector<int> v[100005];
vector<int> ans;
int a[100005];
int ok=1;
int visit[100005];
void dfs(int n,int d){
	int vv=d;
	if(!visit[a[n]])
	ans.push_back(a[n]),visit[a[n]]=1,vv=a[n];
	else{
		if(a[n]!=d)
		ok=0;
	}
		visit[n]=1;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++) {
		dfs(*it,vv);
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	bool root[100005];
	for(int i=1;i<=n;i++)
	root[i]=true;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		root[b]=false;
	}
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)	
	if(root[i])
	dfs(i,0);
	if(!ok){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",ans.size());
	for(vector<int>::iterator it=ans.end();it!=ans.begin();){
		it--;
		printf("%d\n",*it);
	}

}