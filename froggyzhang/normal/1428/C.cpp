#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
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
int Solve(){
	int A=0,B=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='A')++A;
		else{
			if(!A)++B;
			else --A;
		}
	}
	return A+(B&1);
}
int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		printf("%d\n",Solve());
	}
	return 0;
}