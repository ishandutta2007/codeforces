#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

int n,m,delta;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0; i<n;i++) {
		char c;
		cin>>c;
		if(c=='-') {
			delta--;
		}
		else {
			delta++;
		}
		m = min(m,delta);
	}
	cout<<-m+delta;
}