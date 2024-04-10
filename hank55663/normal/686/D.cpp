#include<bits/stdc++.h>
using namespace std;
#define N 300005
vector<int> v[N]; 
int size[N];
int f[N]; 
int dfs(int n){
	int sum=1;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++)
	sum+=dfs(*it);
	return size[n]=sum;
}
stack<int> s;
int ans[N];
void dfs2(int n){
	s.push(n); 
	int Max=0;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++)
	Max=max(Max,size[*it]);
	if(Max<size[n]/2.0)
	{
		ans[n]=n;
		s.pop();
	}
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++)
		dfs2(*it);
	while(!s.empty()){
		int node=s.top();
		if(size[n]>=size[node]/2.0&&Max<size[node]/2.0)
		{
			ans[node]=n;
			s.pop();
		}
		else
		break;
	}
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	memset(size,0,sizeof(size));
	memset(ans,0,sizeof(ans));
	for(int i=2;i<=n;i++) 
	{
		scanf("%d",&f[i]);
		v[f[i]].push_back(i);
	}
	dfs(1);
	dfs2(1);
	while(q--){
		int ask;
		scanf("%d",&ask);
		printf("%d\n",ans[ask]);
	}
}