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
char s[N];
int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		bool same=true;
		for(int i=2;i<=n;++i){
			if(s[i]!=s[i-1]){
				same=false;break;
			}
		}	
		if(same){
			for(int i=1;i<=n;++i){
				putchar(s[i]);
			}
		}
		else{
			for(int i=1;i<=n;++i){
				putchar('0'),putchar('1');
			}
		}
		putchar('\n');
	}
	return 0;
}