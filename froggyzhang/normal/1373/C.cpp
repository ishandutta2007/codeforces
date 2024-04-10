#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 10001000
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
ll Solve(){
	int now=0;
	ll ans=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='-'){
			--now;
			if(now<0)++now,ans+=i;
		}
		else{
			++now;
		}
	}
	return ans+n;
}
int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		printf("%I64d\n",Solve());
	}
	return 0;
}