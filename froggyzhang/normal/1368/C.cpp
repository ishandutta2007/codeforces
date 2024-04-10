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
int n;
void print(int x,int y){
	printf("%d %d\n",x+1,y);
	printf("%d %d\n",x,y+1);
	printf("%d %d\n",x+2,y);
	printf("%d %d\n",x,y+2);
	printf("%d %d\n",x+1,y+2);
	printf("%d %d\n",x+2,y+1);
	printf("%d %d\n",x+2,y+2);
}
int main(){
	n=read()+1;
	printf("%d\n",7*n+1);
	printf("%d %d\n",1,1);
	for(int i=1;i<=n;++i){
		print(2*i-1,2*i-1);
	}
	return 0;
}