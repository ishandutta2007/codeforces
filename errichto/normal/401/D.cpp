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
#define all(w) w.begin(),w.end()
const int inf=1e9+5,nax=1e6+5;

int t[20];
int count_dig[10];
ll r[5+(1<<18)][102];

int main()
{
	ios_base::sync_with_stdio(0);

	ll n;
	int mo;
	cin >> n >> mo;

	int N = 0;

	while(n){
		t[N]=n%10;
		count_dig[t[N]]++;
		n/=10;
		N++;
	}

	r[0][0] = 1;

	RE(mask,1<<N)
		RE(i,N) if(mask & (1<<i)) if (t[i] || mask != (1<<i)){
			int sm = mask - (1<<i);
			RE(j,mo)
				r[mask][(j*10+t[i])%mo] += r[sm][j];
		}
	ll res = r[-1+(1<<N)][0];
	RE(i, 10) for(int j = 2; j <= count_dig[i]; ++j) res /= (ll)j;
	cout << res;

	return 0;
}