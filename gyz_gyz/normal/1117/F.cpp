#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define fr first
#define sc second
#define ctz __builtin_ctz
#define N 100010
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
int n,m,ans,tt[17],ls[17],p[17][17],a[1<<17];set<pii>se;
char s[N];bool r[17][17][1<<17],v[1<<17];
int main(){
	scanf("%d%d%s",&n,&m,s+1);int nn=(1<<m)-1;
	rep(i,0,m-1)rep(j,0,m-1)scanf("%d",&p[i][j]);
	dep(i,n,1){
		int x=0,c=s[i]-'a';++tt[c];
		for(pii j:se){
			if(!p[c][j.sc])r[max(c,j.sc)][min(c,j.sc)][x]=1;
			if(j.sc!=c)x|=1<<j.sc;
		}
		if(ls[c])se.erase({ls[c],c});
		ls[c]=i;se.insert({i,c});
	}
	rep(i,0,m-1)rep(j,0,i){int m1=1<<i,m2=1<<j;
		rep(k,0,nn)if(r[i][j][k]){
			for(int d=(~k)&nn,t=d&(-d);t;d^=t,t=d&(-d))
				if(t!=m1&&t!=m2)r[i][j][k|t]=1;
			v[k]=1;
		}
	}
	rep(i,1,nn)a[i]=-n;
	rep(i,0,nn)if(!v[i]){
		ans=max(ans,a[i]);
		for(int d=(~i)&nn,t=d&(-d);t;d^=t,t=d&(-d))
			if(!v[i|t])a[i|t]=max(a[i|t],a[i]+tt[ctz(t)]);
	}
	printf("%d\n",n-ans);
}