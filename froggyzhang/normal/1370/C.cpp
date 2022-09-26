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
#define win1 printf("Ashishgup\n");continue;
#define win2 printf("FastestFinger\n");continue;
int T,n;
inline bool Prime(int x){
	for(int i=3;i*i<=x;++i){
		if(x%i==0)return false;
	}
	return true;
}
int main(){
	T=read();
	while(T--){
		n=read();
		if(n==1||n==4){
			win2;
		}
		if(n&1||n==2){
			win1;
		}
		int cnt=0;
		while(!(n&1))n>>=1,++cnt;
		if(cnt>=2){
			if(n>1){
				win1;
			}
			else{
				win2;
			}
		}
		if(Prime(n)){
			win2;
		}
		else{
			win1;
		}
	}
	return 0;
}