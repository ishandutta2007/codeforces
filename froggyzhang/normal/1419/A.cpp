#include<iostream>
#include<cstdio>
#include<cstring>
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
int T,n;
char s[2333];
int Solve(){
	n=read();
	scanf("%s",s+1);
	if(n&1){
		for(int i=1;i<=n;i+=2){
			if((s[i]-'0')&1)return 1;
		}
		return 2;
	}
	else{
		for(int i=2;i<=n;i+=2){
			if(!((s[i]-'0')&1))return 2;
		}
		return 1;
	}
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}