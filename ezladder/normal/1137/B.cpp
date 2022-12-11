#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define x first
#define y second

using namespace std;

string s, t;

vector<int> z_function (const string& s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

int need[500007];
int need0[500007];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int cnt = 0, cnt2 = 0;
	cin >> s >> t;
	for (char c : s) if (c == '1') cnt++;
	for (int i = (int)t.size() - 1; i >= 0; i--){
		need[i] = need[i + 1] + (t[i] == '1');
		need0[i] = need0[i + 1] + (t[i] == '0');
	}
	int cnt00 = (int)s.size() - cnt;
	cnt2 = need[0];
	int cnt0 = need0[0];
	auto now = z_function(t + '#' + t);
	reverse(all(now));
	for (int i = 0; i < t.size() + 1; i++) now.pop_back();
	reverse(all(now));
	vector<int> ans;
	
	int pos = -1;
	for (int i = 0; i < s.size(); i++){
		if (pos == -1){
			if ((int)s.size() - i >= t.size() && cnt2 <= cnt && cnt0 <= cnt00){
				pos = 0;
			}
		} else {
			//cout << pos << ' ' << now[pos] << endl;
			if ((int)s.size() - i >= t.size() && now[pos] + pos == t.size()){
				if (cnt2 <= cnt && cnt0 <= cnt00){
					pos = 0;
				}
			}
		}
		//cout << pos << endl;
		if (pos == -1){
			if (cnt) ans.pb(1), cnt--; else ans.pb(0), cnt00--;
		} else {
			ans.pb(t[pos] - '0');
			cnt -= (t[pos] == '1');
			cnt00 -= (t[pos] == '0');
			pos++;
			if (pos == t.size()) pos = -1;
		}
	}

	for (int x : ans) cout << x;
}