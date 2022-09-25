#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int T,n,cnt[N][5];
char s[N<<1];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		int len=strlen(s+1);
		memset(cnt[i],0,sizeof(cnt[i]));
		for(int j=1;j<=len;++j){
			++cnt[i][s[j]-'a'];
		}
	}
	int ans=0;
	for(int t=0;t<5;++t){
		static int c[N];
		for(int i=1;i<=n;++i){
			c[i]=0;
			for(int j=0;j<5;++j){
				c[i]+=(j==t?1:-1)*cnt[i][j];
			}
		}
		sort(c+1,c+n+1,greater<int>());
		int sum=0;
		for(int i=1;i<=n+1;++i){
			if(i>n||sum+c[i]<=0){ans=max(ans,i-1);break;}
			sum+=c[i];
		}
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}