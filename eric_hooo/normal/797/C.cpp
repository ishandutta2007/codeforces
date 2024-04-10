#include <bits/stdc++.h>
using namespace std;

char s[100010];
char minj[100010];
int n;
vector <int> t;

int main(){
	scanf("%s", s);
	n = strlen(s);
	for (int i = n - 1; i >= 0; i--){
		minj[i] = s[i];
		if (i < n - 1) minj[i] = min(minj[i], minj[i + 1]);
	}
	string ans;
	for (int i = 0; i < n; i++){
		if (t.empty()) t.push_back(s[i]);
		else {
			while (t.size() && t.back() <= minj[i]) ans.push_back(t.back()), t.pop_back();
			t.push_back(s[i]);
		}
	}
	while (t.size()) ans.push_back(t.back()), t.pop_back();
	printf("%s\n", ans.c_str());
	return 0;
}