#include <bits/stdc++.h>
using namespace std;

char buf[1000010];

string read(){
	scanf("%s", buf);
	return buf;
}

int sum[500010][2];
int all;

int main(){
	int n;
	scanf("%d", &n);
	int maxj = 0;
	for (int i = 0; i < n; i++){
		string s = read();
		int tot = 0, m = s.length();
		int minj = 0;
		for (int j = 0; j < m; j++){
			if (s[j] == '(') tot++;
			else tot--;
			minj = min(minj, tot);
		}
//		cout << "  " << minj << " " << tot << endl;
		if (minj == 0 && tot == 0) all++;
		else if (minj < 0 && tot == minj) sum[-minj][0]++;
		else if (minj == 0 && tot > 0) sum[tot][1]++;
		maxj = max(maxj, m);
	}
	int res = all / 2;
	for (int i = 0; i <= maxj; i++){
		res += min(sum[i][0], sum[i][1]);
	}
	printf("%d\n", res);
	return 0;
}