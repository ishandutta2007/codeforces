#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
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
int n,m,a;
int main(){
	n=read(),m=read(),a=read();
	cout<<((long long)ceil(n*1.0/a)*(long long)ceil(m*1.0/a))<<endl;
	return 0;
}