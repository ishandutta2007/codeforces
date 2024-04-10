#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
const int N=2005,mod=1000000007;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
char s[N],t[N];int f[N+N][2],g[N+N][2];
void MAIN(){
	int n;read(n);scanf("%s%s",s+1,t+1);
	for(int i=2;i<=n;i+=2){
		if(s[i]!='?')s[i]^=1;
		if(t[i]!='?')t[i]^=1;
	}
	memset(f,0,sizeof(f)),f[N][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=N-i;j<=N+i;++j)g[j][0]=g[j][1]=0;
		for(int a=0;a<2;++a)if(s[i]=='?'||s[i]==a+48){
			for(int b=0;b<2;++b)if(t[i]=='?'||t[i]==b+48){
				for(int j=N-i+1;j<=N+i-1;++j){
					add(g[j+a-b][0],f[j][0]);
					add(g[j+a-b][1],f[j][1]);
				}
			}
		}
		for(int j=N-i;j<=N+i;++j)f[j][0]=g[j][0],f[j][1]=g[j][1],add(f[j][1],1LL*f[j][0]*abs(j-N)%mod);
	}
	printf("%d\n",f[N][1]);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}