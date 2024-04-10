#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
string u[2];
int main() {
	cin >> u[0] >> u[1];
	cout << u[0] << ' ' << u[1] << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string r, t;
		cin >> r >> t;
		if (r == u[0]) u[0] = t;
		else u[1] = t;
		cout << u[0] << ' ' << u[1] << endl;
	}
	return 0;
}