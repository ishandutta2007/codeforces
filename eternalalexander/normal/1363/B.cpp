#include <bits/stdc++.h>
const int inf = 1e8;
int sum[1005];
char s[1005];

void solve(){
	int ans = inf;
	scanf("%s",s+1);
	int n = std::strlen(s+1);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+s[i]-'0';
	for(int i=0;i<=n;++i){
		ans=std::min(ans,sum[i] + (n-i) - (sum[n] - sum[i]) );
		ans=std::min(ans,i - sum[i] + (sum[n] - sum[i]) );
	}
	printf("%d\n",ans);
}

int main(){
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}