#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000100
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
int T,n,m,cnt[26],t[26];
char a[N],b[N];
bool Solve(){
	n=read(),m=read();
	memset(t,0,sizeof(t));
	memset(cnt,0,sizeof(cnt));
	scanf("%s",a+1);
	scanf("%s",b+1);
	for(int i=1;i<=n;++i){
		++cnt[a[i]-'a'];
		++t[b[i]-'a'];
	}
	for(int i=0;i<25;++i){
		if(cnt[i]<t[i]||(cnt[i]-t[i])%m)return false;
		cnt[i+1]+=cnt[i]-t[i];
	}
	return true;
}
int main(){
	T=read();
	while(T--){
		printf(Solve()?"Yes\n":"No\n");
	}
	return 0;
}