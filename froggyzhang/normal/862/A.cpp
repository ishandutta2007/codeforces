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
int n,x,ans;
int main(){
	n=read(),x=read(),ans=x;
	for(int i=1;i<=n;++i){
		int num=read();
		if(num<x)--ans;
		else if(num==x)++ans;
	}
	cout<<ans<<endl;
	return 0;
}