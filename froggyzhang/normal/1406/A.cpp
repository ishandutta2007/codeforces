#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 233
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
int T,n,cnt[N],ans;
int main(){
	T=read();
	while(T--){
		memset(cnt,0,sizeof(cnt));
		n=read();
		for(int i=1;i<=n;++i){
			++cnt[read()];
		}
		ans=0;
		for(int i=0;i<=100;++i){
			if(!cnt[i]){
				ans+=i;
				break;
			}
			--cnt[i];
		}
		for(int i=0;i<=100;++i){
			if(!cnt[i]){
				ans+=i;
				break;
			}
			--cnt[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}