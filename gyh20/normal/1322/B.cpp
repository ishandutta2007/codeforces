#include<bits/stdc++.h>
#define re register
using namespace std;
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
int n,a[400002],ans[32],b[400002],f;
signed main(){
	n=read();
	for(re int i=1;i<=n;++i){
	b[i]=a[i]=read();
	}
	sort(a+1,a+n+1);
	for(re int i=0;i<=25;++i){
		int l=1;
		for(re int j=1;j<=n;++j)a[j]=b[j]%(1<<(i+1));
		sort(a+1,a+n+1);
		for(re int j=n;j;--j){
			while(a[j]+a[l]<(1<<i)&&l<j)++l;
			if(l>=j)break;
			ans[i]+=j-l;
		}		
		l=1;
		for(re int j=n;j;--j){
			while(a[j]+a[l]<((1<<(i+1)))&&l<j)++l;
			if(l>=j)break;
			ans[i]-=j-l;
		}
		l=1;
		for(re int j=n;j;--j){
			while(a[j]+a[l]<((1<<(i+1))+(1<<i))&&l<j)++l;
			if(l>=j)break;
			ans[i]+=j-l;
		}
	}
	for(re int i=0;i<=25;++i){

		f+=(ans[i]&1)*(1<<i);
	}
	printf("%d",f);
}