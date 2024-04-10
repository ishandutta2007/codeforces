#include <bits/stdc++.h>
			 
#define x first
#define y second
#define mp make_pair
#define pub push_back
#define all(a) a.begin(), a.end()
#define ll long long
#define db double
	
using namespace std;

int n;
int a[33];
int b[33];

int main(){
	// /freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<pair<int, int> > t;
	for (int i = 0; i < n; i++) t.pub(mp(a[i], i));
	sort(all(t));
	for (int i = 0; i < t.size(); i++){
		int nxt;
		if (i + 1 < t.size()) nxt = t[i + 1].x;
		else nxt = t[0].x;
		b[t[i].y] = nxt;
	}
	for (int i = 0; i < n; i++) cout << b[i] << ' ';
}