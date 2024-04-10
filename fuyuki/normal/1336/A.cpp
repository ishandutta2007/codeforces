#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1;
ll ans=0;
vector<int>e[N];
int n,k,a[N],dep[N],siz[N];
V add_edge(int x,int y){e[x].push_back(y),e[y].push_back(x);}
V dfs(int u,int fa=0){
	siz[u]=1,dep[u]=dep[fa]+1;
	for(int v:e[u])if(v!=fa)
		dfs(v,u),siz[u]+=siz[v];
}
int main(){
	n=getint(),k=getint();
	FOR(i,2,n)add_edge(getint(),getint());
	dfs(1);
	FOR(i,1,n)a[i]=dep[i]-siz[i];
	sort(a+1,a+1+n),reverse(a+1,a+1+n);
	FOR(i,1,k)ans+=a[i];
	cout<<ans;
	return 0;
}