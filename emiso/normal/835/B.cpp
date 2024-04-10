#include <bits/stdc++.h>

using namespace std;

int k, ans, sum;
char s[100010]; string str;
vector<int> v;

int main() {
	scanf("%d %s", &k, s);
	str = s;
	
	for(int i = 0; i < str.size(); i++) {
		v.push_back(str[i] - '0');
		sum += (str[i] - '0');
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size() && sum < k; i++, ans++) {
		sum -= v[i];
		sum += 9;
	}
	
	printf("%d\n", ans);
	return 0;
}