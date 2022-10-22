#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
#define fr first
#define sc second
using pi2 = pair<int, int>;
typedef pair<pi2, pi2> pi4;
using ll = long long;
using pl2 = pair<ll, ll>;



void Main(){
	int sl, n; cin >> sl >> n;
	string s; cin >> s;
	while (n--){
		string str = "";
		for (int i = 0; i < sl; i++){
			if (i+1 < sl){
				if (s[i] == 'B' && s[i+1] == 'G'){ str += "GB"; i += 1; }
				else{ str += s[i]; }
			}
			else{ str += s[i]; }
		}
		s = str;
	}
	cout << s;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}