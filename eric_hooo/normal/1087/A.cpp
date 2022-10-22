#include <bits/stdc++.h>
using namespace std;

char buf[100];
string s;

int main(){
	scanf("%s", buf), s = buf;
	int n = s.length(), now = (n - 1) / 2, cnt = 1;
	string res;
	while (0 <= now && now < n){
		res.push_back(s[now]);
		now += (cnt & 1 ? 1 : -1) * cnt;
		cnt++;
	}
	printf("%s\n", res.c_str());
	return 0;
}