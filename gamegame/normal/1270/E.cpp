#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll x[1001],y[1001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> x[i] >> y[i];
	}
	while(true){
		int cnt=0;
		for(int i=1; i<=n ;i++){
			if((x[i]+y[i])%2==0) cnt++;
		}
		if(cnt!=0 && cnt!=n){
			cout << cnt << '\n';
			for(int i=1; i<=n ;i++){
				if((x[i]+y[i])%2==0) cout << i << '\n';
			}
			return 0;
		}
		if(cnt==0){
			for(int i=1; i<=n ;i++) y[i]--;
		}
		for(int i=1; i<=n ;i++){
			ll nx=(x[i]+y[i])/2;
			ll ny=(x[i]-y[i])/2;
			x[i]=nx;y[i]=ny;
		}
	}
}