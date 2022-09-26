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
int x,y;
int main(){
	x=read(),y=read();
	x=max(x,y);
	switch(x){
		case 1:printf("1/1");break;
		case 2:printf("5/6");break;
		case 3:printf("2/3");break;
		case 4:printf("1/2");break;
		case 5:printf("1/3");break;
		case 6:printf("1/6");break;
	}
	return 0;
}