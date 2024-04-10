#include<bits/stdc++.h>
using namespace std;
#define N 100005
vector<pair<int,long long int> > v[N];
int ans=0;
long long int a[N];
void dfs(int n,int f,long long int step){
	ans++;
	for(vector<pair<int,long long int> >::iterator it=v[n].begin();it!=v[n].end();it++ ){
		if(it->first!=f){
			if(step+it->second<=a[it->first])
			dfs(it->first,n,max(step+it->second,0ll));
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%I64d",&a[i]);
	for(int i=2;i<=n;i++){
		int p;
		long long int c;
		scanf("%d %I64d",&p,&c);
		v[i].push_back(make_pair(p,c));
		v[p].push_back(make_pair(i,c));
	}
	dfs(1,0,0);
	printf("%d\n",n-ans);
}