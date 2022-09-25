#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=998244353;
typedef long long ll;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int n,m,K,q,x[N],y[N];
void Solve(){
	cin>>n>>m>>K>>q;
	for(int i=1;i<=q;++i){
		cin>>x[i]>>y[i];
	}
	set<int> X,Y;
	int cnt=0;
	for(int i=q;i>=1;--i){
		if((Y.size()<m&&!X.count(x[i]))||(X.size()<n&&!Y.count(y[i]))){
			++cnt;
		}
		X.insert(x[i]);
		Y.insert(y[i]);
	}
	cout<<qpow(K,cnt)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}