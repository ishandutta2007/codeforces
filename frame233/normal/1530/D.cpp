#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int a[N],cnt[N],b[N];
bool vis[N],tag[N];
int main(){
	int _;read(_);
	while(_--){
		int n;read(n),memset(cnt,0,(n+3)<<2),memset(b,0,(n+3)<<2),memset(vis,0,n+3),memset(tag,0,n+3);
		for(int i=1;i<=n;++i)read(a[i]),++cnt[a[i]];
		for(int i=1;i<=n;++i)if(!cnt[i]){
			if(!vis[a[i]])vis[a[i]]=true,b[i]=a[i];
		}
		for(int i=1;i<=n;++i)if(!vis[a[i]])vis[a[i]]=true,b[i]=a[i];
		std::vector<int> all;
		for(int i=1;i<=n;++i)if(!b[i]&&!cnt[i])all.pb(i);
		for(int i=0;i+1<SZ(all);i+=2)b[all[i]]=all[i+1],b[all[i+1]]=all[i];
		for(int i=1;i<=n;++i)if(b[i])tag[b[i]]=true;
		std::vector<int> rest;
		for(int i=1;i<=n;++i)if(!tag[i])rest.pb(i);
		if(SZ(all)&1){
			if(rest.back()==all.back()){
				int tp=rest.back();rest.pop_back();
				b[all.back()]=rest.back();rest.pop_back();
				rest.pb(tp);
			}
			else b[all.back()]=rest.back(),rest.pop_back();
		}
		for(int i=1;i<=n;++i)if(!b[i])b[i]=rest.back(),rest.pop_back();
		int cnt=0;for(int i=1;i<=n;++i)cnt+=a[i]==b[i];
		printf("%d\n",cnt);for(int i=1;i<=n;++i)printf("%d%c",b[i]," \n"[i==n]);
	}
	return 0;
}