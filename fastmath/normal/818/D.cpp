#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>


using namespace std;


#define int long long
mt19937 rnd(rand());
int inf = 1e9;
int mod = 1e9 + 7;
int big_inf = 1e18;

int by_color[1000001];
int colors[100000];
bool used[1000001];
int n, a, c;



struct comp{
	bool operator () (const pair <int, int> &x, const pair <int, int> &y) const{
		return (x.first < y.first) || (x.first == y.first && x.second == a && y.second != a) || (x.first == y.first && x.second != a && y.second != a && x.second < y.second);
	}
};


signed main(){
	ios_base::sync_with_stdio(false);

	cin >> n >> a;

	set <pair <int, int>, comp > s;
	for (int i = 0; i < n; ++i){
		cin >> colors[i];
		s.insert({ 0, colors[i] });
	}

	for (int i = 0; i < n; ++i){
		c = colors[i];
		++by_color[c];

		if (!used[c]){
			s.erase({ by_color[c] - 1, c });
			s.insert({ by_color[c], c });
		}

		while (s.size() && s.begin()->first < by_color[a]){
			used[s.begin()->second] = true;
			s.erase(s.begin());
		}
	}

	if (s.size() == 1){
		if (s.begin() -> second == a)
			cout << -1;
		else
			cout << s.begin()->second;
	}
	else{
		s.erase(s.begin());
		cout << s.begin()->second;
	}

	return 0;
}