#include <bits/stdc++.h>

using namespace std;
#define result pair<int, bool>

map<string, int> id;
char str[100];
result ans[100];
int n;

result analyze(char* str, int i) {
	result ret(3, 1);
	char t[100], opt;
	int ind, cnt, pri = 0;
	bool lst = 0;
	while (*str) {
		if (!isspace(*str)) {
			if (*str == '(') {
				ind = 0;
				++str;
				cnt = 1 - (*str == ')') + (*str == '(');
				while (cnt) {
					t[ind++] = *str++;
					if (*str == '(') ++cnt; else
					if (*str == ')') --cnt;
				}
				t[ind] = 0;
				++str;
				ret.second &= analyze(t, i).second;
				lst = 0;
			} else if (isdigit(*str)) {
				while (isdigit(*str)) ++str;
				lst = 0;
			} else if (isalpha(*str)) {
				ind = 0;
				while (isalpha(*str)) t[ind++] = *str++;
				t[ind] = 0;
				auto it = id.find(t);
				if (it != id.end()) {
					if (!ans[it->second].second || pri > ans[it->second].first ||
							pri == ans[it->second].first && (opt == '-' || opt == '/'))
						ret.second = 0;
					pri = ans[it->second].first;
					if (ans[it->second].first < 3)
						ret.first = min(ret.first, pri);
					lst = 1;
				}
			} else {
				opt = *str;
				if (lst)
					ret.second &= pri >= (opt == '+' || opt == '-' ? 1 : 2);
				if (opt == '+' || opt == '-') pri = 1; else pri = 2;
				ret.first = min(ret.first, pri);
				++str;
			}
		} else ++str;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", str);
		if (str[1] == '\0') scanf("%s", str);
		scanf("%s", str);
		id[str] = i;
		scanf("%[^\n]", str);
		ans[i] = analyze(str, i);
	}
	scanf("\n%[^\n]", str);
	puts(analyze(str, n).second ? "OK" : "Suspicious");
	return 0;
}