#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
inline ull read(){
	ull x=0,f=1;
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
ull n;
int s,T;
bool check(ull x){
	int tot=0;
	while(x){
		tot+=x%10;
		x/=10;
	}
	return tot<=s;
}
int main(){
	T=read();
	while(T--){
		n=read(),s=read();
		ull ans=0,k=0,p=n,pw=1;
		if(check(n)){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=19;++i){
			k+=p%10*pw;
			pw*=10;
			p/=10;
			ans=pw-k;
			if(check(n+ans))break;
		}
		cout<<ans<<endl;
	}
	return 0;
}