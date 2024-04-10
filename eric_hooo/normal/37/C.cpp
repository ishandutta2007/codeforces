#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

pii a[1010];
string ans[1010];

string add(string &s){
	if (s.length() == 0) return "0";
	int n = s.length();
	s[n - 1]++;
	for (int i = n - 1; i >= 1; i--){
		if (s[i] == '2') s[i] = '0', s[i - 1]++;
		else break;
	}
	if (s[0] == '2') return "-1";
	return s;
}

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i].fi);
		a[i].se = i;
	}
	sort(a, a + n);
	string s;
	int last = 1;
	for (int i = 0; i < n; i++){
		int x = a[i].fi, id = a[i].se;
		s = add(s);
		if (s == "-1"){
			printf("NO\n");
			return 0;
		}
		if (x > last){
			for (int i = 0; i < x - last; i++){
				s.push_back('0');
			}
			last = x;
		}
		ans[id] = s;
	}
	printf("YES\n");
	for (int i = 0; i < n; i++){
		printf("%s\n", ans[i].c_str());
	}
	return 0;
}