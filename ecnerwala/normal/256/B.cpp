/*
ID: he.andr1
PROG: PrB
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int edge(int n) {
	if(n > 0)  return n * n;
	return 0;
}

int corner(int out) {
	if(out > 0) return out * (out + 1) / 2;
	return 0;
}

int num(int n, int x, int y, int t) {
	int out = 1;
	out += t * (t + 1) * 2;
	out -= edge(t - (x - 0    ) + 1);
	out -= edge(t - (n + 1 - x) + 1);
	out -= edge(t - (y - 0    ) + 1);
	out -= edge(t - (n + 1 - y) + 1);
	out += corner(t - ((x - 0    ) + (y - 0    )) + 1);
	out += corner(t - ((x - 0    ) + (n + 1 - y)) + 1);
	out += corner(t - ((n + 1 - x) + (y - 0    )) + 1);
	out += corner(t - ((n + 1 - x) + (n + 1 - y)) + 1);
	return out;
}

int go(int n, int x, int y, int c) {
	for(int t = 0; ; t++) {
		if(num(n, x, y, t) >= c) {
			return t;
		}
	}

}

void io(istream &in, ostream &out) {
	int n, x, y, c;
	in >> n >> x >> y >> c;
	out << go(n, x, y, c) << '\n';
}

int main(){
	io(cin, cout);
	return 0;
}