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
int T,x,n,m;
int main(){
	T=read();
	while(T--){
		x=read(),n=read(),m=read();
		while(n--){
			if(x>(x/2)+10){
				x=x/2+10;
			}
			else break;
		}
		while(m--)x-=10;
		if(x<=0){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}