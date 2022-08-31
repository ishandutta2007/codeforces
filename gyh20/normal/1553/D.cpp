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
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,ans,cnt,head[1000002],p[1002];
char a[100002],b[100002],f[1002][502];
inline void dfs(re int x){
	if(x==11){
		re int ans1=0,ans2=0,pp=0;
		for(re int i=1;i<=10;++i){
			if(i&1)ans1+=b[i];
			else ans2+=b[i];
			re int rm1=(10-i)/2,rm2=(10-i+1)/2;
			pp=i;
			if(ans1+rm1<ans2||ans2+rm2<ans1)break;
		}
		ans=min(ans,pp);
		return;
	}
	if(a[x]!='?')b[x]=a[x]-'0',dfs(x+1);
	else{
		b[x]=1,dfs(x+1);
		b[x]=0,dfs(x+1);
	}
}
signed main(){
	t=read();
	while(t--){
		ans=0;
		scanf("%s%s",a+1,b+1);
		n=strlen(a+1),m=strlen(b+1);
		re int v[2];memset(v,0,sizeof(v));v[(n&1)^1]=1;
		for(re int i=n;i;--i)
			if(a[i]==b[m]){
				if(v[i&1])continue;
				v[i&1]=1;
				re int pos=i;
				re int ia=1;
				for(re int j=m-1;j;--j){
					re int pp=pos-1;
					while(pp>=1&&a[pp]!=b[j])pp-=2;
					if(pp<=0){
						ia=0;
						break;
					}
					pos=pp;
				}
				if(ia)ans=1;
			}
		puts(ans?"YES":"NO");
	}
}