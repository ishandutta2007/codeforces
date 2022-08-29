#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[100002],b[100002];
char s[100002];
inline void mul(re int x){
	for(re int i=0;i<n;++i)b[(i+x)%n]=a[i];
	for(re int i=0;i<n;++i)a[i]-=b[i];
}
int main(){
	n=read(),scanf("%s",s),m=n;
	for(re int i=0;i<n;++i)a[i]=s[i]-'0';
	for(re int i=2;i<=n;++i)
		if(m%i==0){
			while(m%i==0)m/=i;
			mul(n/i);
		}
	for(re int i=0;i<n;++i)if(a[i])return puts("NO"),0;
	puts("YES");
}