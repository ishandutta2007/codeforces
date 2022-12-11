#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define x first
#define ll long long
#define y second

using namespace std;

int n, q;
int a[100007];

struct tree{
	int t[200007 * 4];
	int p[200007 * 4];

	void build(int v, int vl, int vr){
		if (vl == vr){
			t[v] = 1;
		} else {
			int vm = (vl + vr) >> 1;
			build(v * 2 + 1, vl, vm);
			build(v * 2 + 2, vm + 1, vr);
		}
	}

	void merge(int &a, int b){
		if (b == 0) return;
		if (b == 1 || b == 2){
			a = b;
		} else if (b == 3){
			if (a == 0) a = 3;
			else if (a == 1) a = 2;
			else if (a == 2) a = 1;
			else if (a == 3) a = 0;
		}
	}

	void push(int v){
		if (p[v]){
			if (p[v] == 1) t[v] = 0;
			if (p[v] == 2) t[v] = 1;
			if (p[v] == 3) t[v] ^= 1;
			if (v * 2 + 1 < 200007 * 4) merge(p[v * 2 + 1], p[v]);
			if (v * 2 + 2 < 200007 * 4) merge(p[v * 2 + 2], p[v]);
			p[v] = 0;
		}
	}

	void rev(int v, int vl, int vr, int l, int r){
		push(v);
		if (r < vl || l > vr) return;
		if (vl >= l && vr <= r){
			p[v] = 3;
			push(v);
		} else {
			int vm = (vl + vr) >> 1;
			rev(v * 2 + 1, vl, vm, l, r);
			rev(v * 2 + 2, vm + 1, vr, l, r);
		}
	}

	void set0(int v, int vl, int vr, int l, int r){
		push(v);
		if (r < vl || l > vr) return;
		if (vl >= l && vr <= r){
			p[v] = 1;
			push(v);
		} else {
			int vm = (vl + vr) >> 1;
			set0(v * 2 + 1, vl, vm, l, r);
			set0(v * 2 + 2, vm + 1, vr, l, r);
		}
	}

	void set1(int v, int vl, int vr, int l, int r){
		push(v);
		if (r < vl || l > vr) return;
		if (vl >= l && vr <= r){
			p[v] = 2;
			push(v);
		} else {
			int vm = (vl + vr) >> 1;
			set1(v * 2 + 1, vl, vm, l, r);
			set1(v * 2 + 2, vm + 1, vr, l, r);
		}
	}


	int get(int v, int vl, int vr, int pos){
		push(v);
		if (vl == vr){
			return t[v];
		} else {
			int vm = (vl + vr) >> 1;
			if (pos <= vm)
				return get(v * 2 + 1, vl, vm, pos);
			return get(v * 2 + 2, vm + 1, vr, pos);
		}
	}
} t;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
//	freopen("input.txt", "r", stdin);
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	t.build(0, -1e5 - 1, 1e5 + 1);
	while(q--){
		char c;
		int x;
		cin >> c >> x;
		//cout << c << ' ' << x << endl;
		if (c == '>'){
			if (x > 0){
				t.set0(0, -1e5 - 1, 1e5 + 1, x + 1, 1e5 + 1);
				t.set1(0, -1e5 - 1, 1e5 + 1, -1e5 - 1, -x - 1);
			} else {
				x = -x;
				t.set0(0, -1e5 - 1, 1e5 + 1, x, 1e5 + 1);
				t.set1(0, -1e5 - 1, 1e5 + 1, -1e5 - 1, -x);
				if (x != 0) t.rev(0, -1e5 - 1, 1e5 + 1, -x + 1, x - 1);
			}
		} else {
			if (x < 0){
				x = -x;
				t.set1(0, -1e5 - 1, 1e5 + 1, x + 1, 1e5 + 1);
				t.set0(0, -1e5 - 1, 1e5 + 1, -1e5 - 1, -x - 1);
			} else {
				t.set1(0, -1e5 - 1, 1e5 + 1, x, 1e5 + 1);
				t.set0(0, -1e5 - 1, 1e5 + 1, -1e5 - 1, -x);
				if (x != 0) t.rev(0, -1e5 - 1, 1e5 + 1, -x + 1, x - 1);
			}
		}

	/*for (int i = 0; i < n; i++){
		int val = t.get(0, -1e5 - 1, 1e5 + 1, a[i]);
		if (val == 0) a[i] = -a[i];
		cout << a[i] << ' ';
	}
	cout << endl;*/
	}	
	for (int i = 0; i < n; i++){
		int val = t.get(0, -1e5 - 1, 1e5 + 1, a[i]);
		if (val == 0) a[i] = -a[i];
		cout << a[i] << ' ';
	}
}