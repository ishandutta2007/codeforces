#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read() {
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0') {
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return t;
}
struct edge {
	int to,next;
} e[2002];
int n,k,mns,ans[10002];
int main() {
	n=read();
	k=read();
	int tmp=0;
	int x=1,y=1,z=0,mx,tot=0;
	bool ia=1;
	while(tot<n) {
		mx=x;
		if(x>1e9){
			ia=0;
			break;
		}
		if(tmp/2+z<=k) {
			ans[++tot]=x,x+=y,z+=tmp/2,++tmp;
		} else {
			break;
		}
	}
	if(!ia){
		puts("-1");
		return 0;
	}
	int s=mx-1,kk=k-z,lst,mx1;
	for(re int i=s+1;i<=s*2-1;++i){
		mx1=mx=i;lst=i-1;
		if((s*2-i+1)/2<=kk&&tot<n){
			kk-=(s*2-i+1)/2;
			ans[++tot]=i;
		}
	}
	if(kk){
		puts("-1");
		return 0;
	}
	while(tot<n){
		ans[++tot]=lst+mx;
		mx+=mx1;
	}
	for(re int i=1; i<=tot; ++i)printf("%d ",ans[i]);
}