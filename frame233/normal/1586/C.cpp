#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=1000005;
char pool[N<<3],*s[N],*P=pool;
int f[N],n,m;
inline int getid(int x,int y){return (x-1)*m+y;}
int main(){
	read(n,m);
	for(int i=0;i<=n+1;++i)s[i]=P,P+=m+2;
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i][j]=='X'&&s[i-1][j+1]=='X')++f[j+1];
		}
	}
	for(int i=1;i<=m;++i)f[i]+=f[i-1];
	int q;read(q);
	while(q--){
		int x1,x2;read(x1,x2);
		puts(f[x2]==f[x1]?"YES":"NO");
	}
	return 0;
}