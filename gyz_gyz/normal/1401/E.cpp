#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int M=1e6+2;
const int inf=1e9;
const int mo=1e9+7;
struct pr{
	int t,x,y;
	friend bool operator<(const pr&a,const pr&b){
		return a.t<b.t;
	}
}p[N],t[N];
int a[M+1];
void f(int x,int y){
	for(;x<=M;x+=x&-x)a[x]+=y;
}
int q(int x){int y=0;
	for(;x;x-=x&-x)y+=a[x];return y;
}
int main(){int n,m;ll ans=1;
	scanf("%d%d",&n,&m);
	rep(i,1,n){int x,l,r;
		scanf("%d%d%d",&x,&l,&r);
		p[i*2-1]={l,x+1,1};
		p[i*2]={r+1,x+1,-1};
		if(!l&&r==M-2)++ans;
	}
	rep(i,1,m)scanf("%d%d%d",&t[i].t,&t[i].x,&t[i].y);
	sort(p+1,p+n*2+1);
	sort(t+1,t+m+1);
	f(1,1);f(M-1,1);int x=1;
	rep(i,1,m){
		for(;x<=n*2&&p[x].t<=t[i].t;++x)f(p[x].x,p[x].y);
		ans+=q(t[i].y+1)-q(t[i].x)-1;
	}
	printf("%lld\n",ans);
}