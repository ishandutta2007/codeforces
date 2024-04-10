#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
char s[N];
int sum[N];
int main() {
	int T,n,q,l,r;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+(i%2?1:-1)*(s[i]=='-'?-1:1);
		while(q--) {
			scanf("%d%d",&l,&r);
			if(sum[l-1]==sum[r])puts("0");
			else if((sum[r]-sum[l-1])%2)puts("1");
			else puts("2");
		}
	}
	return 0;
}