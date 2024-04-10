#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const int M=262144;
const ll mod=1e9+7;
const int mg=30;
int n,m;
ll a[N];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	int c0=0,c1=0;
	cin >> s;
	for(auto c:s){
		if(c=='0') c0++;
		else c1++;
	}
	cout << max(n-2*c0,n-2*c1) ;
}