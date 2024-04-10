#include<bits/stdc++.h>
using namespace std;
#define N 100010
const int lim=1e5;
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
int T,ok[N];
int main(){
	T=read();
	for(int i=0;11*i<=lim;++i){
		for(int j=0;111*j+11*i<=lim;++j){
			ok[11*i+111*j]=1;
		}
	}
	while(T--){
		int x=read();
		printf(x>lim||ok[x]?"YES\n":"NO\n");
	}
	return 0;
}