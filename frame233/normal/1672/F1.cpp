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
int a[N],b[N];std::vector<int> vec[N],cyc[N];
void MAIN(){
	int n;read(n);for(int i=0;i<=n;++i)vec[i].clear(),cyc[i].clear();
	for(int i=1;i<=n;++i)read(a[i]),vec[a[i]].pb(i);
	for(int i=1;i<=n;++i)for(int j=0;j<SZ(vec[i]);++j)cyc[j].pb(vec[i][j]);
	for(int i=0;i<=n;++i)for(int j=0;j<SZ(cyc[i]);++j)b[cyc[i][j]]=cyc[i][j+1==SZ(cyc[i])?0:j+1];
	for(int i=1;i<=n;++i)printf("%d%c",a[b[i]]," \n"[i==n]);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}