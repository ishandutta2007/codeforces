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

const int nax = 110;
int n;
char s[nax];
int ans;

int main() {
	scanf("%d%s",&n,s);
	s[n] = s[n-1]; n++;
	for(int i=1; i<n;i++) {
		if(s[i]!=s[i-1]) {
			ans++; i++;
			//if(i==n-1) ans++;
		} else {
			ans++;
		}
	}
	printf("%d",ans);
}