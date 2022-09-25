#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,K,cnt[N];
char s[N];
void Solve(){
	cin>>n>>K;
	cin>>(s+1);
	int rem=K;
	for(int i=1;i<=n;++i){
		cnt[i]=0;
	}
	for(int i=1;i<=n;++i){
		int t=(s[i]-'0')^(K&1);
		if(!t){
			if(rem){
				cnt[i]=1;
				--rem;
			}
		}
	}
	while(rem>1)cnt[1]+=2,rem-=2;
	if(rem)cnt[n]++;
	for(int i=1;i<=n;++i){
		cout<<char(((s[i]-'0')^((K-cnt[i])&1))+'0');
	}
	cout<<'\n';
	for(int i=1;i<=n;++i){
		cout<<cnt[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}

//shabi luogu