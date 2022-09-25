#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int ans[2333333];
int main(){
	int n=1;
	while(n<1e6){
		ans[n]=ans[n+1]=1;
		n=2*n+1+(n&1);
	}
	printf("%d\n",ans[read()]);
	return 0;
}