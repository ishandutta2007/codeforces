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
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002];
char s[52][52];
signed main(){
	t=read();
	while(t--){
		memset(s,0,sizeof(s));
		n=read(),m=read();
		for(re int i=1;i<=n;++i)scanf("%s",s[i]+1);
		int px=-1,py=-1;
		re bool ia=1;
		for(re int i=1;i<=n;++i){
			for(re int j=1;j<=m;++j){
				re int pos=(i&1)^(j&1);
				if(s[i][j]=='R'){
					if(px>=0&&px!=pos)ia=0;
					px=pos;
				}
				else if(s[i][j]=='W'){
					if(py>=0&&py!=pos)ia=0;
					py=pos;
				}
			}
		}
		if(px>=0&&py>=0&&px==py)ia=0;
		if(!ia)puts("NO");
		else{
			puts("YES");
			a[0]='R',a[1]='W';
			if(px==1||py==0)swap(a[0],a[1]);
			for(re int i=1;i<=n;++i){
				for(re int j=1;j<=m;++j){
					re int pos=(i&1)^(j&1);
					s[i][j]=a[pos];
			}
		}
			for(re int i=1;i<=n;++i)printf("%s\n",s[i]+1);
		}
	}
}