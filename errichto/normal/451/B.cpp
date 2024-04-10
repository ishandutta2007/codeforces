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

int n;
int t[nax];

bool F() {
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	t[0] = 0;
	t[n + 1] = inf;
	RI(i, n) cin >> t[i];
	n += 2;
	int start = -1, end = -1;
	RE(i, n-1) if(t[i+1] < t[i]) {
		start = i;
		int x = start;
		while(t[x+1] < t[x]) x++;
		end = x;
		break;
	}
	for(int i = start; i <= end; ++i) {
		int b = end - (i-start);
		if(i < b) swap(t[i], t[b]);
	}
	RE(i, n-1) if(t[i+1] < t[i]) {
		cout << "no";
		return 0;
	}
	cout << "yes\n";
	if(start == -1) cout << "1 1";
	else cout << start << " " << end;
	return 0;
}