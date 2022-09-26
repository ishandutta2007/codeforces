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
int T,n,m;
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		if((n&1)&&(m&1)){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					putchar((i+j)&1?'W':'B');
				}
				putchar('\n');
			}
		}
		else{
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					putchar(((i==1&&j==1)||(i+j)&1)?'B':'W');
				}
				putchar('\n');
			}
		}
	}
	return 0;
}