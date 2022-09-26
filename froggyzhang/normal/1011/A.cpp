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
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,k,cnt[50],ans;
char s[55];
int main(){
	n=read(),k=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		++cnt[s[i]-'a'];
	}
	for(int i=0;i<26&&k;++i){
		if(cnt[i]){
			ans+=i+1;
			++i;
			--k;
		}
	}
	if(k)return !printf("-1\n");
	printf("%d\n",ans);
	return 0;
}