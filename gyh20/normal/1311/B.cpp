#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return t;
}
int t,n,a[102],p[102],m;
int main(){
	t=read();
	while(t--){
		bool ia=1;
		n=read();m=read();
		memset(p,0,sizeof(p));
		for(re int i=1;i<=n;++i)a[i]=read();
		for(re int j=1;j<=m;++j)p[read()]=1;
		for(re int i=1;i<=n;++i){
		
		for(re int j=1;j<n;++j){
			if(a[j]>a[j+1]){
				if(p[j])swap(a[j],a[j+1]);
			}
		}}
		for(re int i=1;i<=n;++i)if(a[i]<a[i-1]){
			ia=0;
			puts("NO");
			break;
		}
		if(ia){
			puts("YES");
		}
	}
}