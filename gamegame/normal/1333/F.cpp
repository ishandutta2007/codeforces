#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=1e9+7;
ll n,m;
bool np[N];
int lp[N];
pair<int,int>a[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=2; i<=n ;i++){
		if(np[i]) continue;
		for(int j=i; j<=n ;j+=i){
			if(lp[j]==0) lp[j]=i;
			np[j]=true;
		}
	}
	for(int i=1; i<=n-1 ;i++) a[i]={(i+1)/lp[i+1],i+1};
	sort(a+1,a+n);
	for(int i=1; i<n ;i++) cout << a[i].fi << ' ';
	cout << endl;
}