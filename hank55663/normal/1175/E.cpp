#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int L[500005];
vector<int> v[500005];
bool cmp(const pii &p,const pii &q){
	if(p.y!=q.y)return p.y<q.y;
	else return p.x>q.x;
}
int p[500005][20];
void dfs(int x,int f){
	p[x][0]=f;
	for(auto it:v[x]){
		if(it!=f){
			dfs(it,x);
		}
	}
}
int query(int l,int r){
	int res=0;
	if(L[p[r][19]]>l)return -1;
	if(L[r]<=l)return 1;
	for(int i = 19;i>=0;i--){
		int tar=p[r][i];
		if(L[tar]>l){
			r=tar;
			res+=(1<<i);
		}
	}
	return res+2;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	vector<pii> vv;
	for(int i=0;i<n;i++){
		int l,r;
		//l++,r++;
		scanf("%d %d",&l,&r);
		vv.pb(mp(l,r));
	}
	sort(vv.begin(),vv.end(),cmp);
	vector<pii> stk;
	for(auto it:vv){
		while(!stk.empty()&&stk.back().x>=it.x){
			stk.pop_back();
		}
		stk.pb(it);
	}
	vector<int> vis;
	vector<int> root;
	for(auto it:stk){
		L[it.y]=it.x;
		auto x=lower_bound(vis.begin(),vis.end(),it.x);
		if(x==vis.end())root.pb(it.y);
		else v[*x].pb(it.y);
		vis.pb(it.y);
	}
	for(auto it:root)
	dfs(it,it);
	for(int i = 1;i<20;i++){
		for(int j=1;j<=500000;j++){
			p[j][i]=p[p[j][i-1]][i-1];
		}
	}
	for(int i =0;i<m;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		auto it=lower_bound(vis.begin(),vis.end(),r);
		if(it==vis.end()){
			printf("-1\n");
			continue;
		}
		r=*it;
		printf("%d\n",query(l,r));
	}
}