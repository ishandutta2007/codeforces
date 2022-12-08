#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define x first
#define w second
using pii=pair<int,int>;
#define pb push_back
#define mp make_pair
int w[N],f[N],siz[N],rt,Min,Siz,P;
vector<pii>S[N];
double d[N],ans;
void getroot(int x,int fa) {
	siz[x]=1;
	int Max=0;
	for(pii y:S[x]) {
		if(y.x==fa||f[y.x])continue;
		getroot(y.x,x);
		siz[x]+=siz[y.x];
		Max=max(Max,siz[y.x]);
	}
	Max=max(Max,Siz-siz[x]);
	if(Max<Min) {
		Min=Max;
		rt=x;
	}
}
double get(int x,int fa,int sum) {
	double Sum=pow(sum,1.5)*w[x];
	for(pii y:S[x]) {
		if(y.x==fa)continue;
		Sum+=get(y.x,x,sum+y.w);
	}
	return Sum;
}
double calc(int x,int fa,int sum) {
	double Sum=pow(sum,0.5)*w[x];
	for(pii y:S[x]) {
		if(y.x==fa)continue;
		Sum+=calc(y.x,x,sum+y.w);
	}
	return Sum;
}
void solve(int x) {
	f[x]=1;
	double now=get(x,0,0),Sum=0;
	if(now<ans)ans=now,P=x;
	for(pii y:S[x]) {
		if(f[y.x])continue;
		Sum+=d[y.x]=calc(y.x,x,y.w);
	}
	for(pii y:S[x]) {
		if(f[y.x])continue;
		if(Sum-2*d[y.x]<0) {
			Siz=siz[y.x]<siz[x]?siz[y.x]:Siz-siz[x];
			rt=0,Min=1e9;
			getroot(y.x,0);
			solve(rt);
			break;
		}
	}
}
int main() {
	int n,a,b,c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",w+i);
	for(int i=1;i<n;i++) {
		scanf("%d%d%d",&a,&b,&c);
		S[a].pb(mp(b,c));
		S[b].pb(mp(a,c));
	}
	ans=1e20;
	rt=0,Min=1e9;
	Siz=n;
	getroot(1,0);
	solve(rt);
	printf("%d %.10lf\n",P,ans);
	return 0;
}