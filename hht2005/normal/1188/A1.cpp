#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int deg[N];
int main() {
	int n,x,y,fl=1;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		deg[x]++,deg[y]++;
	}
	for(int i=1;i<=n;i++)
		if(deg[i]==2)fl=0;
	if(!fl)puts("NO"),exit(0);
	puts("YES");
	return 0;
}