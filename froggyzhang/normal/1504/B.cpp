#include<bits/stdc++.h>
using namespace std;
#define N 300030
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
char a[N],b[N];
inline bool check(){
	int x=0,y=0;
	int u=0;
	for(int i=1;i<=n;++i){
		int ca=a[i]-'0',cb=b[i]-'0';
		u+=ca==0?-1:1;
		x+=ca^cb;
		y+=ca==cb;
		if(!u){
			if(x&&y)return false;
			x=y=0;
		}
	}	
	return x==0;
}
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",a+1);
		scanf("%s",b+1);
		printf(check()?"YES\n":"NO\n");	
	}
	return 0;
}