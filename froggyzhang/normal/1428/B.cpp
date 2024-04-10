#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 300030
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
	bool t1=false,t2=false;
	for(int i=1;i<=n;++i){
		if(s[i]=='<')t1=true;
		else if(s[i]=='>')t2=true;
	}
	if(!t1||!t2)return n;
	int ans=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='-'||s[i%n+1]=='-')++ans;
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		printf("%d\n",Solve());
	}
	return 0;
}