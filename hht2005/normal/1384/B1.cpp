#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int d[maxn];
int main() {
	int T,n,k,l;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&n,&k,&l);
		int fl=1;
		for(int i=1;i<=n;i++)scanf("%d",d+i);
		int L=max(k-(l-d[1]),0),R=min(k+(l-d[1]),2*k);
		if(L>R) {
			puts("No");
			continue;
		}
		for(int i=2;i<=n;i++) {
			int L1=max(k-(l-d[i]),0),R1=min(k+(l-d[i]),2*k);
			if(d[i]+k<=l)L1=0,R1=2*k;
			else L1=max(L+1,L1),R1=min(R+1,R1);
			if(L1>R1) {
				puts("No");
				fl=0;
				break;
			}
			L=L1,R=R1;
		}
		if(fl)puts("Yes");
	}
	return 0;
}