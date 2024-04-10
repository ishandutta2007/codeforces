#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map> 
#include<cassert>
#include<vector>
using namespace std;
#define N 1234
typedef long long ll;
const ll mx=2e8;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}

int n,tot,g[N],dis[N][N],T;
int d[N][N];
const int p[30]={0,2,3,5,7,11,13,17,23,27,29,31,37,41,43,47,53,57};
vector<int> a[N],em;
map<vector<int>,int> mp;
map<int,int> qwq;
void dfs(vector<int> &vec,int u,ll x){
	a[++tot]=vec;
	mp[vec]=tot;
	int lim=vec.empty()?233333:vec.back();
	for(int i=1;i<=lim;++i){
		x*=p[u];
		if(x>mx)break;
		vector<int> tmp=vec;
		tmp.push_back(i);
		dfs(tmp,u+1,x);
	}
}
inline vector<int> Get(int x){
	vector<int> vec;
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			int c=0;
			while(x%i==0)++c,x/=i;
			vec.push_back(c);
		}
	}
	if(x>1)vec.push_back(1);
	sort(vec.begin(),vec.end(),greater<int>());
//	for(auto x:vec){
//		cerr<<" "<<x;
//	}
//	cerr<<endl;
//	cerr<<" g: "<<g[mp[vec]]<<endl;
	assert(mp.count(vec));
	
	return vec;
}
int z,id[N];
int main(){
	dfs(em,1,1);
	for(int i=1;i<=tot;++i){
		int o=1;
		for(auto x:a[i])o*=x+1;
		g[i]=o;
		if(!qwq.count(g[i]))qwq[g[i]]=++z;
		id[i]=qwq[g[i]];
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=tot;++i){
		dis[i][i]=0;
	}
	for(int u=1;u<=tot;++u){
		for(int i=0;i<(int)a[u].size();++i){
			vector<int> b=a[u];
			--b[i];
			sort(b.begin(),b.end(),greater<int>());
			if(b.back()==0)b.pop_back();
			assert(mp.count(b));
			int v=mp[b];
//			for(auto x:a[t]){
//				cerr<<" "<<x;
//			}
//			cerr<<endl;
//			for(auto x:b)
//				cerr<<" "<<x;
//			cerr<<endl<<u<<" .. "<<v<<endl;
//			cerr<<endl<<endl;
			if(dis[u][v]!=0)dis[u][v]=dis[v][u]=1;
		}
	}
	for(int k=1;k<=tot;++k){
		for(int i=1;i<=tot;++i){
			for(int j=1;j<=tot;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=tot;++i){
		for(int j=1;j<=tot;++j){
			d[i][id[j]]=min(d[i][id[j]],dis[i][j]);
		}
	}
	T=read();
	while(T--){
		int A=read(),B=read();
		vector<int> vA=Get(A);
		vector<int> vB=Get(B);
		int u=mp[vA],v=mp[vB];
		int ans=0x3f3f3f3f;
		for(int i=1;i<=z;++i){
			ans=min(ans,d[u][i]+d[v][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}