#include <bits/stdc++.h>
using namespace std;

int vis[100010];

int main(){
	int n; cin >> n;
	int Y1 = -1, Y2 = -1;
	for (int i = 1; i <= n; i++){
		cout << "? " << 1 << " " << i << " " << n << " " << i << endl;
		cout.flush();
		int x; cin >> x;
		if (x & 1){
			if (Y1 == -1) Y1 = i;
			else Y2 = i;
		}
	}
	int x1 = -1, x2 = -1;
	for (int i = 1; i <= n; i++){
		cout << "? " << i << " " << 1 << " " << i << " " << n << endl;
		cout.flush();
		int x; cin >> x;
		if (x & 1){
			if (x1 == -1) x1 = i;
			else x2 = i;
		}
	}
	if (x1 != -1 && Y1 != -1){
		cout << "? " << x1 << " " << Y1 << " " << x1 << " " << Y1 << endl;
		cout.flush();
		int x; cin >> x;
		if (x == 1){
			cout << "! " << x1 << " " << Y1 << " " << x2 << " " << Y2 << endl;
			cout.flush();
			return 0;
		}
		cout << "! " << x2 << " " << Y1 << " " << x1 << " " << Y2 << endl;
		cout.flush();
		return 0;
	}
	if (x1 == -1){
		int l = 1, r = n;
		while (l < r){
			int mid = l + r >> 1;
			cout << "? " << 1 << " " << Y1 << " " << mid << " " << Y1 << endl;
			cout.flush();
			int x; cin >> x;
			if (x & 1) r = mid;
			else l = mid + 1;
		}
		cout << "! " << l << " " << Y1 << " " << l << " " << Y2 << endl;
		cout.flush();
		return 0;
	}
	if (Y1 == -1){
		int l = 1, r = n;
		while (l < r){
			int mid = l + r >> 1;
			cout << "? " << x1 << " " << 1 << " " << x1 << " " << mid << endl;
			cout.flush();
			int x; cin >> x;
			if (x & 1) r = mid;
			else l = mid + 1;
		}
		cout << "! " << x1 << " " << l << " " << x2 << " " << l << endl;
		cout.flush();
		return 0;
	}
	return 0;
}