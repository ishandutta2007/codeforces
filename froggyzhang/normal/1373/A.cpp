#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
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
int T;
int main(){
	T=read();
	while(T--){
		int a=read(),b=read(),c=read();
		if(a>c){
			printf("-1 1\n");
		}
		else if(a==c){
			printf("-1 %d\n",b);
		}
		else{
			printf("1 %d\n",1LL*a*b>c?b:-1);
		}
	}
	return 0;
}