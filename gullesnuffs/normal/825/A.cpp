#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ones = 0;
	rep(i,0,n){
		if(s[i] == '1'){
			++ones;
		}
		else{
			cout << ones;
			ones = 0;
		}
	}
	cout << ones << endl;
}