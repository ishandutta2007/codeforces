#include<bits/stdc++.h>
using namespace std;
#define N 600030
typedef long long ll;
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
int n,a[N],p[N];
struct Inter{
	int l,r;
	Inter(int _l=0,int _r=0){l=_l,r=_r;}
	friend Inter operator + (const Inter &a,const Inter &b){
		return Inter(min(a.l,b.l),max(a.r,b.r));
	}
};
int lg[N];
Inter g[N][20];
void init(){
	for(int i=2;i<=n;++i){
		lg[i]=lg[i>>1]+1;
	}
	for(int i=1;i<=n;++i){
		g[i][0]=Inter(p[i],p[i]);
	}
	for(int j=1;j<=19;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			g[i][j]=g[i][j-1]+g[i+(1<<j-1)][j-1];
		}
	}
}
inline Inter Query(int l,int r){
	int k=lg[r-l+1];
	return g[l][k]+g[r-(1<<k)+1][k];
}
int cnt,type[N];
ll ans;
struct node{
	Inter I,ran,fsup,sup;
	friend node operator + (const node &a,const node &b){
		return (node){a.I+b.I,a.ran+b.ran,a.fsup+b.fsup,a.fsup+b.sup};
	}
	inline bool check(){
		return I.r-I.l==ran.r-ran.l;
	}
}t[N],fnd[N];
vector<int> G[N];
int st[N],top,fail[N];
int Add(int u){
	int v=st[top];
	node tmp=t[v]+t[u];
	if(!top||tmp.sup.r>t[u].I.r){
		st[++top]=u;
		fnd[top]=t[u];
		fail[top]=top-1;
		return 0;
	}
	if(type[v]&&!G[v].empty()&&(t[G[v].back()]+t[u]).check()){
		t[v]=tmp,G[v].push_back(u);
		--top;
		return v;
	}
	if(tmp.check()){
		t[++cnt]=tmp;
		type[cnt]=true;
		G[cnt].push_back(v);
		G[cnt].push_back(u);
		--top;
		return cnt;
	}
	v=top;
	tmp=t[u];
	do{
		tmp=fnd[v]+tmp;
		v=fail[v];
	}while(tmp.sup.r<=t[u].I.r&&!tmp.check());
	if(tmp.check()){
		t[++cnt]=tmp;
		type[cnt]=0;
		for(int i=v+1;i<=top;++i){
			G[cnt].push_back(st[i]);
		}
		G[cnt].push_back(u);
		top=v;
		return cnt;
	}
	st[++top]=u;
	fail[top]=v;
	fnd[top]=tmp;
	return 0;	
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read(),y=read();
		a[x]=y;
		p[y]=x;
	}
	init();
	cnt=n;
	for(int i=1;i<=n;++i){
		t[i].I=Inter(i,i);
		t[i].ran=Inter(a[i],a[i]);
		t[i].fsup= i==n?Inter(i,i):Query(min(a[i],a[i+1]),max(a[i],a[i+1]));
		t[i].sup= Inter(i,i);
		type[i]=1;
	}
	for(int i=1;i<=n;++i)
		for(int u=i;u;u=Add(u));
		
	for(int i=1;i<=cnt;++i){
		if(type[i]&&i>n)ans+=1LL*G[i].size()*(G[i].size()-1)/2;
		else ++ans;
	}
	printf("%lld\n",ans);
	return 0;
}