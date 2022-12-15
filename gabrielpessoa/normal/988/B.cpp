#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int ms = 2005, mv = 2e5+5;
const ll mod = 1e9+7;

string a[ms];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n - 1; j++) {
			if(a[j].size() > a[j+1].size()) swap(a[j], a[j+1]);
		}
	}
	//for(int i = 0; i < n; i++) {
	//	cout << a[i] << '\n';
	//}
	for(int i = 0; i < n -1; i++) {
		if(a[i+1].find(a[i]) == string::npos) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for(int i = 0; i < n; i++) {
		cout << a[i] << '\n';
	}
	return 0;
}