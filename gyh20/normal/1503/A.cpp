#include<bits/stdc++.h>
#define N 200005
using namespace std;
char s[N];
int T,n,T0,T1;
int main() {
	cin>>T;
	while(T--) {
		scanf("%d%s",&n,s+1),T0=T1=0;
		for(int i=1; i<=n; ++i) {
			if(s[i]=='0')++T0;
			else ++T1;
		}
		if((T0&1)||(s[1]=='0')||(s[n]=='0'))puts("NO");
		else {
			puts("YES");
			for(int i=1,n0=0,n1=0; i<=n; ++i) {
				if(s[i]=='1')putchar((++n1<=T1/2)?'(':')');
				else putchar(((++n0)&1)?')':'(');
			}
			puts("");
			for(int i=1,n0=0,n1=0; i<=n; ++i) {
				if(s[i]=='1')putchar((++n1<=T1/2)?'(':')');
				else putchar(((++n0)&1)?'(':')');
			}
			puts("");
		}
	}
	return 0;
}