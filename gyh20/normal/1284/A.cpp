#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0'||v>'9')v=getchar();
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t;
}
char s[22][22],t[22][22];
int n,m,q,a;
int main(){
	n=read();
	m=read();
	for(re int i=1;i<=n;++i)scanf("%s",s[i]);
	for(re int i=1;i<=m;++i)scanf("%s",t[i]);
	q=read();
	while(q--){
		a=read();
		printf("%s%s\n",s[((a-1)%n)+1],t[((a-1)%m+1)]);
	}
}