#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 300030
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
int T,n,k,a[N];
char s[N];
bool Solve(){
	for(int i=1;i<=n;++i){
		if(s[i]=='?')a[i]=-1;
		else a[i]=s[i]-'0';
	}
	for(int i=1;i<=k;++i){
		int t=-1;
		for(int j=i;j<=n;j+=k){
			if(~t){
				if(~a[j]&&a[j]^t)return false;
			}
			else{
				t=a[j];
			}
		}
		if(~t){
			for(int j=i;j<=n;j+=k){
				a[j]=t;
			}
		}
	}
	int cnt0=0,cnt1=0;
	for(int i=1;i<=k;++i){
		if(a[i]==0)++cnt0;
		else if(a[i]==1)++cnt1;
	}
	return cnt0<=k/2&&cnt1<=k/2;
}
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		scanf("%s",s+1);
		printf(Solve()?"YES\n":"NO\n");
	}
	return 0;
}