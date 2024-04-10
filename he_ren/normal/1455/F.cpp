#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;

int d;
char s[MAXN];
string f[MAXN];

inline char get_mn(char c){ return c == 'a' || c == 'a' + d - 1? 'a': c - 1;}

void solve(void)
{
	int n;
	scanf("%d%d%s",&n,&d,s+1);
	
	f[1] = get_mn(s[1]);
	for(int i=2; i<=n; ++i)
	{
		f[i] = f[i-1] + s[i];
		swap(*(f[i].end() - 1), *(f[i].end() - 2));
		
		f[i] = min(f[i], f[i-1] + get_mn(s[i]));
		f[i] = min(f[i], f[i-2] + get_mn(s[i]) + s[i-1]);
		
		if(i > 2)
		{
			string tmp = f[i-2] + s[i];
			swap(*(tmp.end() - 1), *(tmp.end() - 2));
			tmp += s[i-1];
			f[i] = min(f[i], tmp);
		}
	}
	
	cout << f[n] << endl;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}