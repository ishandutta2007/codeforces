#include <bits/stdc++.h>

using namespace std;

int main() {
	int flag = 0;
	string st1, st2;
	cin >> st1 >> st2;
	if (st1.size() != st2.size()) flag = 0;
	else {
		int ones1 = 0, ones2 = 0;
		for(int i = 0; i< st1.size();i++) {
			if(st1[i] == '1') ones1++;
			if(st2[i] == '1') ones2++;
		}
		if(ones1 == 0 && ones2) flag = 0;
		else if(ones1 && ones2 == 0) flag = 0;
		else flag = 1;
	}
	printf("%s\n",flag?"YES":"NO");
	return 0;
}