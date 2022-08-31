#include<bits/stdc++.h>
#define re register
#define ull unsigned long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,b[200002];
ull a[200002],ans;
map<ull,ull>Sum,Num;
int main(){
	mt19937_64 rng(time(0));
	n=read(),m=read();
	for(re int i=1;i<=n;++i){
		re int l=read(),r=read();re ull tmp=rng(); 
		++b[l],--b[r+1];
		a[l+1]^=tmp,a[r+1]^=tmp;
	}
	for(re int i=1;i<=m;++i)a[i]^=a[i-1];
	for(re int i=1;i<=m;++i)a[i]^=a[i-1],b[i]+=b[i-1];
	for(re int i=1;i<=m;++i){
		Sum[a[i]]+=-i+1,++Num[a[i]];
		ans+=Num[a[i]]*i+Sum[a[i]];
	}
	re int lst=0;
	for(re int i=1;i<=m;++i){
		if(b[i])lst=i;
		ans-=1ll*(i-lst)*(i-lst+1)/2;
	}printf("%llu",ans);
}