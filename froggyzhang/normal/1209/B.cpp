#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 111
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
int a[N],b[N],p[N],n,ans;
char s[N];
int main(){
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		p[i]=s[i]-'0';
		ans+=p[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read();
	}
	for(int i=1;i<=50000;i++){
		int tmp=0;
		for(int j=1;j<=n;j++){
			if(b[j]>i){
				tmp+=p[j];
			}
			else{
				tmp+=(((i-b[j])/a[j])&1)^p[j]^1;
			}
		}
		ans=max(ans,tmp);
	} 
	printf("%d\n",ans);
	return 0;
}