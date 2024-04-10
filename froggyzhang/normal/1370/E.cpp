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
int n;
char s[N],t[N];
int main(){
	n=read();
	scanf("%s",s+1);
	scanf("%s",t+1);
	int now=0,mx=0,mn=0;
	for(int i=1;i<=n;++i){
		if(s[i]==t[i])continue;
		now+=(s[i]=='0'?-1:1);
		mn=min(mn,now),mx=max(mx,now);
	}
	printf("%d\n",now==0?mx-mn:-1);
	return 0;
}