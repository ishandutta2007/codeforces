#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int mo=1e9+7;
int n,h[N],dr[N],st[N],v[N];vector<int>p[N];
void dfs(int x){
	for(auto i:p[x])if(!h[i]){
		h[i]=h[x]+1;dfs(i);
	}
}
void ck(int x){
	rep(i,1,n)h[i]=dr[i]=0;
	h[x]=1;dfs(x);
	rep(i,1,n){
		if(dr[h[i]]&&dr[h[i]]!=int(p[i].size()))return;
		dr[h[i]]=p[i].size();
	}
	printf("%d\n",x);exit(0);
}
int main(){
	scanf("%d",&n);vector<int>d;
	if(n==1)return printf("1\n"),0;
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	rep(i,1,n)if(p[i].size()==1){
		d.push_back(i);v[i]=1;st[i]=i;
	}
	while(!d.empty()){
		vector<int>ds;
		if(d.size()==1){
			ck(d[0]);return printf("-1\n"),0;
		}
		int dg=0,ls=0;
		for(auto i:d){
			if(dg&&dg!=int(p[i].size())){
				ck(ls);ck(st[i]);return printf("-1\n"),0;
			}else{
				dg=p[i].size();ls=st[i];
			}
		}
		for(auto i:d){
			int vs=0,vt=0;
			for(auto j:p[i])if(!v[j])vs=j,++vt;
			else if(v[j]==v[i]){
				ck(st[i]);ck(st[j]);return printf("-1\n"),0;
			}
			if(vt>1){
				ck(st[i]);return printf("-1\n"),0;
			}
			if(vt){
				ds.pb(vs);v[vs]=v[i]+1;st[vs]=st[i];
			}
		}d=ds;
	}printf("-1\n");
}