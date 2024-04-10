#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=10005;
int a[N],ans[N],t;bool vis[N];
int ask(int i){
	printf("? %d\n",i),fflush(stdout);
	int x;read(x);return x;
}
void MAIN(){
	int n;read(n);memset(vis,0,n+3);
	for(int i=1;i<=n;++i)if(!vis[i]){
		std::vector<int> cyc;int o=t+1;
		while(true){
			int u=ask(i);if(vis[u])break;
			vis[u]=1,cyc.pb(u);
		}
		int len=SZ(cyc);
		for(int i=0;i<SZ(cyc);++i)ans[cyc[((i-o)%len+len)%len]]=cyc[i];
	}
	printf("! ");for(int i=1;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);
	fflush(stdout);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}