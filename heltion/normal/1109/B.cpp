#include<bits/stdc++.h>
using namespace std;
#define maxn 6000
char s[maxn];
void no(){
	cout << "Impossible";
	exit(0);
}
unordered_map<char, int> mp;
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	int n = strlen(s);
	for(int i = 0; i < n; i += 1) mp[s[i]] += 1;
	for(const auto &p : mp) if(p.second >= n - 1) no();
	for(int i = 1; i < n; i += 1){
		int ok = 1;
		for(int j = 0; j < n and ok; j += 1) if(s[(i + j) % n] != s[(i - 1 - j + n) % n]) ok = 0;
		int sok = 0;
		for(int j = 0; j < n and not sok; j += 1) if(s[(i + j) % n] != s[j]) sok = 1;
		if(ok && sok){
			cout << 1;
			return 0;
		}
	}
	cout << 2;
}