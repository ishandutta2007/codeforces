#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
#define FAIL return puts("Human"),void();
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=300005,B=200;typedef std::pair<int,int> pi;
int pos[N],c[N];std::vector<int> a[N];std::vector<pi> b[N];
void MAIN(){
	int n,q;read(n,q);
	for(int i=1,k;i<=q;++i){read(k);a[i].resize(k);for(auto &it:a[i])read(it);}
	std::sort(a+1,a+q+1,[&](const std::vector<int> &a,const std::vector<int> &b){return a.size()>b.size();});
	for(int i=1;i<=n;++i)b[i].clear();
	for(int i=1;i<=q;++i){
		if(SZ(a[i])<=B)for(int j=0;j<SZ(a[i]);++j)for(int k=j+1;k<SZ(a[i]);++k)b[a[i][k]].pb({a[i][j],a[i][j+1]});
		else{
			memset(pos,-1,(n+3)<<2);
			for(int j=0;j<SZ(a[i]);++j)pos[a[i][j]]=j;
			for(int j=i+1;j<=q;++j){
				int mx=-1;
				for(int k=SZ(a[j])-1;k>=0;--k)if(pos[a[j][k]]!=-1){
					if(pos[a[j][k]]<mx){
						if(a[j][k+1]!=a[i][pos[a[j][k]]+1])FAIL;
					}
					else mx=pos[a[j][k]];
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(auto [x,y]:b[i])c[x]=0;
		for(auto [x,y]:b[i]){
			if(c[x]&&c[x]!=y)FAIL;
			c[x]=y;
		}
	}
	puts("Robot");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}