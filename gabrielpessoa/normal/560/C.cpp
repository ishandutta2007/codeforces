#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int ans = 0;
	int triangles = 2 * a - 1;
	for(int i = 0; i < b + c; i++) {
		if(i < b) triangles++;
		else if(i > b) triangles--;
		if(i < f) triangles++;
		else if(i > f) triangles--;
		//cout << triangles << endl;
		ans += triangles;
	}
	cout << ans << endl;
	return 0;
}