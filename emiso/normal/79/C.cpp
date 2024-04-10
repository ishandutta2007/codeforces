#include <bits/stdc++.h>

using namespace std;

vector<int> end_[200020];
map<int, int> open;

int n, len, pos;
string pat, s;

int main() {
	cin >> pat >> n;
	while(n--) {
		cin >> s;
		
		int p = -1;
		while(1) {
			p = pat.find(s, p + 1);
			if(p == -1) break;
			
			end_[p].push_back(p + s.size() - 1);
			open[p + s.size() - 1]++;
		}
	}
	
	open[pat.size()]++;
	
	for(int i = 0; i < pat.size(); i++) {
		if(i) for(int x : end_[i-1]) {
			open[x]--;
			if(open[x] == 0) open.erase(x);
		}	
		int l = (*(open.begin())).first - i;
		if(len < l) {
			len = l;
			pos = i;
		}
	}
	
	printf("%d %d\n", len, pos);
	
}