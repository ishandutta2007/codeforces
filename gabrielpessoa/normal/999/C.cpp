#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const int ms = 4e5+5, sigma = 26;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
typedef vector<int> vi;

char s[ms];
bool removed[ms];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	scanf("%d %d %s", &n, &k, s);
	for(int i = 0; i < sigma; i++) {
		for(int j = 0; j < n && k; j++) {
			if(s[j] == i + 'a') {
				removed[j] = true;
				k--;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(!removed[i]) printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}