#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> P;
#define fi first
#define sc second
ll n,p;
int main(){
	cin >> n >> p;
	for(int i=1;;i++){
		n -= p;
		if(n < i){
			puts("-1");
			return 0;
		}
		int x = __builtin_popcount(n);
		if(x <= i){
			cout << i << endl; return 0;
		}
	}
}