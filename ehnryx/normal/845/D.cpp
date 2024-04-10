#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
const ll MOD = 1e9+7;
const int INF = 0x7f7f7f7f;
const ll INFLL = 0x7f7f7f7f7f7f7f7f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> speedlim;
	stack<bool> overtake;
	int n, s, type, curr;
	cin >> n;
	speedlim.push(INF);
	overtake.push(true);
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> type;
		if (type == 1) {
			cin >> curr;
			while (curr > speedlim.top()) {
				speedlim.pop();
				count++;
			}
		}
		else if (type == 2) {
			while (overtake.top() == false) {
				overtake.pop();
				count++;
			}
		}
		else if (type == 3) {
			cin >> s;
			if (s < curr) 
				count++;
			else 
				speedlim.push(s);
		}
		else if (type == 4) {
			overtake.push(true);
		}
		else if (type == 5) {
			speedlim.push(INF);
		}
		else if (type == 6) {
			overtake.push(false);
		}
	}
	cout << count << endl;

	return 0;
}