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
const int inf=1e9+5, nax=1e6+5;

bool ok[nax];

int main()
{
	ios_base::sync_with_stdio(0);
	
	int H, W;
	cin >> H >> W;
	RI(i, 1000) ok[i * i] = true;
	int N = 50;
	RI(a, N) RI(b, N) if(ok[(W-1) * pow(a) + pow(b)])
		RI(c, N) if(ok[(H-1) * pow(a) + pow(c)])
			RI(d, N) if(ok[(W-1) * pow(c) + pow(d)])
				if(ok[(H-1) * pow(b) + pow(d)]) {
					
					RI(_, H-1) {
						RI(nic, W-1) cout << a << " ";
						cout << b << "\n";
					}
					RI(nic, W-1) cout << c << " ";
					cout << d << "\n";
					return 0;
				}
				
	N = 100;
	RI(a, N) RI(b, N) if(ok[(W-1) * pow(a) + pow(b)])
		RI(c, N) if(ok[(H-1) * pow(a) + pow(c)])
			RI(d, N) if(ok[(W-1) * pow(c) + pow(d)])
				if(ok[(H-1) * pow(b) + pow(d)]) {
					
					RI(_, H-1) {
						RI(nic, W-1) cout << a << " ";
						cout << b << "\n";
					}
					RI(nic, W-1) cout << c << " ";
					cout << d << "\n";
					return 0;
				}
	return 0;
}