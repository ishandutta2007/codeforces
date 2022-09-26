#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 55
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
char qwq[10]={'a','b','a','c','a','b','a'};
int check1(int pos){
	for(int i=0;i<7;++i){
		if(s[i+pos]^qwq[i])return false;
	}
	return true;
}
int check2(int pos){
	for(int i=0;i<7;++i){
		if(s[i+pos]!='?'&&s[i+pos]^qwq[i])return false;
	}
	return true;
}
int calc(){
	int ans=0;
	for(int i=1;i<=n-6;++i){
		if(check1(i))++ans;
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		int cnt=calc();
		if(cnt>1){
			printf("No\n");
			continue;
		}
		if(!cnt){
			bool ok=false;
			for(int i=1;i<=n-6;++i){
				if(check2(i)){
					static char tmp[23];
					for(int j=0;j<7;++j){
						tmp[j]=s[i+j];
						s[i+j]=qwq[j];
					}
					if(calc()==1){
						ok=true;
						break;
					}
					for(int j=0;j<7;++j){
						s[i+j]=tmp[j];
					}
				}
			}
			if(!ok){
				printf("No\n");
				continue;
			}
		}
		printf("Yes\n");
		for(int i=1;i<=n;++i){
			putchar(s[i]=='?'?'z':s[i]);
		}
		putchar('\n');
	}
	return 0;
}