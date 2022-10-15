#include <bits/stdc++.h>
using namespace std;

#define error(arg...){vector<string>_v =split(#arg,',');err(_v.begin(),arg);}
vector<string> split(const string& s,char c){vector<string> v;stringstream ss(s);
string x;while(getline(ss,x,c))v.push_back(move(x));return v;}
void err(vector<string>::iterator it){}template<typename T,typename...Args>
void err(vector<string>::iterator it,T a, Args... args){cerr<<it->
substr((*it)[0]==' ',it->length())<<" = "<<a<<'\n';err(++it, args...);}

typedef long long LL;
const double PI = 4 * atan(1);

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	string s;
	cin >> s;
	int ans = 0;
	N = s.length();
	for (int i = 0; i < N; i++) {
		if (s[i] != 'Q') continue;
		for (int j = i + 1; j < N; j++) {
			if (s[j] != 'A') continue;
			for (int k = j + 1; k < N; k++) {

				if (s[k] != 'Q') continue;
				ans++;
			}
		}
	}

	cout<<ans << endl;
	return 0;
}