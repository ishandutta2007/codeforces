#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,K,cnt[N],a[N];
void Solve(){
	cin>>n>>K;
	for(int i=1;i<=n;++i)cnt[i]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++cnt[a[i]];
	}
	int now=-n;
	int ans=1e9,cl=0,cr=0;
	for(int i=1,j=1;i<=n;++i){
		while(j<=n&&now<K){
			now+=2*cnt[j];
			++j;
		}
		if(now>=K){
			if(j-i<ans){
				ans=j-i;
				cl=i,cr=j-1;
			}
		}
		now-=2*cnt[i];
	}
	cout<<cl<<' '<<cr<<'\n';
	for(int i=1,las=0,now=0,jb=1;i<=n;++i){
		now+=a[i]>=cl&&a[i]<=cr?1:-1;
		if(i==n||(now==jb&&jb<K)){
			cout<<las+1<<' '<<i<<'\n';
			++jb;
			las=i;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}