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



int main()
{
	ios_base::sync_with_stdio(0);
	
	int k;
	cin >> k;
	
	bool flaga = false;
	if(k >= 3) {
		flaga = true;
		k--;
	}
	
	cout << "+------------------------+\n";
	cout << "|";
	int nr = 1;
	RE(i, 11) {
		if(i * 3 + nr <= k) cout << "O";
		else cout << "#";
		cout << ".";
	}
	cout << "|D|)\n";
	
	nr = 2;
	cout << "|";
	RE(i, 11) {
		if(i * 3 + nr <= k) cout << "O";
		else cout << "#";
		cout << ".";
	}
	cout << "|.|\n";
	
	if(flaga) cout << "|O.......................|\n";
	else cout << "|#.......................|\n";
	
	cout << "|";
	nr = 3;
	RE(i, 11) {
		if(i * 3 + nr <= k) cout << "O";
		else cout << "#";
		cout << ".";
	}
	cout << "|.|)\n";
	cout << "+------------------------+";
	/*
	
	+------------------------+
|O.O.O.#.#.#.#.#.#.#.#.|D|)
|O.O.O.#.#.#.#.#.#.#.#.|.|
|O.......................|
|O.O.#.#.#.#.#.#.#.#.#.|.|)
+------------------------+
	*/
	return 0;
}