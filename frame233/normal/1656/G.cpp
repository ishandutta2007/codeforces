#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int a[N],b[N],fa[N];int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
std::vector<int> vec[N];
void MAIN(){
	int n;read(n);for(int i=1;i<=n;++i)vec[i].clear();
	for(int i=1;i<=n;++i)read(a[i]),vec[a[i]].pb(i);
	int p=1,q=n,cnt=0;
	for(int i=1;i<=n;++i){
		if(SZ(vec[i])%2){
			if(n%2==0||++cnt>1||(SZ(vec[i])==1&&vec[i][0]==n/2+1))return puts("NO"),void();
			b[n/2+1]=vec[i].back();vec[i].pop_back();
		}
		for(int j=0;j<SZ(vec[i]);j+=2)b[p++]=vec[i][j],b[q--]=vec[i][j+1];
	}
	std::iota(fa+1,fa+n+1,1);for(int i=1;i<=n;++i)fa[find(i)]=find(b[i]);
	for(int i=1;i<=n/2;++i)if(find(i)!=find(n-i+1))std::swap(b[i],b[n-i+1]),fa[find(i)]=find(n-i+1);
	for(int i=2;i<=n/2;++i)if(find(i)!=find(1))std::swap(b[i],b[1]),std::swap(b[n-i+1],b[n]),std::swap(b[i],b[n-i+1]),fa[find(i)]=find(1);
	if(b[n/2+1]==n/2+1)for(int i=1;i<=n;++i)if(i!=n/2+1&&a[b[i]]==a[n/2+1]){std::swap(b[i],b[n/2+1]);break;}
	puts("YES");for(int i=1;i<=n;++i)printf("%d%c",b[i]," \n"[i==n]);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}