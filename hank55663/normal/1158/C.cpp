#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
using namespace std;
vector<int> v[500005];
int cnt;
int ans[500005];
void dfs(int x){
	ans[x]=cnt;
	cnt--;
	for(auto it:v[x])
		dfs(it);
}
int main(){
	int t;
	scanf("%d",&t);
	int p[500005];
	while(t--){
		int n;
		scanf("%d",&n);
		cnt=n+1;
		vector<int> temp;
		temp.pb(n+1);
		for(int i = 1;i<=n;i++){
			scanf("%d",&p[i]);
			v[i].clear();
		}
		v[n+1].clear();
		int ok=1;
		for(int i =1;i<=n;i++){
			while(temp.back()==i)temp.pop_back();
			if(p[i]==-1)
			p[i]=temp.back();
			if(p[i]>temp.back()){
				printf("-1\n");
				ok=0;
				break;
			}
			v[p[i]].pb(i);
			temp.pb(p[i]);
		}
		if(ok){
			dfs(n+1);
			for(int i = 1;i<=n;i++)
				printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}
/*
n = x*m+x=x*(m+1);



*/