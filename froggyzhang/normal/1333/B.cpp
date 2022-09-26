#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
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
int T,a[N],b[N],n;
int main(){
	T=read();
	while(T--){
		n=read();
		int ok1=0,ok2=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			if(a[i]==1)++ok1;
			else if(a[i]==-1)++ok2;
		}
		for(int i=1;i<=n;++i){
			b[i]=read();
		}
		bool ok=true;
		for(int i=n;i>=1;--i){
			if(a[i]==1)--ok1;
			else if(a[i]==-1)--ok2;
			if(a[i]==b[i])continue;
			if((a[i]>b[i]&&!ok2)||(a[i]<b[i]&&!ok1)){
				ok=false;
				printf("NO\n");
				break;
			}
		}
		if(ok){
			printf("YES\n");
		}
	}
	return 0;
}