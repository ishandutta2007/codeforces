#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 2333
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
int n,vis[N],an;
int ans[N];
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int l=1,r=n;
	while(l<=r){
		while(l<=r&&s[l]==')')++l;
		while(l<=r&&s[r]=='(')--r;
		if(l<=r)ans[++an]=l,ans[++an]=r,++l,--r;
	}
	if(!an){
		printf("0\n");
	}
	else{
		printf("1\n");
		printf("%d\n",an);
		sort(ans+1,ans+an+1);
		for(int i=1;i<=an;i++){
			printf("%d ",ans[i]);
		}
	}
	return 0;
}