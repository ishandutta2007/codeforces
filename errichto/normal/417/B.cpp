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
#define pow(a) ((a)*(a))
const int inf=1e9+5, nax=1e5+5;

int t[nax];

int main()
{
	ios_base::sync_with_stdio(0);
	
	RE(i, nax) t[i] = -1;
	
	int n;
	cin >> n;
	
	RI(i, n) {
		int x, k;
		cin >> x >> k;
		if(t[k] < x-1) {
			cout << "NO";
			return 0;
		}
		maxi(t[k], x);
	}
	cout << "YES";
	return 0;
}