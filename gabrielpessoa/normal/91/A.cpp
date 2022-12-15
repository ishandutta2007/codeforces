#include <bits/stdc++.h>
using namespace std;

char s2[1000005];
char s1[10005];
int posV[10005][50];

int main() {
	scanf("%s %s", s1, s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	memset(posV, -1, sizeof(posV));
	for(int i = len1 - 1; i >= 0; i--) {
		for(int j = 0; j <= 'z' - 'a'; j++) {
			posV[i][j] = posV[i+1][j];
		}
		posV[i][s1[i]-'a'] = i;
	}
	int pos = 0;
	int act = 1;
	int vPos;
	for(int i = 0; i < len2; i++) {
		vPos = s2[i] - 'a';
		if(posV[0][vPos] == -1) {
			act = -1;
			break;
		}
		if(posV[pos][vPos] == -1) {
			pos = 0;
			act++;
		}
		pos = posV[pos][vPos] + 1;
	}
	printf("%d", act);
	return 0;
}