#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int ms = 55;

int arr[ms];

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 2; i < n; i++) {
		if(s[i] == 'x' && s[i-1] == 'x' && s[i-2] == 'x') {
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}