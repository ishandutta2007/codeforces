#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200*1000 + 10;
int n,p;
int a[nax];
int cnt[2 * nax];
multiset<int>rest;
vi ans;

void eval(int x) {
	//~ cout << "X : " <<x << "\n";
	for(int i = 0; i <= n; ++i) {
		cnt[i] = 0;
	}
	for(int i = 0; i < n; ++i) {
		cnt[max(0,a[i] - x)]++;
	}
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		sum = sum + cnt[i];
		//~ cout << (sum - i + p)%p << " ";
		rest.insert((sum - i + p)%p);
	}
	int con = (sum - (n-1) + p)%p;
	sum = 0;
	for(int i = 0; i < n; ++i) {
		sum = sum + cnt[i];
		int y = (p - (i%p))%p;
		//~ cout << y << " " << con << "\n";
		if( rest.find(y) == rest.end()) {
			ans.PB(x + i);
		}
		int y2 = (sum - i + p)%p;
		rest.erase(rest.find(y2));
		rest.insert((con - (i+1) + p)%p);
	}
}
	

int main() {_
	cin >> n >> p;
	int mx= 0 ;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		mx = max(mx,a[i]);
	}
	int start = max(1, mx - n + 1);
	eval(start);
	//~ for(int i = max(1, mx - n); i < mx; ++i) {
		//~ if(eval(i)) {
			//~ ans.PB(i);
		//~ }
	//~ }
	cout << (int)ans.size() << "\n";
	for(auto it : ans) {
		cout << it << " ";
	}
	
}