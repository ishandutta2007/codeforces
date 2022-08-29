#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[200002],pos[200002],X[200002],Y[200002],tot;
inline void rev(re int l,re int r){
	reverse(a+l,a+r+1);X[++tot]=r;
	for(re int i=l;i<=r;++i)pos[a[i]]=i;
}
int main(){
	int t=read();
	while(t--){
		n=read(),tot=0;
		re bool ia=1;
		for(re int i=1;i<=n;++i)pos[a[i]=read()]=i;
		for(re int i=1;i<=n;i+=2)if(!(pos[i]&1)){ia=0;break;}
		if(!ia){
			puts("-1");
			continue;
		}
		for(re int i=n;i>1;i-=2){
			rev(1,pos[i]),rev(1,pos[i-1]-1);
			rev(1,pos[i-1]+1),rev(1,3);
			rev(1,i);
		}
		printf("%d\n",tot);
		for(re int i=1;i<=tot;++i)printf("%d ",X[i]);
		puts("");
		
	}
}