#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int T,n,m,cnt[N],ans[N];
vector<int> a[N];
void Solve(){
	n=read(),m=read();
	int lim=(m+1)/2;
	for(int i=1;i<=n;++i)cnt[i]=0;
	for(int i=1;i<=m;++i){
		a[i].clear();
		int k=read();
		while(k--){
			a[i].push_back(read());
		}
		++cnt[a[i][0]];
		ans[i]=0;
	}
	for(int i=1;i<=n;++i){
		if(cnt[i]>lim){
			for(int j=1;j<=m&&cnt[i]>lim;++j){
				if(a[j][0]==i&&(int)a[j].size()>1){
					--cnt[i];
					ans[j]=1;
				}
			}
			if(cnt[i]>lim)return (void)printf("NO\n");
		}
	}
	printf("YES\n");
	for(int i=1;i<=m;++i){
		printf("%d ",a[i][ans[i]]);
	}
	printf("\n");
}	
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}