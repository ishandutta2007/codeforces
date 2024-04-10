#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e6+5;

char s[5];
bool jest[105];

bool isLit(char a) {
	return 'a' <= a && a <= 'z';
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	while(cin >> s) {
		int n = strlen(s);
		RE(i, n) if(isLit(s[i])) jest[ s[i] - 'a' ] = true;
	}
	int licz = 0;
	RE(i, 26) if(jest[i]) licz++;
	cout << licz;
	return 0;
}