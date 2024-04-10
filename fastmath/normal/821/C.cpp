#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>


using namespace std;


mt19937 rnd(rand());
int inf = 1e9;
long long big_inf = 1e18;


int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	set <int> s;

	vector <pair <string, int> > a(2 * n);
	for (int i = 0; i < 2 * n; ++i){
		cin >> a[i].first;
		if (a[i].first == "add"){
			cin >> a[i].second;
		}
	}


	int ans = 0;
	int now = 1;
	vector <int> stack;
	for (int i = 0; i < 2 * n; ++i){
		string type = a[i].first;
		if (type != "add"){
			s.erase(now);

			if (stack.size() && stack[stack.size() - 1] != now){
				++ans;
				stack = {};
			}
			else{
				if (stack.size()) stack.pop_back();
			}
			
			++now;
		}
		else{
			stack.push_back(a[i].second);
		}
	}

	cout << ans;
	return 0;
}