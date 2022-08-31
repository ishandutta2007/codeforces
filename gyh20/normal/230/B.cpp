#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a;
signed main(){
	n=read();
	while(n--){
		a=read();
		re int x=sqrt(a);
		if(x*x!=a||a==1)puts("NO");
		else{
			bool ia=1;
			int xx=sqrt(x);
			for(re int i=2;i<=xx;++i){
				if(x%i==0){ia=0;break;
				}
			}
			puts(ia?"YES":"NO");
		}
	}
}