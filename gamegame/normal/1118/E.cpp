#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=1e6+1;
ll n,k;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	if(n>k*(k-1)) return cout << "NO\n",0;
	cout << "YES\n";
	for(int i=1; i<k ;i++){
		for(int j=1; j<=k ;j++){
			if(n==0) return 0;
			cout << j << ' ' << (i+j-1)%k+1 << '\n';
			n--;
		}
	}
}