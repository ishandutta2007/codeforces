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
int n,ans[10000],cnt;
char s[10000],t[10000];
int a[1000],b[1000];
void End(){
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++){
		printf("%d ",ans[i]);
	}
}
int main(){
	n=read();
	scanf("%s",s+1);
	bool ok=true;
	for(int i=1;i<=n;i++){
		if(s[i]=='W')a[i]=1;
		else a[i]=0;
	}
	for(int i=2;i<=n;i++){
		if(a[i]!=a[1]){
			ok=false;
			break;
		}
	}
	if(ok){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	for(int i=1;i<n;i++){
		if(b[i]==1){
			ans[++cnt]=i;
			b[i]^=1,b[i+1]^=1;
		}
	}
	if(b[n]==0){
		End();
		return 0;
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	for(int i=1;i<n;i++){
		if(b[i]==0){
			ans[++cnt]=i;
			b[i]^=1,b[i+1]^=1;
		}
	}
	if(b[n]==1){
		End();
		return 0;
	}
	printf("-1\n");
	return 0;
}
/*
8
BWBWBBBW
*/