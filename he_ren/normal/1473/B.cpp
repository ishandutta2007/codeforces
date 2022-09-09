#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int gcd(int a,int b){ return b? gcd(b,a%b): a;}
inline int lcm(int a,int b){ return a / gcd(a,b) * b;}

void solve(void)
{
	string a,b;
	cin >> a >> b;
	
	int len = lcm(a.size(), b.size());
	string s,t;
	while((int)s.size() < len) s += a;
	while((int)t.size() < len) t += b;
	
	if(s == t) cout << s << endl;
	else cout << -1 << endl;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}