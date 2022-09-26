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
int T;
int main(){
	T=read();
	while(T--){
		int x=read(),y=read(),a=read(),b=read();
		if((y-x)%(a+b)!=0){
			cout<<-1<<endl;
		}
		else{
			cout<<(y-x)/(a+b)<<endl;
		}
	}
	return 0;
}