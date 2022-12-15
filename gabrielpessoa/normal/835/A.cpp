#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int SIZE = 35;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;


int main() {
	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int final1 = 2*t1 + v1*s;
	int final2 = 2*t2 + v2*s;
	if(final1 < final2) {
		puts("First");
	} else if(final2 < final1) {
		puts("Second");
	} else {
		puts("Friendship");
	}
	return 0;
}