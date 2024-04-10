#include<bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
int n,cnt[5],a[N][5];
void Solve(){
	cin>>n;
	for(int i=0;i<5;++i){
		cnt[i]=0;
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<5;++j){
			cin>>a[i][j];
			if(a[i][j])++cnt[j];
		}
	}
	for(int i=0;i<5;++i){
		for(int j=i+1;j<5;++j){
			bool ok=cnt[i]>=n/2&&cnt[j]>=n/2;
			for(int k=1;k<=n;++k){
				if(!a[k][i]&&!a[k][j]){
					ok=false;break;		
				}
			}
			if(ok){
				cout<<"YES\n";
				return;
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