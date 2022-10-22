#include <bits/stdc++.h>
using namespace std;

char buf[100010];

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int n;
		scanf("%d", &n);
		scanf("%s", buf);
		string s = buf;
		if (s.size() < 2){
			printf("NO\n");
			continue;
		}
		if (s.size() == 2 && s[0] >= s[1]){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		printf("2\n");
		printf("%c ", s[0]);
		for (int i = 1; i < s.length(); i++){
			printf("%c", s[i]);
		}
		printf("\n");
	} 
	return 0;
}