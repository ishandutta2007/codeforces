#include<bits/stdc++.h>
using namespace std;
char s[65][65];
int n,m,A,P;
inline int h(int i,char c='A') {
	for(int j=1;j<=m;j++)
		if(s[i][j]!=c)return 0;
	return 1;
}
inline int l(int j,int c='A') {
	for(int i=1;i<=n;i++)
		if(s[i][j]!=c)return 0;
	return 1;
}
inline int can2() {
	if(s[1][1]=='A'||s[1][m]=='A'||s[n][1]=='A'||s[n][m]=='A')return 1;
	for(int i=1;i<=n;i++)
		if(h(i))return 1;
	for(int i=1;i<=m;i++)
		if(l(i))return 1;
	return 0;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		A=0,P=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) {
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)
				s[i][j]=='A'?A++:P++;
		}
		if(!P)puts("0");
		else if(h(1)||h(n)||l(1)||l(m))puts("1");
		else if(can2())puts("2");
		else if(!h(1,'P')||!h(n,'P')||!l(1,'P')||!l(m,'P'))puts("3");
		else if(A)puts("4");
		else puts("MORTAL");
	}
	return 0;
}