#include <bits/stdc++.h>

using namespace std;

char s[200020];
string str, ans;
vector<pair<char, int> > felix;

int main() {
	scanf("%s", s);
	str = s;
	
	for(char c : str) {
		if(felix.empty() || c != felix.back().first) {
			felix.emplace_back(c, 1);
		} else felix.back().second++;
	}
	
	for(int i = 0; i < felix.size(); i++) {
		int quant = min(felix[i].second, 2);
		if(quant == 2 && i + 1 < felix.size() && felix[i+1].second >= 2)
			felix[i+1].second = 1;
		
		for(int j = 0; j < quant; j++) printf("%c", felix[i].first);
	}
	
	puts("");
	return 0;
}