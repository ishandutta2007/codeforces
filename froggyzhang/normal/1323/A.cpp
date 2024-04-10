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
int n,a[1234],T,pos;
int main(){
	T=read();
	while(T--){
		n=read();
		bool ok=false;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(!(a[i]&1)){
				ok=true;
				pos=i;
			}
		}
		if(ok){
			printf("%d\n%d\n",1,pos);
		}
		else if(n>1){
			printf("%d\n%d %d\n",2,1,2);
		}
		else{
			printf("%d\n",-1);
		}
	}
	return 0;
}