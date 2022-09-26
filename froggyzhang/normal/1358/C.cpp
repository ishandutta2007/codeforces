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
ll X1,Y1,X2,Y2;
int main(){
	T=read();
	while(T--){
		X1=read(),Y1=read(),X2=read(),Y2=read();
		if(X1==X2||Y1==Y2){
			printf("1\n");
			continue;
		}
		printf("%lld\n",(X2-X1)*(Y2-Y1)+1);
	}
	return 0;
}