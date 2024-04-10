#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e5+2,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
int T,n,m,k,top,tot,d[N],sta[N],ans[N];
string p[N];
vector<int>e[N];
map<string,int>mp;
V input(){
	cin.tie(0),cin>>n>>m>>k;
	FOR(i,1,n)cin>>p[i],mp[p[i]]=i;
}
V add_edge(int x,int y){
//	cout<<x<<' '<<y<<'\n';
	e[x].push_back(y),d[y]++;
}
V init(){
	string st,tmp;int x,y,flag,u;
	while(m--){
		cin>>st>>x,flag=0;
		FOR(i,0,(1<<k)-1){
			tmp=st;
			FOR(j,0,3)if(i>>j&1)
				tmp[j]='_';
//			cout<<tmp<<'\n';
			if(y=mp[tmp]){
				if(x!=y)
					add_edge(x,y);
				else flag=1;
			}
		}
		if(!flag)return void(cout<<"NO");
	}
	FOR(i,1,n)if(!d[i])sta[++top]=i;
	FOR(i,1,n){
		if(!top)return void(cout<<"NO");
		u=sta[top--],ans[i]=u;
		for(int v:e[u])if(!--d[v])sta[++top]=v;
	}
	cout<<"YES\n";
	FOR(i,1,n)cout<<ans[i]<<' ';
}
V work(){
	
}
int main(){
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}