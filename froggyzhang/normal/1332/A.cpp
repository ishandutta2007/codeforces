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
int T,a,b,c,d,x,y,X1,Y1,X2,Y2; 
int main(){
	T=read();
	while(T--){
		a=read(),b=read(),c=read(),d=read();
		x=read(),y=read(),X1=read(),Y1=read(),X2=read(),Y2=read();
		if(x<X1||x>X2||y<Y1||y>Y2){
			printf("No\n");
			continue;
		}
		if(((a|b)&&X1==x&&X2==x)||((c|d)&&(Y1==y&&Y2==y))){
			printf("No\n");
			continue;
		}
		x+=b-a,y+=d-c;
		if(x>=X1&&x<=X2&&y>=Y1&&y<=Y2){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}