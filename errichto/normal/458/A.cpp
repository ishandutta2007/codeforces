#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
//#include<ctime>
//#include<cstdlib>
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
const int inf=1e9+5, nax=1e5+5;

char s1[nax], s2[nax];

int main()
{
	ios_base::sync_with_stdio(0);
	//srand(time(NULL));
	
	cin >> s1 >> s2;
	int d1 = strlen(s1), d2 = strlen(s2);
	/*int d1, d2;
	cin >> d1 >> d2;
	RE(i, d1) {
		s1[i] = '0';
		if (rand()%2) s1[i] = '1';
	}
	RE(i, d2) {
		s2[i] = '0';
		if (rand()%2) s2[i] = '1';
	}*/
	bool zamiana = false;
	if(d1 < d2) {
		swap(s1, s2);
		swap(d1, d2);
		zamiana = true;
	}
	if(d1 > d2) {
		for(int i = d2-1; i >= 0; --i)
			s2[i + d1-d2] = s2[i];
		for(int i = 0; i < d1-d2; ++i) s2[i] = '0';
	}
	int d = d1;
	/*RE(i, d) cout << s1[i];
	cout << "\n";
	RE(i, d) cout << s2[i];
	cout << "\n";*/
	if(zamiana) RE(i, d) swap(s1[i], s2[i]);
	int a = 0, b = 0;
	int M = 100 * 1000 * 1000;
	RE(i, d) {
		int c = 0;
		if(s1[i] == '1') c++;
		if(s2[i] == '1') c--;
		b += a;
		c += a;
		a = b;
		b = c;
		//cout << a << " " << b << "\n";
		if(abs(a) + abs(b) > M) break;
	}
	while(true) {
		if(a >= 0 && b >= 0) {
			if(a+b > 0) cout << ">";
			else cout << "=";
			return 0;
		}
		if(a <= 0 && b <= 0) {
			if(a+b < 0) cout << "<";
			else cout << "=";
			return 0;
		}
		if(a == 0 || b == 0) {
			if(a+b > 0) cout << ">";
			else if(a+b==0) cout << "=";
			else cout << "<";
			return 0;
		}
		if(abs(a) >= abs(b)){
			if(a > 0) cout << ">";
			else cout << "<";
			return 0;
		}
		int pom = a+b;
		b = a;
		a = pom;
	}
	return 0;
}