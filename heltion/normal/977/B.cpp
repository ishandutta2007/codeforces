 #include<bits/stdc++.h>
 using namespace std;
 int main(){
	int N;
	scanf("%d", &N);
	char *s = new char [N + 1];
	scanf("%s", s);
	int n = strlen(s);
	int C[26 * 26];
	for(int i = 0; i < 26 * 26; i += 1) C[i] = 0;
	for(int i = 1; i < n; i += 1) C[s[i - 1] - 'A' + (s[i] - 'A') * 26] += 1;
	int ma = 0;
	for(int i = 0; i < 26 * 26; i += 1) ma = max(C[i], ma);
	for(int i = 0; i < 26 * 26; i += 1) if(C[i] == ma) return printf("%c%c", i % 26 + 'A', i / 26 + 'A'), 0;
 }