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
int T,a1,a2,a3,a4,a5,c1,c2,c3;
int main(){
	T=read();
	while(T--){
		c1=read(),c2=read(),c3=read();
		a1=read(),a2=read(),a3=read(),a4=read(),a5=read();
		c1-=a1,c2-=a2,c3-=a3;
		a4=max(0,a4-c1),a5=max(0,a5-c2);
		if(c1>=0&&c2>=0&&c3>=a4+a5){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}