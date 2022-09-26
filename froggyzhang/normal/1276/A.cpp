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
int T;
char s[N];
int ans[N],cnt;
int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		int n=strlen(s+1);cnt=0;
		for(int i=1;i<=n-2;i++){
			if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'){
				if(i!=n-2&&s[i+3]=='o')ans[++cnt]=i+1;
				else ans[++cnt]=i+2,i+=2;
			}
			else if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e'){
				ans[++cnt]=i+1,i++;
			}
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}