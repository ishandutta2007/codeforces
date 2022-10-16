#include <bits/stdc++.h>
using namespace std;
 
int n;
char s[1100000];
int cnt[30];

set<pair<int, char>> ss;

int main() {
	scanf("%d", &n);
	scanf("%s", s);
	
	for (int i = 0; i < n; i++) cnt[s[i]-'a']++;
	for (int i = 0; i < 26; i++) for (int j = 0; j < cnt[i]; j++) printf("%c", i+'a');



}