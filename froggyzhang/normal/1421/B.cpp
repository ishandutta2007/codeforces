#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 233
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
int T,n;
char s[N][N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			scanf("%s",s[i]+1);
		}
		int a=s[1][2]-'0',b=s[2][1]-'0';
		int c=s[n-1][n]-'0',d=s[n][n-1]-'0';
		int cnt=(a!=0)+(b!=0)+(c!=1)+(d!=1);
		if(cnt<=2){
			printf("%d\n",cnt);
			if(a!=0)printf("1 2\n");
			if(b!=0)printf("2 1\n");
			if(c!=1)printf("%d %d\n",n-1,n);
			if(d!=1)printf("%d %d\n",n,n-1);
		}
		else{
			printf("%d\n",4-cnt);
			if(a!=1)printf("1 2\n");
			if(b!=1)printf("2 1\n");
			if(c!=0)printf("%d %d\n",n-1,n);
			if(d!=0)printf("%d %d\n",n,n-1);
		}
	}	
	return 0;
}