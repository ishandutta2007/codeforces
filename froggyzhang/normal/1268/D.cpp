#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
int G[N][N],n,d[N];
char s[N];
bool check(){
	static int g[N];
	for(int i=1;i<=n;++i)g[i]=d[i];
	sort(g+1,g+n+1);
	int now=0;
	for(int i=1;i<n;++i){
		now+=g[i];
		if(now==i*(i-1)/2)return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>(s+1);
		for(int j=1;j<=n;++j){
			d[j]+=(G[i][j]=s[j]-'0');
		}
	}
	if(n<=6){
		int mn=n+1,cnt=0;
		for(int s=0;s<(1<<n);++s){
			static int H[20][20];
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					H[i][j]=G[i][j];
			for(int i=1;i<=n;++i){
				if(s>>(i-1)&1){
					for(int j=1;j<=n;++j){
						if(i^j)H[i][j]^=1,H[j][i]^=1;
					}	
				}
			}
			for(int i=1;i<=n;++i)d[i]=0;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					d[j]+=H[i][j];	
				}	
			}
			if(check()){
				int w=__builtin_popcount(s);
				if(w<mn){
					mn=w,cnt=1;
				}
				else if(w==mn){
					++cnt;
				}
			}
		}
		if(mn>n){
			cout<<-1<<'\n';	
		}
		else{
			for(int i=1;i<=mn;++i)cnt*=i;
			cout<<mn<<' '<<cnt<<'\n';
		}
	}
	else{
		if(check()){
			cout<<0<<' '<<1<<'\n';
			return 0;
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			d[i]=n-1-d[i];
			for(int j=1;j<=n;++j){
				if(i==j)continue;
				d[j]+=G[i][j]?-1:1;
			}
			ans+=check();
			d[i]=n-1-d[i];
			for(int j=1;j<=n;++j){
				if(i==j)continue;
				d[j]+=G[i][j]?1:-1;
			}
		}	
		cout<<1<<' '<<ans<<'\n';
	}
	return 0;
}