#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int n,m,ans,t,zt;
char a[1000002],b[1000002];
int main(){
	t=read();
	while(t--){
		n=read();
		scanf("%s%s",a+1,b+1);
		ans=0,zt=-1;
		for(re int i=1;i<=n;++i){
			if(a[i]!=b[i]){
				if(zt=='0')++ans;
				ans+=2,zt=-1;
			}
			else{
				if(a[i]!=zt){
					if(zt!=-1)ans+=2,zt=-1;
					else zt=a[i];
				}//zt=-1,ans+=2;
				else if(zt=='0')++ans;
			}
		}
		if(zt=='0')++ans;
		printf("%d\n",ans);
	}
}