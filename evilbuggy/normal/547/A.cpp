#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 1e6 + 16;
int mp[N];

inline pair<int, int> find(int h, int x, int y, int m){
	memset(mp, -1, sizeof(mp));
	int ind = 0;
	while(true){
		if(mp[h] != -1)return {mp[h], ind - mp[h]};
		mp[h] = ind++;
		h = (x*1LL*h + y)%m;
	}
}

inline int getIndex(int h, int x, int y, int a, int period, int m){
	for(int i = 0; i < period; i++){
		if(h == a)return i;
		h = (x*1LL*h + y)%m;
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int m; cin>>m;
	int h1, a1, x1, y1;
	cin>>h1>>a1>>x1>>y1;
	int h2, a2, x2, y2;
	cin>>h2>>a2>>x2>>y2;
	int period1, offset1;
	int period2, offset2;
	{
		pair<int, int> tmp = find(h1, x1, y1, m);
		offset1 = tmp.first; period1 = tmp.second;
	}
	{
		pair<int, int> tmp = find(h2, x2, y2, m);
		offset2 = tmp.first; period2 = tmp.second;
	}
	int mx = max(offset1, offset2);
	for(int i = 0; i < mx; i++){
		if(h1 == a1 && h2 == a2){
			cout<<i<<'\n';
			exit(0);
		}
		h1 = (x1*1LL*h1 + y1)%m;
		h2 = (x2*1LL*h2 + y2)%m;
	}
	// cout<<offset1<<" "<<offset2<<'\n';
	// cout<<period1<<" "<<period2<<'\n';
	int ind1 = getIndex(h1, x1, y1, a1, period1, m);
	int ind2 = getIndex(h2, x2, y2, a2, period2, m);
	if(ind1 == -1 || ind2 == -1){
		cout<<-1<<'\n';
		exit(0);
	}
	ll lcm = period1*1LL*period2/__gcd(period1, period2);
	for(ll ind = ind1; ind < lcm; ind += period1){
		if(ind%period2 == ind2){
			cout<<mx + ind<<'\n';
			exit(0);
		}
	}
	cout<<-1<<'\n';

	return 0;
}