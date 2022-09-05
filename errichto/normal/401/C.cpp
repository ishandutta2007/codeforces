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

bool t[4005];

bool ok(int zeroes, int ones){
	if(zeroes > ones + 1 || ones > zeroes * 2 + 2){
		cout << -1;
		return 0;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);

	int zeroes, ones;
	cin >> zeroes >> ones;
	if(zeroes > ones + 1 || ones > zeroes * 2 + 2){
		cout << -1;
		return 0;
	}
	RE(_,2)
		if(ones > 2 * zeroes){
			cout << 1;
			ones--;
		}
	// ew. pierwsze jedynki
	while(ones + zeroes > 0){
		cout << 0;
		zeroes--;
		if(ones){
			cout << 1;
			ones--;
		}
		if(ones > 2 * zeroes){
			cout << 1;
			ones--;
		}
	}

	return 0;
}