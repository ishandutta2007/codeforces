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
int n,m,c,a[23333],x;
int main(){
	n=read(),m=read(),c=read();
	while(m--){
		cin>>x;
		if((x<<1)<=c){
			for(int i=1;i<=n;i++){
				if(!a[i]||a[i]>x){
					a[i]=x;
					printf("%d\n",i);
					break;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				if(!a[i]||a[i]<x){
					a[i]=x;
					printf("%d\n",i);
					break;
				}
			}
		}
		fflush(stdout);
	}
	return 0;
}