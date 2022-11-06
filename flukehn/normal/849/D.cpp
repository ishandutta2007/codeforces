#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=100010;
struct fst {
	int id, g, x, y;
	friend bool operator< (fst a, fst b) {
		return a.x < b.x;
	}
} arr[N];
int n, w, h, pref[N], ans[N][2];
vector<fst> ver, hor;
int main() {
	n = rd(), w = rd(), h = rd();
	rep(i,0,n-1) {
		arr[i].id = i;
		arr[i].g=rd();;
		if (arr[i].g == 1)
			arr[i].x =rd(), arr[i].y = rd(), arr[i].y *= -1;
		else
			arr[i].y =rd(), arr[i].x=rd(), arr[i].x *= -1;
	}
	sort(arr, arr+n, [](fst a, fst b) {
		return a.x + a.y < b.x + b.y;
	});
	for (int i = 0; i < n;) {
		int p = arr[i].x + arr[i].y;
		ver.clear();
		hor.clear();
		while (i < n && arr[i].x + arr[i].y == p) {
			if (arr[i].g == 1) ver.push_back(arr[i]);
			else hor.push_back(arr[i]);
			i++;
		}
		sort(ver.begin(), ver.end());
		sort(hor.begin(), hor.end());
		vector<fst>::iterator it, t;
		for (it = ver.begin(); it != ver.end(); it++) {
			t = lower_bound(hor.begin(), hor.end(), *it);
			int l = t - hor.begin(), r = ver.end() - it - 1, k = it -> id;
			if (l >= r + 1) ans[k][0] = w, ans[k][1] = (t - r - 1) -> y;
			else ans[k][0] = (it + l) -> x, ans[k][1] = h;
		}
		for (it = hor.begin(); it != hor.end(); it++) {
			t = lower_bound(ver.begin(), ver.end(), *it);
			int l = it - hor.begin(), r = ver.end() - t, k = it -> id;
			if (l >= r) ans[k][0] = w, ans[k][1] = (it - r) -> y;
			else ans[k][0] = (t + l) -> x, ans[k][1] = h;
		}
	}
	rep(i,0,n-1)
	cout << ans[i][0] << ' ' << ans[i][1] << endl;
}