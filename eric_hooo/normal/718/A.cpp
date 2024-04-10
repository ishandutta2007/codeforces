#include <bits/stdc++.h>
using namespace std;

char s[200010];
int t;

void add(int pos){
	s[pos]++;
	while (s[pos] > '9'){
		int nxt = s[pos - 1] == '.' ? pos - 2 : pos - 1;
		s[nxt]++, s[pos] = '0';
		pos = nxt, t--;
	}
}

int main(){
	int n; scanf("%d%d", &n, &t);
	s[0] = '0';
	scanf("%s", s + 1);
	int pd = 0, pos = -1;
	for (int i = 1; i <= n; i++){
		if (pd && s[i] >= '5'){
			pos = i; break;
		}
		pd |= s[i] == '.';
	}
	if (pos == -1){
		printf("%s\n", s + 1);
		return 0;
	}
	pos--, t--;
	while (t && s[pos] == '4') pos--, t--;
	if (s[pos] == '.') add(pos - 1);
	else add(pos);
	while (s[pos] == '0') pos--;
	if (s[pos] == '.') pos--;
	s[pos + 1] = '\0';
	printf("%s\n", s + (s[0] == '0'));
	return 0;
}