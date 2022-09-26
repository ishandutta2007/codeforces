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
int a,b;
int main(){
	a=read(),b=read();
	if(a==b){
		cout<<a*10+1<<" "<<b*10+2<<endl;
	}
	else if(a+1==b){
		cout<<a*10+9<<" "<<b*10<<endl;
	}
	else if(a==9&&b==1){
		cout<<99<<" "<<100<<endl;
	}
	else{
		cout<<-1<<endl;
	}
	return 0;
}