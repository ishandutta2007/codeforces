#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N],b[N],cnt[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)cnt[i]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
	}
	a[0]=-233;
	int u=0;
	for(int i=1;i<=n;++i){
		while(a[u]!=b[i]||!cnt[a[u]]){
			u++;
			if(u==n+1){cout<<"No\n";return;}
			++cnt[a[u]];
		}
		--cnt[a[u]];
	}
	cout<<"Yes\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}