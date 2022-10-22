#include <bits/stdc++.h>
using namespace std;

void print(int x){
	string s = "";
	while (x){
		x--;
		s += char(x % 26 + 'A');
		x /= 26;
	}
	reverse(s.begin(), s.end());
	printf("%s", s.c_str());
}

int main(){
	char s[110];
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%s", s);
		int len = strlen(s);
		bool pd = 0;
		for (int i = 1; i < len - 1; i++){
			if (isalpha(s[i]) && isdigit(s[i - 1]) && isdigit(s[i + 1])){
				pd = 1;
				break;
			}
		}
		if (pd){
			int r = 0, c = 0;
			pd = 0;
			for (int i = 1; i < len; i++){
				if (isdigit(s[i])){
					if (pd) c = c * 10 + s[i] - '0';
					else r = r * 10 + s[i] - '0';
				}
				else pd = 1;
			}
			print(c), printf("%d\n", r);
			continue;
		}
		int r = 0, c = 0;
		for (int i = 0; i < len; i++){
			if (isdigit(s[i])) r = r * 10 + s[i] - '0';
		}
		for (int i = 0; i < len; i++){
			if (!isdigit(s[i])) c = c * 26 + s[i] - 'A' + 1;
			else break;
		}
		printf("R%dC%d\n", r, c);
	}
	return 0;
}