#include <bits/stdc++.h>
using namespace std;

char buf[1010];

int main(){
	int n; scanf("%d", &n);
	vector <int> v, vv;
	for (int i = 0; i < n; i++){
		scanf("%s", buf);
		int now = 0, x = 0, pd = 1;
		if (buf[0] == '-') now++, pd = -1;
		while (buf[now] != '.'){
			x = x * 10 + buf[now] - '0';
			now++;
		}
		int pp = 1;
		now++;
		for (int i = 0; i < 5; i++){
			if (buf[now + i] != '0') pp = 0;
		}
		v.push_back(x * pd + (pd == -1 && !pp ? -1 : 0)), vv.push_back(pp);
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++){
		sum += v[i];
	}
	for (int i = 0; i < v.size(); i++){
		if (vv[i]) continue;
		if (sum < 0) v[i]++, sum++;
	}
	for (int i = 0; i < v.size(); i++){
		printf("%d\n", v[i]);
	}
	return 0;
}