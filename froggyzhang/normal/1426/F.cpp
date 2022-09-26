#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e9+7;
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
int A,B,C,n,pw3[N],cnt[N];
char s[N];
int main(){
	n=read();
	scanf("%s",s+1);
	pw3[0]=1;
	for(int i=1;i<=n;++i){
		pw3[i]=3LL*pw3[i-1]%mod;
	}
	for(int i=1;i<=n;++i){
		cnt[i]=cnt[i-1]+(s[i]=='?');
	}
	for(int i=1;i<=n;++i){
		if(s[i]=='a'){
			A=(A+pw3[cnt[i]])%mod;
		}
		else if(s[i]=='b'){
			B=(B+A)%mod;
		}
		else if(s[i]=='c'){
			C=(C+B)%mod;
		}
		else{
			C=(3LL*C+B)%mod;
			B=(3LL*B+A)%mod;
			A=(3LL*A+pw3[cnt[i-1]])%mod;
		}
	}
	printf("%d\n",C);
	return 0;
}