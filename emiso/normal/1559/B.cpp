#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %s", &n, s); str = s;

	vector<int> pos;
    for(int i = 0; i < n; i++) {
		if(str[i] != '?') pos.push_back(i);
    }
	if(!pos.empty()) {
		if(pos[0] > 0) for(int i = 0; i < pos[0]; i++) {
			char c = str[pos[0]], oc = (c == 'R') ? 'B' : 'R';
			str[i] = (i % 2 == pos[0] % 2) ? c : oc;
		}
		if(pos.back() < n - 1) for(int i = pos.back(); i < n; i++) {
			char c = str[pos.back()], oc = (c == 'R') ? 'B' : 'R';
			str[i] = (i % 2 == pos.back() % 2) ? c : oc;
		}
	} else {
		for(int i = 0; i < n; i++) str[i] = (i % 2) ? 'R' : 'B';
	}

	for(int i = 0; i + 1 < (int)pos.size(); i++) {
		for(int j = pos[i] + 1; j < pos[i+1]; j++) {
			char c = str[pos[i]], oc = (c == 'R') ? 'B' : 'R';
			str[j] = (j % 2 == pos[i] % 2) ? c : oc;
		}
    }

    printf("%s\n", str.c_str());
    if(--t) goto st;
    return 0;
}