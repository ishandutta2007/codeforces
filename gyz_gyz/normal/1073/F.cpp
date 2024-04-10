#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 300000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int n,f[N];vector<int>p[N];
struct pr{int x,y,a[4];}a[N][5],ans;
pr operator +(pr a,pr b){pr r;
	r.x=a.x+b.x;r.y=a.y+b.y;int t=0;
	rep(i,0,3)r.a[i]=0;
	rep(i,0,3)if(a.a[i])r.a[t++]=a.a[i];else break;
	rep(i,0,3)if(b.a[i])r.a[t++]=b.a[i];else break;return r;
}
bool operator <(pr x,pr y){
	if(x.x==y.x)return x.y<y.y;return x.x<y.x;
}
pr ex(pr x,int y){pr r=x;
	r.x+=max(y-1,0);r.y+=y;return r;
}
void dp(int x){
	rep(i,1,4)a[x][i]={-inf,-inf,{0,0,0,0}};
	if(p[x].size()==1)a[x][1]={0,0,{x,0,0,0}};
	for(auto i:p[x])if(i!=f[x]){
		f[i]=x;dp(i);
		dep(j,3,1)rep(k,1,4-j)
			a[x][j+k]=max(a[x][j+k],a[x][j]+ex(a[i][k],min(k,4-k)));
		rep(j,1,4)a[x][j]=max(a[x][j],ex(a[i][j],min(j,4-j)));
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}dp(1);
	rep(i,1,n)ans=max(ans,a[i][4]);
	printf("%d %d\n%d %d\n",ans.a[0],ans.a[2],ans.a[1],ans.a[3]);
}