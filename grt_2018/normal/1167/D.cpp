#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 200*1000+1;
int n,r;
string s;
bool St[nax];
bool ans[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>s;
	St[r++]=0;
	ans[0]=0;
	for(int i=1; i<n;i++) {
		if(s[i]==')') {
			r--;
			ans[i] = St[r];
		}
		else {
			St[r] = 1-St[r-1];
			ans[i]=St[r];
			r++;
		}
	}
	for(int i=0; i<n;i++) {
		cout<<ans[i];
	}
}