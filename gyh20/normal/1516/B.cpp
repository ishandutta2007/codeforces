#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,k,a[2002],pos;
int main(){
	int t=read();
	while(t--){
		n=read();
		re int sum=0;
		for(re int i=1;i<=n;++i)a[i]=read(),sum^=a[i];
		re int s=0;
		if(sum==0){
			puts("YES");
			continue;
		}
		re bool ia=1;
		for(re int i=1;i<n;++i){
			s^=a[i];
			if(s==sum){
				re bool ss=1;
				re int r=0;
				for(re int j=n;j>i;--j){
					r^=a[j];
					if(r==sum){
						ss=0;
						break;
					}
				}
				if(ss)continue;
				ia=0;
				break;
			}
		}
		if(ia)puts("NO");
		else puts("YES");
	}
}