#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--){
		int n, k1, k2, x;
		cin>>n>>k1>>k2;
		bool firstPlayer = false;
		while(k1--){
			cin>>x;
			if(x == n)firstPlayer = true;
		}
		while(k2--)cin>>x;
		if(firstPlayer)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}