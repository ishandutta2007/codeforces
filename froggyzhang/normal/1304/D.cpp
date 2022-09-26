#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200100
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
int T,n,a[N],cnt;
char s[N];
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		int las=0;
		cnt=n;
		for(int i=1;i<=n;i++){
			if(i==n||s[i]=='>'){
				for(int j=i;j>=las+1;j--){
					a[j]=cnt--;
				}
				las=i;
			}
		}
		for(int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		cnt=las=0;
		for(int i=1;i<=n;i++){
			if(i==n||s[i]=='<'){
				for(int j=i;j>=las+1;j--){
					a[j]=++cnt;
				}
				las=i;
			}
		}
		for(int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	return 0;
}