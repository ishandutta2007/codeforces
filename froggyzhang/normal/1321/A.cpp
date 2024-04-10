#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 110
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
int n,a[N],b[N],sa,sb;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		b[i]=read();
	}
	for(int i=1;i<=n;i++){
		if(a[i]&&b[i])continue;
		if(a[i])++sa;
		if(b[i])++sb;
	}
	if(!sa&&sb>=0){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",sb/sa+1);
	return 0;
}