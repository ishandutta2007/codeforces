#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

int H,L;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>H>>L;
	double x = (double)((ll)L*L-(ll)H*H)/(2*H);
	cout<<setprecision(10)<<x;
}