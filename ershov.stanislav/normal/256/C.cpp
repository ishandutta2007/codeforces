#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
long long n, r, t, t2, b[7][2]={
		{1, 0},
		{4, 1},
		{16, 2},
		{82, 0},
		{82*82, 3},
		{15LL*15*15*15+1, 1},
		{(15LL*15*15*15+1)*(15LL*15*15*15+1), 2}
};
int main(){
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> t;
		for (int j=0; j<7; j++) if (t>=b[j][0]) t2=b[j][1];
		r^=t2;
	}
	if (r) cout << "Furlo"; else cout << "Rublo";
    return 0;
}