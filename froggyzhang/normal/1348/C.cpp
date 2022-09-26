#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100010
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
int n,T,k;
char s[N];
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		scanf("%s",s+1);
		n=strlen(s+1);
		sort(s+1,s+n+1);
		if(s[k]^s[1]){
			putchar(s[k]);
		}
		else{
			if(s[n]==s[1]){
				for(int i=1;i<=(n-1)/k+1;++i){
					putchar(s[i]);
				}
			}
			else{
				bool ok=true;
				for(int i=2;i<n;++i){
					if(s[i]^s[1]&&s[i]^s[n]){
						ok=false;
						break;
					}
				}
				if(ok&&s[k]^s[k+1]){
					putchar(s[1]);
					for(int i=1;i<=(n-k-1)/k+1;++i){
						putchar(s[n]);
					}
				}
				else{
					for(int i=k;i<=n;++i){
						putchar(s[i]);
					}
				}	
			}
		}
		putchar('\n');
	}
	return 0;
}