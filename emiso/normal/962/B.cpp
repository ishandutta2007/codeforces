#include <bits/stdc++.h>

using namespace std;

int n, a, b, tot;
char s[200200];
string str;

vector<int> stud;

int main() {
	scanf("%d %d %d %s", &n, &a, &b, s);
	str = s;
	
	int co = 0;
	for(int i = 0; i < n; i++) {
		if(str[i] == '.') co++;
		else {
			if(co) stud.push_back(co);
			co = 0;
		}
	}
	if(co) stud.push_back(co);
	
	for(int x : stud) {
		int last = (a > b) ? 1 : 0;
		for(int i = 0; i < x; i++) {
			if(last) {
				if(a) {
					a--;
					tot++;
				}
			} else {
				if(b) {
					b--;
					tot++;
				}
			}
			last = (last == 0) ? 1 : 0;
		}
	}
	
	printf("%d\n", tot);
	return 0;
}