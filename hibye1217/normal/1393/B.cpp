#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define endl '\n'
#define all(v) v.begin(),v.end()
#define fr(p) get<0>(p)
#define sc(p) get<1>(p)
#define th(p) get<2>(p)
#define fo(p) get<3>(p)
#define fi(p) get<4>(p)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tuple<int, int> pii;
typedef tuple<int, int, int> piii;
typedef tuple<int, int, int, int> piiii;
typedef tuple<int, int, int, int, int> piiiii;
typedef tuple<ll, ll> pll;
typedef tuple<ll, ll, ll> plll;
typedef tuple<ll, ll, ll, ll> pllll;
typedef tuple<ll, ll, ll, ll, ll> plllll;

int arr[100020];

int main(){
	Fast;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		arr[x] += 1;
	}
	int c2=0, c4=0, c6=0, c8=0;
	for (int i = 1; i <= 1e5; i++){
		if (arr[i] >= 2) c2++;
		if (arr[i] >= 4) c4++;
		if (arr[i] >= 6) c6++;
		if (arr[i] >= 8) c8++;
	}
	int m;
	cin >> m;
	while (m--){
		string x; int y;
		cin >> x >> y;
		if (x == "+"){
			arr[y] += 1;
			if (arr[y] == 2) c2++;
			if (arr[y] == 4) c4++;
			if (arr[y] == 6) c6++;
			if (arr[y] == 8) c8++;
		}
		if (x == "-"){
			arr[y] -= 1;
			if (arr[y] == 1) c2--;
			if (arr[y] == 3) c4--;
			if (arr[y] == 5) c6--;
			if (arr[y] == 7) c8--;
		}
		//cout << c2 << ' ' << c4 << ' ' << c6 << ' ' << c8 <<endl;
		bool ans = false;
		ans = ans || (c2 >= 3 && c4 >= 1);
		ans = ans || (c4 >= 2);
		ans = ans || (c2 >= 2 && c6 >= 1);
		ans = ans || (c8 >= 1);
		cout << (ans ? "YES" : "NO") << endl;
	}
}