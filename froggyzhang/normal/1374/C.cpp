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
int T,n;
char s[2333];
void Solve(){
	n=read();
	scanf("%s",s+1);
	int now=0,ans=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='(')++now;
		else{
			if(!now){
				++ans;continue;
			}
			--now;
		}
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}