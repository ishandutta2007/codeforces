#include <bits/stdc++.h>
using namespace std;

char buf[100010];

string read(){
	scanf("%s", buf);
	return buf;
}

int t[30];

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		string s = read();
		int n = s.length();
		memset(t, 0, sizeof(t));
		for (int i = 0; i < n; i++){
			t[s[i] - 'a']++;
		}
		string res = "";
		for (int i = 0; i < 26; i++){
			for (int j = 0; j < t[i]; j++) res.push_back(char(i + 'a'));
		}
		string tmp = res;
		reverse(tmp.begin(), tmp.end());
		if (tmp == res) printf("-1\n");
		else printf("%s\n", res.c_str());
	}
	return 0;
}