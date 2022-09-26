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
int T,n,k,f[N],cnt[N][26],ans;
char s[N];
int getf(int x){
	if(f[x]==x)return x;
	return f[x]=getf(f[x]);
}
int main(){
	T=read();
	while(T--){
		n=read(),k=read(),ans=n;
		scanf("%s",s+1);
		for(int i=1;i<=n;++i){
			f[i]=i;
			memset(cnt[i],0,sizeof(cnt[i]));
		}
		for(int i=1;i<=n/2;++i){
			f[n-i+1]=i;
		}
		for(int i=1;i<=n-k;++i){
			int fx=getf(i),fy=getf(i+k);
			if(fx==fy)continue;
			f[fy]=fx;
		}
		for(int i=1;i<=n;++i){
			int fx=getf(i);
			cnt[fx][s[i]-'a']++;
		}
		for(int i=1;i<=n;++i){
			if(getf(i)^i)continue;
			int mx=0;
			for(int j=0;j<26;++j){
				mx=max(mx,cnt[i][j]);
			}
			ans-=mx;
		}
		printf("%d\n",ans);
	}
	return 0;
}