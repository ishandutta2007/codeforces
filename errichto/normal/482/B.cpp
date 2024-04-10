#include<iostream>
#include<algorithm>
#include<vector>
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
const int pot = 128 * 1024;

int tr[2 * pot + 5];
int res[nax];

int t[nax][3];

int F(int a, int b) {
	if(a > b) return 0;
	a += pot;
	b += pot;
	int s = 0;
	s = tr[a];
	if(a != b) s &= tr[b];
	while(a < b - 1) {
		if(a % 2 == 0) s &= tr[a + 1];
		if(b % 2) s &= tr[b-1];
		a /= 2;
		b/=2;
	}
	return s;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;
	RE(i, m) {
		int low, high, q;
		cin >> low >> high >> q;
		t[i][0] = low;
		t[i][1] = high;
		t[i][2] = q;
		low += pot;
		high += pot;
		tr[low] |= q;
		tr[high] |= q;
		while(low < high - 1) {
			tr[low + 1] |= q;
			tr[high - 1] |= q;
			low /= 2;
			high /= 2;
		}
	}
	RI(a, n) {
		int s = 0;
		for(int x = a + pot; x; x /= 2)
			s |= tr[x];
		res[a] = s;
	}
	RI(a, n) tr[a + pot] = res[a];
	for(int i = pot - 1; i; i--)
		tr[i] = tr[2*i] & tr[2*i+1];
	RE(i, m) {
		int low = t[i][0];
		int high = t[i][1];
		low += pot;
		high += pot;
		int s = tr[low] & tr[high];
		while(low < high - 1) {
			s &= tr[low + 1];
			s &= tr[high - 1];
			low /= 2;
			high /= 2;
		}
		if(s != t[i][2]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES\n";
	RI(a, n) cout << res[a] << " ";
		
	
	return 0;
}