#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int ,int> pii;

int n, a, s[111111], l=0, ans;

int main() {
	cin >> n;
	while (n--) {
		cin >> a;
		while (l) {
			if ((a^s[l-1])>ans) ans=a^s[l-1];
			if (s[l-1]<a) l--; else break;
		}
		s[l]=a;
		l++;
	}
	cout << ans;
}