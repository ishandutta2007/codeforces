#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
#define N 500010
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000001ll
using namespace std;
typedef long long ll;
typedef pair<char,char>pii;
inline pii gp(const int &x,const int &y){
	if(x<y)return {x,y};else return {y,x};
}
struct pr{
	vector<pii>a;int s=inf;
	void clear(){
		s=0;a.clear();
	}
	pr operator +(const pii &x){
		pr a=*this;a.a.pb(x);++a.s;return a;
	}
	pr operator +(const pr &b){
		pr a=*this;a.s+=b.s;
		for(auto i:b.a)a.a.pb(i);
		return a;
	}
	bool pd(const pii &x){
		for(auto i:a)if(i==x)return 1;return 0;
	}
}a[1<<14][14][14],b[1<<14];
vector<int>p[14];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	int nn=(1<<n)-1;
	rep(i,0,n-1){
		a[1<<i][i][i].clear();
		b[1<<i].clear();
	}
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		p[x-1].pb(y-1);p[y-1].pb(x-1);
	}
	rep(i,0,nn)rep(j,0,n-1)rep(k,0,n-1)if(a[i][j][k].s<=m){
		for(auto r:p[j]){
			int x=i|(1<<r);
			if(a[i][j][k].s+1<a[x][r][k].s&&!a[i][j][k].pd(gp(j,r)))a[x][r][k]=a[i][j][k]+gp(j,r);
		}
		for(auto r:p[k]){
			int x=i|(1<<r);
			if(a[i][j][k].s+1<a[x][j][r].s&&!a[i][j][k].pd(gp(k,r)))a[x][j][r]=a[i][j][k]+gp(k,r);
		}
	}
	dep(i,nn,0)rep(r,0,n-1){int ii;
		if((i>>r)&1)ii=i-(1<<r);else continue;
		rep(j,0,n-1)rep(k,0,n-1)
			if(a[i][j][k].s<a[ii][j][k].s)a[ii][j][k]=a[i][j][k];
	}
	rep(i,0,nn)if(b[i].s<=m){
		int m=pct(nn^i),mm=(1<<m)-1;
		rep(jj,0,mm){
			int oo=0,j=0;
			rep(o,0,n-1)if(!((i>>o)&1)&&((jj>>(oo++))&1))j+=1<<o;
			rep(k1,0,n-1)if((i>>k1)&1)rep(k2,0,n-1)if((i>>k2)&1)
				if(b[i].s+a[j][k1][k2].s<b[i|j].s)b[i|j]=b[i]+a[j][k1][k2];
		} 
	}	
	printf("%d\n",b[nn].s);
	for(auto i:b[nn].a)printf("%d %d\n",i.fr+1,i.sc+1);
}