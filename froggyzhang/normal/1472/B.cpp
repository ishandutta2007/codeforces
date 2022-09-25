#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void Solve(){
	int cnt[3]={0,0,0},x;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;++i){
		cin>>x;
		++cnt[x];
		sum+=x;
	}
	if(sum&1){
		cout<<"NO\n";return;
	}
	for(int i=0;i<=cnt[1];++i){
		for(int j=0;j<=cnt[2];++j){
			if(i+2*j==sum/2){
				cout<<"YES\n";return;
			}	
		}
	}
	cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}