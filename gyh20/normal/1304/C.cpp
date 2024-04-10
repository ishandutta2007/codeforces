#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;
	re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0'){
	t=(t<<3)+(t<<1)+v-48;
	v=getchar();}
	return f?-t:t;
}
int q,n,k,l[102],r[102],t[102];
int main(){
q=read();
while(q--){
	bool ia=1;
	n=read();k=read();
	for(re int i=1;i<=n;++i){
		t[i]=read();
		l[i]=read();
		r[i]=read();
	}
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<i;++j){
			if((abs(r[i]-l[j])>t[i]-t[j])&&(abs(r[i]-r[j])>t[i]-t[j])&&(abs(l[i]-l[j])>t[i]-t[j])&&(abs(l[i]-r[j])>t[i]-t[j])&&((r[i]<l[j])||l[i]>r[j])){
				ia=0;
				break;
			}
		}
		if((abs(r[i]-k)>t[i])&&(abs(l[i]-k)>t[i])&&(r[i]<k||l[i]>k))ia=0;
		if(!ia)break; 
	}
	if(ia)puts("YES");
	else puts("NO");
}
}