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
const int inf=1e9+5, nax=1e3+5;

char s[nax];
int n, k;

bool inRange(int a) {
	return 0 <= a && a <= n-1;
}

bool inBigRange(int a) {
	return 0 <= a && a <= n-1 + k;
}

int F(int koniec) {
	int left = koniec, right = koniec + 1;
	while(true) {
		if(  
					(inRange(left) && inRange(right) && s[left] == s[right])
					||
					(inBigRange(left) && inBigRange(right) && !inRange(right))
		)
			{
				left--;
				right++;
			}
		else
			{
				return right-left-1;
			}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> s >> k;
	n = strlen(s);
	
	int res = 0;
	
	RE(koniec, 200) RI(d, koniec + 1) {
		int left = koniec - d + 1;
		bool ok = true;
		for(int i = left; i <= koniec; ++i)
			if(!(
			(inRange(i) && inRange(i+d) && s[i] == s[i+d])
			||
			(inBigRange(i) && inBigRange(i+d) && !inRange(i+d))
			))
				ok = false;
		if(ok) maxi(res, 2*d);
	}
	
	cout << res;
	
	return 0;
}