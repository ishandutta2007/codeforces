#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
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
#define all(w) w.begin(),w.end()
const int inf=1e9+5,nax=1e6+5;

int maka[nax], cena[nax], ma[nax], smak[nax];
int dp[12][1005];

int main()
{
	ios_base::sync_with_stdio(0);

	int jego, m;
	cin >> jego >> m >> maka[0] >> cena[0];

	RI(i, m) cin >> ma[i] >> smak[i] >> maka[i] >> cena[i];

	RE(i, 12) RE(j, 1000) dp[i][j] = -inf;
	dp[0][jego] = 0;

	RI(rodz, m) {
		RE(zostalo, jego + 1) RE(bierz, 105) {
			if(bierz * smak[rodz] <= ma[rodz] && bierz * maka[rodz] <= zostalo)
				maxi(dp[rodz][zostalo - bierz * maka[rodz]], dp[rodz - 1][zostalo] + bierz * cena[rodz]);
		}
	}
	int res = 0;
	RE(zostalo, jego + 1) maxi(res, dp[m][zostalo] + (zostalo / maka[0]) * cena[0]);
	cout << res;
	
	return 0;
}