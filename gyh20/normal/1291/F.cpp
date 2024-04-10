#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,k,B;
char v[100002],s[12];
inline void Ins(re int x){
	for(re int i=(x-1)*B+1;i<=x*B;++i)
		if(!v[i]){
			printf("? %d\n",i),fflush(stdout);
			scanf("%s",s+1);
			if(s[1]=='Y')v[i]=1;
		}
}
int main(){
	n=read(),k=read(),B=max(1,k>>1);
	for(re int i=1;i<=n/B;++i){
		puts("R"),fflush(stdout);
		re int p1=i,p2=i;
		for(re int j=1;j<=n/B;++j){
			if(j&1)++p2;
			else --p1;
			if(p2>n/B)p2=1;
			if(!p1)p1=n/B;
			if(j&1)Ins(p1);
			else Ins(p2);
		}
	}
	re int ans=0;
	for(re int i=1;i<=n;++i)ans+=!v[i];
	printf("! %d",ans),fflush(stdout);
}