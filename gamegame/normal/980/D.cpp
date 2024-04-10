#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=1e6+1;
int n;
ll a[5001];
ll g[5001];
bool hv[5001];
ll ans[5001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]==0) continue;
		int iu=1e4;
		for(int j=2; j<=iu ;j++){
			while(a[i]%(j*j)==0){
				a[i]/=j*j;
			}
		}
	}
	for(int i=1; i<=n ;i++){
		g[i]=1;
		for(int j=i-1; j>=1 ;j--){
			if(a[j]==a[i]) break;
			g[j]++;
		}
		if(a[i]==0){
			for(int j=1; j<=i ;j++) hv[j]=true;
		}
		for(int j=1; j<=i ;j++){
			ans[max(1LL,g[j]-hv[j])]++;
		}
	}
	for(int i=1; i<=n ;i++) cout << ans[i] << ' ';
	cout << endl;
}