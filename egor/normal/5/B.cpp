#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	char buf[2000];
	vector <string> t;
	while (true) {
		buf[0] = 1;
		gets(buf);
		if (buf[0] == 1)
			break;
		t.push_back(buf);
	}
	unsigned l = 0;
	int n = t.size();
	for (int i = 0; i < n; i++)
		l = max(l, t[i].length());
	for (int i = 0; i < l + 2; i++)
		printf("*");
	printf("\n");
	bool left = false;
	for (int i = 0; i < n; i++) {
		bool needchange = ((l - t[i].length()) % 2 != 0);
		printf("*");
		int sp = l - t[i].length();
		for (int j = 0; j < sp / 2; j++)
			printf(" ");
		if (left && needchange)
			printf(" ");
		printf("%s", t[i].c_str());			
		for (int j = 0; j < sp / 2; j++)
			printf(" ");
		if (!left && needchange)
			printf(" ");
		printf("*");
		if (needchange && t[i].length() != 0)
			left = !left;
		printf("\n");
	}
	for (int i = 0; i < l + 2; i++)
		printf("*");
	printf("\n");
}