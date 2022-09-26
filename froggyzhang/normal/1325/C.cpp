#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200200
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
int n,d[N],ans[N],x[N],y[N],pos,p,q;
int main(){
	n=read();
	for(int i=1;i<=n-1;i++){
		x[i]=read(),y[i]=read();
		d[x[i]]++,d[y[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(d[i]>=3)pos=i;
	}
	q=d[pos];
	for(int i=1;i<=n-1;i++){
		if(x[i]==pos||y[i]==pos){
			printf("%d\n",p++);
		}
		else{
			printf("%d\n",q++);
		}
	}
	return 0;
}