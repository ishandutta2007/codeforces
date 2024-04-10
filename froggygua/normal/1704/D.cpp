#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
int n,m;
ll sum[N];
void Solve(){
	cin>>n>>m;
	for(int i=0;i<n;++i)sum[i]=0;
	ll x;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>x;
			sum[i]+=x*j;
		}
	}
	cout<<(max_element(sum,sum+n)-sum+1)<<' '<<(*max_element(sum,sum+n))-(*min_element(sum,sum+n))<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}