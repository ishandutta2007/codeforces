#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const int ms = 1e3+5, sigma = 26;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
typedef vector<int> vi;

char s[ms];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	scanf("%d %s", &n, s);
	for(int i = 1; i <= n; i++) {
		if(n % i == 0) reverse(s, s + i);
	}
	printf("%s", s);
	return 0;
}