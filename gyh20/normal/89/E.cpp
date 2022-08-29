#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[1002],pos,ans,b[1002];
int main(){
	n=read(),ans=1e9;
	for(re int i=1;i<=n;++i)a[i]=read();while(!a[n])--n;
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<=n;++j)b[j]=max(0,a[j]-(j>=i));
		re int s1=0,s2=0;
		for(re int j=1;j<=n;++j)s1+=max(b[j]-b[j-1],0),s2+=b[j];
		if(s2*3+s1*2-i<ans)ans=s2*3+s1*2-i,pos=i;
	}
	for(re int i=pos;i<=n;++i)a[i]=max(a[i]-1,0);
	for(re int i=1;i<=n;++i){
		while(a[i]){
			re int pp=i;
			while(a[pp])--a[pp],++pp,printf("AR");
			printf("A");
			for(re int j=pp;j>i;--j)printf("L");
			printf("A");
		}
		printf("AR");
	}
	printf("A");
	for(re int j=n;j>=pos;--j)printf("L");
	printf("A");
}