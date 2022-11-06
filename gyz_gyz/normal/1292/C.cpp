#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=3e3+10;
const int mo=998244353;
const int inf=1e9;
struct pr{int x,y;};
ll s[N],a[N][N],s1[N][N],s2[N][N];int n,f[N],f1[N][N],f2[N][N];
queue<pr>q;vector<int>p[N];bool v[N][N];
void dfs(int x){s[x]=1;
	for(auto&i:p[x])if(i!=f[x]){
		f[i]=x;dfs(i);s[x]+=s[i];
	}
}
void init(int x){
	for(auto&i:p[x])if(i!=f[x]){
		a[x][i]=a[i][x]=s[i]*(n-s[i]);
		v[x][i]=v[i][x]=1;
		f1[x][i]=f2[i][x]=i;
		f2[x][i]=f1[i][x]=x;
		s1[x][i]=s2[i][x]=n-s[i];
		s2[x][i]=s1[i][x]=s[i];
		q.push({x,i});q.push({i,x});
		init(i);
	}
}
int main(){ll ans=0;
	scanf("%d",&n);
	rep(i,2,n){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}
	dfs(1);init(1);
	while(!q.empty()){
		int x=q.front().x,y=q.front().y;q.pop();
		ans=max(ans,a[x][y]);
		for(auto&i:p[x])if(i!=f1[x][y]){
			f1[i][y]=x;s1[i][y]=(i==f[x]?n-s[x]:s[i]);
			f2[i][y]=f2[x][y];s2[i][y]=s2[x][y];
			a[i][y]=max(a[i][y],a[x][y]+s1[i][y]*s2[i][y]);
			if(!v[i][y]){
				v[i][y]=1;q.push({i,y});
			}
		}
		for(auto&i:p[y])if(i!=f2[x][y]&&i!=f[y]){
			f2[x][i]=y;s2[x][i]=(i==f[y]?n-s[y]:s[i]);
			f1[x][i]=f1[x][y];s1[x][i]=s1[x][y];
			a[x][i]=max(a[x][i],a[x][y]+s1[x][i]*s2[x][i]);
			if(!v[x][i]){
				v[x][i]=1;q.push({x,i});
			}
		}
	}
	printf("%lld\n",ans);
}