#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int p, x, y;
	cin >> p >> x >> y;
	for(int sh = 0; sh < 10000; sh++){
		for(int uh = 0; uh < 500; uh++){
			if(x + 100*sh - 50*uh < y)continue;
			int s = ((x + 100*sh - 50*uh)/50)%475;
			for(int j = 0; j < 25; j++){
				s = (s*96 + 42)%475;
				if(s + 26 == p){
					cout << sh << '\n';
					exit(0);
				}
			}
		}
	}
	assert(false);

	return 0;
}