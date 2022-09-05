#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define all(w) w.begin,w.end()
const int inf=1e9+5,nax=1e6+5;

bool Prime(int a) {
	for(int i = 2; i * i <= a; ++i)
		if(a % i == 0) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio;

	int n;
	cin >> n;
	for(int a = 2; a < n; ++a) {
		if(!Prime(a))if(!Prime(n - a)) {
			cout << a << " " << n - a;
			return 0;
		}
	}
	
	return 0;
}