#include<iostream>
#include<cstdio>
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
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,x,a[N];
char s[N];
void Solve(){
	for(int i=1;i<=n;++i){
		a[i]=1;
	}
	for(int i=1;i<=n;++i){
		if(s[i]=='0'){
			if(i-x>=1)a[i-x]=0;
			if(i+x<=n)a[i+x]=0;
		}
	}
	for(int i=1;i<=n;++i){
		if(s[i]=='1'){
			bool ok=false;
			if(i-x>=1)ok|=a[i-x];
			if(i+x<=n)ok|=a[i+x];
			if(!ok){
				printf("-1\n");
				return;
			}
		}
	}
	for(int i=1;i<=n;++i){
		putchar(a[i]+'0');
	}
	putchar('\n');
}
int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		x=read();
		Solve();
	}
	return 0;
}