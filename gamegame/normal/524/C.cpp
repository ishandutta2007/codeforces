#include<bits/stdc++.h>
using namespace std;
int n,kk;
int a[5001];
int hv[10000001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> kk;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		hv[a[i]]=i;
	}
	int q;cin >> q;
	for(int i=1; i<=q ;i++){
		int x;cin >> x;
		int best=21;
		for(int j=n; j>=1 ;j--){
			for(int k=1; k<=kk ;k++){
				if(x<k*a[j]) continue;
				if(x==k*a[j]) best=min(best,k);
				for(int l=1; l+k<=kk ;l++){
					int duh=(x-k*a[j]);
					if(duh%l!=0) continue;
					duh/=l;
					if(duh<=1e7 && hv[duh]) best=min(best,l+k);
				}
			}
		}
		if(best==21) cout << -1 << '\n';
		else cout << best << '\n';
	}
}