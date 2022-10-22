#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

int a,b,c;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>c;
	cout<<(LL)2*c+2*min(a,b)+(a!=b?1:0);
}