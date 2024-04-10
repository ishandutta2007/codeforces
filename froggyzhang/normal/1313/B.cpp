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
int T,x,y,n;
int main(){
	T=read();
	while(T--){
		n=read(),x=read(),y=read();
		if(x>y)swap(x,y);
		int a=min(x,max(1,x-(n-y-1)));
		if(y==n)a=min(n,x+1);
		int b=max(y,min(n,y+(x-1)));
		printf("%d %d\n",a,b);
	}
	return 0;
}