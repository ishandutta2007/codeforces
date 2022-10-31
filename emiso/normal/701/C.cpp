#include <bits/stdc++.h>

using namespace std;

int last[256], _count, l ,r=-1, ans = 0x7FFFFFFF,temp;

int main() {
	int n;
	string str;

	cin >> n >> str;

	for(int i=0;i<str.size();i++) {
		if(!last[str[i]]) {
			last[str[i]]--;
			_count++;
		}
	}

	while(r < (int)str.size()) {
		if(temp != _count) {
			r++;
			if(r == str.size()) break;
			if(last[str[r]] == -1)
				temp++;
			last[str[r]] = r;
		}
		else {
			ans = min(ans, r - l + 1);
			if(last[str[l]] == l) {
				temp--;
				last[str[l]] = -1;
			}
			l++;
		}
	}

	printf("%d\n",ans);

	return 0;
}