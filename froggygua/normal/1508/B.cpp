#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100010
const ll inf=2e18;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n;
ll pw2[N],k;
void init(int n){
	pw2[0]=pw2[1]=1;
	for(int i=2;i<=n;++i){
		pw2[i]=min(inf,pw2[i-1]<<1);
	}
}
void Solve(){
	n=read(),k=read();
	if(k>pw2[n]){
		printf("-1\n");
		return;
	}
	--k;
	for(int i=1,j=0;i<=n;j=i,i++){
		while(i<n&&k>=pw2[n-i])k-=pw2[n-i],++i;
		for(int p=j+1;p<=i;++p){
			printf("%d ",i-p+j+1);		
		}
	}
	printf("\n");
}
int main(){
	init(100000);
	T=read();
	while(T--){
		Solve();	
	}
	return 0;
}