#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int n,m,A,B,a[1000002],b[1000002],t,ans;
char s[1000002];
signed main(){
	t=read();
	while(t--){
		n=read(),m=read(),ans=0;
		map<int,int>V;
		for(re int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+n+1);
		for(re int i=1;i<=n;++i){
			if(V[a[i]]>0)--V[a[i]],--ans;
			else{
				++V[a[i]*m];
				++ans;
			}
		}
		printf("%d\n",ans);
	}
}