//Author: Heltion
//Date: 07-24-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int q;
	for(cin >> q; q; q -= 1){
		int n;
		LL Zuo = -1e5, Shang = 1e5, You = 1e5, Xia = -1e5;
		for(cin >> n; n; n -= 1){
			LL x, y, fz, fs, fy, fx;
			cin >> x >> y >> fz >> fs >> fy >> fx;
			if(fz == 0) Zuo = max(Zuo, x);
			if(fs == 0) Shang = min(Shang, y);
			if(fy == 0) You = min(You, x);
			if(fx == 0) Xia = max(Xia, y);
		}
		if(Zuo <= You and Shang >= Xia) cout << "1 " << Zuo << "  " << Xia << "\n";
		else cout << "0\n";
	}
	return 0;
}