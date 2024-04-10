#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[100002],t;
char s[100002];
int main(){
	n=read();
	scanf("%s",s+1);
	for(re int i=1;i<=n;++i)++a[s[i]];
	printf("%d",min(a['L'],a['R'])*2+2*min(a['U'],a['D']));
}