#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=2e5+1,INF=0x3f3f3f3f;
int T,ans,n,k,flag;
char a[N];
int cnt[N][26];
V input(){
	scanf("%d%d%s",&n,&k,a);
}
V init(){
	FOR(i,0,n-1)
		cnt[i%k][a[i]-'a']++;
	flag=(n/k)&1;
}
V work(){
	int tmp=0,l=0,r=k-1,sum;
	while(l<=r){
		tmp=0,sum=0;
		FOR(i,0,25)
			tmp=max(tmp,cnt[l][i]+cnt[r][i]),sum+=cnt[l][i]+cnt[r][i];
		tmp=sum-tmp;
		if(l==r)ans+=tmp>>1;
		else ans+=tmp;
		l++,r--;
	}
	cout<<ans<<'\n',ans=0;
	FOR(i,0,k-1)FOR(j,0,25)cnt[i][j]=0;
}
int main(){
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}