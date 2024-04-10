#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
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
int T,d,k;
bool Solve(){
	int p=0;
	while(2LL*(p+k)*(p+k)<=1LL*d*d)p+=k;
	return 1LL*p*p+1LL*(p+k)*(p+k)<=1LL*d*d;
}
int main(){
	T=read();
	while(T--){
		d=read(),k=read();
		printf(Solve()?"Ashish\n":"Utkarsh\n");
	}
	return 0;
}