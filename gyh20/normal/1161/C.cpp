#include<cstdio>
#include<vector>
#include<algorithm>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a[200002],mn,ans;
int main(){
	n=read();mn=1e9;
	for(re int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]<mn)mn=a[i],ans=1;
		else if(a[i]==mn)++ans;
	}
	if(ans<=n/2)puts("Alice");
	else puts("Bob");
}