#include <bits/stdc++.h>
#define fi first
#define se second


using namespace std;

char s[300005];

vector <pair<int, int>> v;

int main() {
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < n;) {
		int j = i;
		while(j < n && s[i] == s[j])
			j++;
		v.push_back(make_pair(s[i] - 'A', j - i));
		i = j;
	}

	if(v.size() % 2 == 0) {
		printf("0");
		return 0;
	}

	int wsk1 = v.size() / 2 - 1;
	int wsk2 = v.size() / 2 + 1;

	if(v[v.size() / 2].se == 1) {
		printf("0");
		return 0;
	}

	while(wsk1 >= 0) {
		int ile = v[wsk1].se + v[wsk2].se;
		if(v[wsk1].fi != v[wsk2].fi || ile <= 2) {
			printf("0");
			return 0;
		}
		wsk1--;
		wsk2++;
	}

	printf("%d", v[v.size() / 2].se + 1);







	return 0;
}