#include <bits/stdc++.h>
using namespace std;

const int mod = 1000003;

char input[2010];

vector <int> change(){
	vector <int> res;
	scanf("%s", input);
	char *now = input;
	int cnt = 1;
	while (*now != '\0'){
		if (*now >= '0' && *now <= '9'){
			while (isdigit(*now)) now++;
			res.push_back(cnt - 1), cnt = 0;
		} else {
			if ((*now == '*' || *now == '/') && (now == input || !isdigit(*(now - 1)))){
				printf("0\n");
				exit(0);
			}
			now++, cnt++;
		}
	}
	if (cnt != 0){
		printf("0\n");
		exit(0);
	}
	return res;
}

int main(){
	vector <int> v = change();
	int n = v.size();
	vector <int> dp(4000, 1);
	for (int i = n - 1; i >= 1; i--){
		dp.erase(dp.begin(), dp.begin() + v[i] + 1);
		for (int j = 1; j < dp.size(); j++){
			dp[j] = (dp[j] + dp[j - 1]) % mod;
		}
	}
	printf("%d\n", dp[v[0]]);
	return 0;
}