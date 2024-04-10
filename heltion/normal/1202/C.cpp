//Author: Heltion
//Date: 08-07-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
char s[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int T;
	for(cin >> T; T; T -= 1){
		cin >> s;
		int cw = 0, cd = 0;
		int ma = 0, md = 0, mw = 0, ms = 0;
		int sa = 0, sd = 0, sw = 0, ss = 0;
		for(int i = 0; s[i]; i += 1){
			if(s[i] == 'W') cw += 1;
			if(s[i] == 'S') cw -= 1;
			if(s[i] == 'D') cd += 1;
			if(s[i] == 'A') cd -= 1;
			mw = max(mw, cw);
			ms = min(ms, cw);
			md = max(md, cd);
			ma = min(ma, cd);
			sw = max(sw, cw - ms);
			ss = max(ss, mw - cw);
			sd = max(sd, cd - ma);
			sa = max(sa, md - cd);
		}
		//cout << sw << " " << ss << " " << sa << " " << sd << "\n";
		LL x[2], y[2];
		x[0] = max(sw, ss);
		x[1] = max(LL(sw or ss), x[0] - !(sw == ss));
		y[0] = max(sd, sa);
		y[1] = max(LL(sd or sa), y[0] - !(sd == sa));
		//cout << x[0] << " " << x[1] << " " << y[0] << " " << y[1] << "\n";
		LL ans = min((x[0] + 1) * (y[1] + 1), (x[1] + 1) * (y[0] + 1));
		cout << ans << "\n";
	}
	return 0;
}