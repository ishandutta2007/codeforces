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
int T,a,b,k;
inline int calc(int x){
	int ans=0;
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			while(x%i==0)++ans,x/=i;
		}
	}
	if(x>1)++ans;
	return ans;
}
bool Solve(){
	if(k==1)return a!=b&&(a%b==0||b%a==0);
	return calc(a)+calc(b)>=k;	
}
int main(){
	T=read();
	while(T--){
		a=read(),b=read(),k=read();
		printf(Solve()?"YES\n":"NO\n");
	}
	return 0;
}