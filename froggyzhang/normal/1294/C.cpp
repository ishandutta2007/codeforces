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
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,n;
bool Solve(int x){
	int a=0,b=0;
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			a=i;
			x/=i;
			break;
		}
	}
	if(!a)return false;
	for(int i=2;i*i<=x;++i){
		if(x%i==0&&a^i){
			b=i;
			x/=i;
			break;
		}
	}
	if(!b)return false;
	if(x^a&&x^b){
		printf("YES\n");
		printf("%d %d %d\n",a,b,x);
		return true;
	}
	return false;
}
int main(){
	T=read();
	while(T--){
		n=read();
		if(!Solve(n)){
			printf("NO\n");
		}
	}
	return 0;
}