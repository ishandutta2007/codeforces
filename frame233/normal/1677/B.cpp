#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1000005;
char s[N];int f[N],ans[N],res[N],pre[N];
void MAIN(){
	int n,m;read(n,m);scanf("%s",s);
	for(int i=0;i<n*m;++i)pre[i]=(i?pre[i-1]:0)+(s[i]=='1');
	memset(f,0,m<<2);
	int tot=0;
	for(int i=0;i<n*m;++i){
		if(s[i]=='1'){int to=i%m;tot+=f[to]==0,f[to]=1;}
		ans[i]=tot;
	}
	for(int i=0;i<n*m;++i){
		res[i]=pre[i]-(i-m>=0?pre[i-m]:0)>0;
		if(i>=m)res[i]+=res[i-m];
		printf("%d%c",ans[i]+res[i]," \n"[i+1==n*m]);
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}