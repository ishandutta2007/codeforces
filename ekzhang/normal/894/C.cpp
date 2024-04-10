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

#define MAXN 1013
int N;
int S[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	int K = S[0];
	for (int i = 0; i < N; i++) {
		if (S[i] % K) {
			cout << -1 << endl;
			return 0;
		}
		S[i] /= K;
	}

	cout << 2 * N << endl;
	for (int i = 0; i < N; i++) {
		cout << K << ' ' << K * S[i] << ' ';
	}

	cout.flush();
	return 0;
}