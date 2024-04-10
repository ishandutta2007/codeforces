#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define pii pair<int,int>
#define mp make_pair
#define st first
#define nd second
const int inf=1e9+5, nax=1e6+5;

pii znajdz(int a)
{
	RI(i,1000) RI(j,min(1000,i-1)) if(i*i+j*j==a) return mp(i,j);
	return mp(0,0);
}

int gcd(int a, int b) {
	if(a) return gcd(b%a, a);
	return b;
}

int main()
{
	ios_base::sync_with_stdio(0);

	int a, b;
	cin >> a >> b;

	int pom = gcd(a,b);

	pii p = znajdz(pom*pom);
	
	if(p.st == 0) {
		cout << "NO";
		return 0; 
	}

	cout << "YES\n";
	cout << "0 0\n";
	if(p.nd * (a/pom) != p.st * (b/pom)) {
		cout << p.st * (a/pom) << " " << p.nd * (a/pom) << "\n";
		cout << -p.nd * (b/pom) << " " << p.st * (b/pom);
		cout << "\n";
	}
	else {
		cout << p.st * (a/pom) << " " << p.nd * (a/pom) << "\n";
		cout << p.nd * (b/pom) << " " << -p.st * (b/pom);
		cout << "\n";
	}

	return 0;
}