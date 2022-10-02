#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


int n;
int x, y, r;
string f, g;


string chislo(int a) {
	string ans;
	if (a == 0) {
		ans += '0';
		return ans;
	}
	while (a > 0) {
		ans += '0' + a % 10;
		a /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}


int main() {	
	cin >> n;
	f = "";
	g = "";
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> r;
		x /= 2;
		y /= 2;
		string a = "";
        string b = "";
        a += "(((1-abs((t-";
        a += chislo(i);
        a += ")))+abs((abs((t-";
        a += chislo(i);
        a += "))-1)))*";
        a += chislo(x);
        a += ")";
        b += "(((1-abs((t-";
        b += chislo(i);
        b += ")))+abs((abs((t-";
        b += chislo(i);
        b += "))-1)))*";
        b += chislo(y);
        b += ")";
        if (f.empty()){
            f += a;
        } else {
            f = "(" + f;
            f += "+";
            f += a;
            f += ")";
        }
        if (g.empty()){
            g += b;
        } else {
            g = "(" + g;
            g += "+";
            g += b;
            g += ")";
        }
	}
	cout << f << endl;
	cout << g << endl;
	return 0;
}