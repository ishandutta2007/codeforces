#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve(){
	string x, y;
	cin>>x>>y;
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	int firstOcc = 0;
	while(y[firstOcc] == '0')firstOcc++;
	for(int i = firstOcc; i < x.size(); i++){
		if(x[i] ==  '1'){
			cout<<i - firstOcc<<endl;
			return;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--)solve();

	return 0;
}