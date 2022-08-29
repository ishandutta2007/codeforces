#include<bits/stdc++.h>
#define re register
#define ull unsigned long long
using namespace std;
inline ull read(){
	re ull t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a[1002];
vector<int>tmp,V[13];
ull val[13],ans[1002];
int main(){
	for(re int i=0;i<8192;++i)
		if(__builtin_popcount(i)==6)
			tmp.push_back(i);
	n=read();
	for(re int i=1;i<=n;++i){
		a[i]=tmp[i-1];
		for(re int j=0;j<13;++j)if(a[i]&(1<<j))V[j].push_back(i);
	}
	for(re int i=0;i<13;++i){
		if(V[i].size()){
			printf("? ");
			printf("%d ",V[i].size());
			for(auto z:V[i])printf("%d ",z);
			puts("");
			fflush(stdout);
			val[i]=read();
		}
	}
	printf("! ");
	for(re int i=1;i<=n;++i){
		a[i]=tmp[i-1];
		for(re int j=0;j<13;++j)if(!(a[i]&(1<<j)))ans[i]|=val[j];
		printf("%llu ",ans[i]);
	}fflush(stdout);
}