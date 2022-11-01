#include <iostream>
#include <vector>
#include <set>

#define endl '\n'

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int width, height, n;
	cin >> width >> height >> n;
	set <int> ws, hs;
	multiset <int> wms, hms;
	ws.insert(0), ws.insert(width), wms.insert(width);
	hs.insert(0), hs.insert(height), hms.insert(height);
	while (n--) {
		char c;
		cin >> c;
		if (c == 'H') {
			int pos;
			cin >> pos;
			auto it = hs.lower_bound(pos);
			int r = *it, l = *(--it);
			hms.erase(hms.find(r - l));
			hms.insert(r - pos), hms.insert(pos - l);
			hs.insert(pos);
		}
		if (c == 'V') {
			int pos;
			cin >> pos;
			auto it = ws.lower_bound(pos);
			int r = *it, l = *(--it);
			wms.erase(wms.find(r - l));
			wms.insert(r - pos), wms.insert(pos - l);
			ws.insert(pos);
		}
		cout << 1LL * *(--wms.end()) * *(--hms.end()) << endl;
	}
	return 0;
}