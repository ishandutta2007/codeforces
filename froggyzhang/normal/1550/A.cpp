#include<bits/stdc++.h>
using namespace std;
#define N 5005
typedef long long ll;
const int H=5000;
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
int T,ans[N];
int main(){
	T=read();
	for(int i=1,now=0;;i+=2){
		int las=now+1;
		now=min(now+i,H);
		for(int j=las;j<=now;++j){
			ans[j]=(i+1)/2;	
		}
		if(now==H)break;
	}
	while(T--){
		printf("%d\n",ans[read()]);
	}
	return 0;
}