#include <bits/stdc++.h>
using namespace std;

char buf[300010];

int main(){
	int n; scanf("%d", &n);
	scanf("%s", buf);
	string s = buf;
	int cnt = 0, tot = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == '(') cnt++;
		else if (s[i] == ')') cnt--;
		else tot++;
	}
	tot = (tot - cnt) / 2, cnt = 0;
	for (int i = 0; i < n - 1; i++){
		if (s[i] == '?'){
			if (tot) s[i] = '(', tot--;
			else s[i] = ')';
		}
		if (s[i] == '(') cnt++;
		if (s[i] == ')') cnt--;
		if (cnt < 1){
			printf(":(\n");
			return 0;
		}
	}
	if (tot) s[n - 1] = '(', tot--;
	else s[n - 1] = ')';
	if (s[n - 1] == ')' && cnt == 1) printf("%s\n", s.c_str());
	else printf(":(\n");
	return 0;
}