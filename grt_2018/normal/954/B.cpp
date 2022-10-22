#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

int n;
char s[110];

int main() {
	scanf("%d%s",&n,s);
	for(int len=(n/2); len>0; len--) {
		bool ok=1;
		for(int j=0; j<len; j++) {
			if(s[j]!=s[j+len]) ok=0;
		}
		if(ok) {
			printf("%d",n-len+1);
			return 0;
		}
	}
	printf("%d",n);
}