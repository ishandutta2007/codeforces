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
int T;
void Solve(){
	int n=read();
	int cnt=0;
	for(int i=1;i<=(n<<1);++i)cnt+=read()&1;
	printf(cnt==n?"Yes\n":"No\n");
}
int main(){
	T=read();
	while(T--)Solve();
	return 0;
}