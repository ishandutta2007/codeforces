#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
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
const int inf=1e9+5,nax=1e5+5;

string sl[nax][2];
int p[nax];

bool Wiekszy(string a, string b) {
	RE(i, min(a.length(), b.length())) if(a[i] != b[i]) return a[i] > b[i];
	return a.length() > b.length();
}

int main()
{
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	RI(i, n) {
		cin >> sl[i][0] >> sl[i][1]; //scanf("%s%s", sl[i][0], sl[i][1]);
		if(Wiekszy(sl[i][0], sl[i][1]))
			swap(sl[i][0], sl[i][1]);
	}
	int f = 0;
	RI(i, n) {
		cin >> p[i]; //scanf("%d", &p[i]);
		if(i > 1) {
			if(Wiekszy(sl[ p[i] ][0], sl[ p[i - 1] ][f])) {
				//cout << sl[ p[i] ][0] << " " << sl[ p[i - 1] ][f] << "\n";
				f = 0;
			}
			else if(Wiekszy(sl[ p[i] ][1], sl[ p[i - 1] ][f])) f = 1;
			else {
				cout << "NO"; //printf("NO\n");
				return 0;
			}
		}
	}
	cout << "YES"; //printf("YES\n");

	return 0;
}