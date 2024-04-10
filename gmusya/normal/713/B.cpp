#include <iostream>
#include <vector>

using namespace std;

struct rectangle {
	int xl, xr, yb, yt;
};

int main() {
	int cnt = 0;
	int n;
	cin >> n;
	rectangle global, A, B;
	global.xl = global.yb = 1, global.xr = global.yt = n;
	int bin_xl = 1;
	int bin_xr = n;
	bool tf = false;
	while (true) {
		int bin_xm = (bin_xl + bin_xr) / 2;
		cout << "? " << global.xl << " " << global.yb << " " << bin_xm << " " << global.yt << endl;
		cnt++; if (cnt > 198) { cout << "! 0 0 0 0 0 0 0 0"; return 0; }
		cout.flush();
		int x, y;
		cin >> x;
		if (x == 1) {
			cout << "? " << bin_xm + 1 << " " << global.yb << " " << global.xr << " " << global.yt << endl;
			cnt++; if (cnt > 198) { cout << "! 0 0 0 0 0 0 0 0"; return 0; }
			cout.flush();
			cin >> y;
		}
		if (x == 1 && y == 1) {
			A.xl = global.xl, A.xr = bin_xm, A.yb = global.yb, A.yt = global.yt;
			B.xl = bin_xm + 1, B.xr = global.xr, B.yb = global.yb, B.yt = global.yt;
			tf = true;
			break;
		}
		if (bin_xl >= bin_xr) break;
		if (x == 0) bin_xl = bin_xm + 1;
		if (x >= 1) bin_xr = bin_xm - 1;
	}

	if (!tf) {
		int bin_yl = 1;
		int bin_yr = n;
		while (true) {
			int bin_ym = (bin_yl + bin_yr) / 2;
			cout << "? " << global.xl << " " << global.yb << " " << global.xr << " " << bin_ym << endl;
			cnt++; if (cnt > 198) { cout << "! 0 0 0 0 0 0 0 0"; return 0; }
			cout.flush();
			int x, y;
			cin >> x;
			if (x == 1) {
				cout << "? " << global.xl << " " << bin_ym + 1 << " " << global.xr << " " << global.yt << endl;
				cnt++; if (cnt > 198) { cout << "! 0 0 0 0 0 0 0 0"; return 0; }
				cin >> y;
			}
			if (x == 1 && y == 1) {
				A.xl = global.xl, A.xr = global.xr, A.yb = global.yb, A.yt = bin_ym;
				B.xl = global.xl, B.xr = global.xr, B.yb = bin_ym + 1, B.yt = global.yt;
				break;
			}
			if (bin_yl >= bin_yr) break;
			if (x == 0) bin_yl = bin_ym + 1;
			if (x >= 1) bin_yr = bin_ym - 1;
		}
	}

	{
		int bin_Axl_l = A.xl;
		int bin_Axl_r = A.xr;
		while (bin_Axl_l != bin_Axl_r) {
			int bin_Axl_m = (bin_Axl_l + bin_Axl_r + 1) / 2;
			cout << "? " << bin_Axl_m << " " << A.yb << " " << A.xr << " " << A.yt << endl;
			cnt++; if (cnt > 198) { cout << "! 0 0 0 0 0 0 0 0"; return 0; }
			cout.flush();
			int x;
			cin >> x;
			if (x) bin_Axl_l = bin_Axl_m;
			else bin_Axl_r = bin_Axl_m - 1;
		}
		A.xl = bin_Axl_l;
	}

	{
		int bin_Axr_l = A.xl;
		int bin_Axr_r = A.xr;
		while (bin_Axr_l != bin_Axr_r) {
			int bin_Axr_m = (bin_Axr_l + bin_Axr_r) / 2;
			cout << "? " << A.xl << " " << A.yb << " " << bin_Axr_m << " " << A.yt << endl;
			cnt++; if (cnt > 198) { cout << "! 0 0 0 0 0 0 0 0"; return 0; }
			cout.flush();
			int x;
			cin >> x;
			if (x) bin_Axr_r = bin_Axr_m;
			else bin_Axr_l = bin_Axr_m + 1;
		}
		A.xr = bin_Axr_r;
	}

	{
		int bin_Ayb_l = A.yb;
		int bin_Ayb_r = A.yt;
		while (bin_Ayb_l != bin_Ayb_r) {
			int bin_Ayb_m = (bin_Ayb_l + bin_Ayb_r + 1) / 2;
			cout << "? " << A.xl << " " << bin_Ayb_m << " " << A.xr << " " << A.yt << endl;
			cnt++; if (cnt > 198) { cout << "! 0 0 0 0 0 0 0 0"; return 0; }
			cout.flush();
			int x;
			cin >> x;
			if (x) bin_Ayb_l = bin_Ayb_m;
			else bin_Ayb_r = bin_Ayb_m - 1;
		}
		A.yb = bin_Ayb_l;
	}

	{
		int bin_Ayt_l = A.yb;
		int bin_Ayt_r = A.yt;
		while (bin_Ayt_l != bin_Ayt_r) {
			int bin_Ayt_m = (bin_Ayt_l + bin_Ayt_r) / 2;
			cout << "? " << A.xl << " " << A.yb << " " << A.xr << " " << bin_Ayt_m << endl;
			cnt++; if (cnt > 198) { cout << "! 0 0 0 0 0 0 0 0"; return 0; }
			cout.flush();
			int x;
			cin >> x;
			if (x) bin_Ayt_r = bin_Ayt_m;
			else bin_Ayt_l = bin_Ayt_m + 1;
		}
		A.yt = bin_Ayt_l;
	}

	{
		int bin_Bxl_l = B.xl;
		int bin_Bxl_r = B.xr;
		while (bin_Bxl_l != bin_Bxl_r) {
			int bin_Bxl_m = (bin_Bxl_l + bin_Bxl_r + 1) / 2;
			cout << "? " << bin_Bxl_m << " " << B.yb << " " << B.xr << " " << B.yt << endl;
			cnt++; if (cnt > 198) { cout << "! 0 0 0 0 0 0 0 0"; return 0; }
			cout.flush();
			int x;
			cin >> x;
			if (x) bin_Bxl_l = bin_Bxl_m;
			else bin_Bxl_r = bin_Bxl_m - 1;
		}
		B.xl = bin_Bxl_l;
	}

	{
		int bin_Bxr_l = B.xl;
		int bin_Bxr_r = B.xr;
		while (bin_Bxr_l != bin_Bxr_r) {
			int bin_Bxr_m = (bin_Bxr_l + bin_Bxr_r) / 2;
			cout << "? " << B.xl << " " << B.yb << " " << bin_Bxr_m << " " << B.yt << endl;
			cnt++; if (cnt > 198) { cout << "! 0 0 0 0 0 0 0 0"; return 0; }
			cout.flush();
			int x;
			cin >> x;
			if (x) bin_Bxr_r = bin_Bxr_m;
			else bin_Bxr_l = bin_Bxr_m + 1;
		}
		B.xr = bin_Bxr_r;
	}

	{
		int bin_Byb_l = B.yb;
		int bin_Byb_r = B.yt;
		while (bin_Byb_l != bin_Byb_r) {
			int bin_Byb_m = (bin_Byb_l + bin_Byb_r + 1) / 2;
			cout << "? " << B.xl << " " << bin_Byb_m << " " << B.xr << " " << B.yt << endl;
			cnt++; if (cnt > 198) { cout << "! 0 0 0 0 0 0 0 0"; return 0; }
			cout.flush();
			int x;
			cin >> x;
			if (x) bin_Byb_l = bin_Byb_m;
			else bin_Byb_r = bin_Byb_m - 1;
		}
		B.yb = bin_Byb_l;
	}

	{
		int bin_Byt_l = B.yb;
		int bin_Byt_r = B.yt;
		while (bin_Byt_l != bin_Byt_r) {
			int bin_Byt_m = (bin_Byt_l + bin_Byt_r) / 2;
			cout << "? " << B.xl << " " << B.yb << " " << B.xr << " " << bin_Byt_m << endl;
			cnt++; if (cnt > 198) { cout << "! 0 0 0 0 0 0 0 0"; return 0; }
			cout.flush();
			int x;
			cin >> x;
			if (x) bin_Byt_r = bin_Byt_m;
			else bin_Byt_l = bin_Byt_m + 1;
		}
		B.yt = bin_Byt_l;
	}
	cout << "! ";
	cout << A.xl << " " << A.yb << " " << A.xr << " " << A.yt << " ";
	cout << B.xl << " " << B.yb << " " << B.xr << " " << B.yt << endl;
	return 0;
}