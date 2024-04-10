#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0'||v>'9')v=getchar();
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t;
}
int n,a[200002],b,c,d,t;
int main(){
	t=read();
	while(t--){
bool ia=0;
	n=read();
	for(re int i=1;i<=n;++i){
		a[i]=read();
	}	
	for(re int i=2;i<=n;++i){
		if(abs(a[i]-a[i-1])>=2){
		ia=1;
		puts("YES");
		printf("%d %d\n",i-1,i);
		break;}
	}
	if(!ia)puts("NO");
	}
}