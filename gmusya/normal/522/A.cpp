#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map <string, pair <vector <string>, pair <int, bool>>> kek;
int answer = 0;

void dfs(string s) {
	kek[s].second.second = true;
	for (int i = 0; i < kek[s].first.size(); i++) 
		if (kek[kek[s].first[i]].second.second == false) {
			kek[kek[s].first[i]].second.first = kek[s].second.first + 1;
			dfs(kek[s].first[i]);
			answer = max(answer, kek[kek[s].first[i]].second.first);
		}
}

int main() {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		for (int i = 0; i < s1.size(); i++)
			if (s1[i] >= 'A' && s1[i] <= 'Z')
				s1[i] += 'a' - 'A';
		for (int i = 0; i < s3.size(); i++)
			if (s3[i] >= 'A' && s3[i] <= 'Z')
				s3[i] += 'a' - 'A';
		kek[s1].first.push_back(s3);
		kek[s3].first.push_back(s1);
	}
	dfs("polycarp");
	cout << answer + 1;
	return 0;
}