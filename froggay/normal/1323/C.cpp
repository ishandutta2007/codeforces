#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000100
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
int n,top,cnt,ans,qwq;
char s[N];
int main(){
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='('){
			++cnt;
			if(top)--top,ans+=2;
			else ++qwq;
		}
		else{
			if(qwq)--qwq;
			else ++top;
		}
	}
	if((n&1)||(cnt*2!=n)){
		printf("-1\n");
	}
	else{
		printf("%d\n",ans);
	}
	return 0;
}