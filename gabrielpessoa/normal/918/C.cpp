#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 1005;
const int MOD = 1E6;
const int DELTA = 1E5+2;
const double PI = atan(1)*4;
const double EPS = 8e-5;
const int INF = 0x3f3f3f3f;

string s;

int main() {
	cin >> s;
	int total = 0;
	for(int i = 0; i < s.size(); i++) {
		int livres = 0, start = 0;
		for(int j = i; j < s.size(); j++) {
			if(s[j] == '?') {
				livres++;
			} else if(s[j] == '(') {
				if(livres > start) {
					int pares = (livres - start + 1)/2;
					start += pares;
					livres -= pares;
				}
				start++;
			} else if(s[j] == ')') {
				if(start == 0) {
					if(livres == 0) break;
					livres--;
				} else {
					start--;
				}
			}
			if(livres >= start && (livres - start) % 2 == 0) {			
				//printf("posicao %d a %d temos Livres: %d e Start: %d\n", i, j, livres, start);
				total++;
			}
		}
	}
	printf("%d\n", total);
	return 0;
}