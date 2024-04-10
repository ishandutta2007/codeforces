#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;


unsigned long long choose[110][51];
unsigned long long difficulty;

int bits[1100];
int bc;

void convert(unsigned long long dd) {
	while (dd) {
		//printf("%llu\n", dd);
		bits[bc++] = dd % 6;
		dd /= 6;
	}
}

void solve() {
	scanf("%llu", &difficulty);

	convert(difficulty);

	int size = 1 + 2*(bc) + 1;
	int cornerx = 1, cornery = 1;
	
	vector< pair< pii, pii> > walls;
	for (int i = 0; i < bc; i++) {
		walls.emplace_back( pii{cornerx-1, cornery+1}, pii{cornerx, cornery+1});
		walls.emplace_back( pii{cornerx-1, cornery+2}, pii{cornerx, cornery+2});
		walls.emplace_back( pii{cornerx+1, cornery-1}, pii{cornerx+1, cornery});
		walls.emplace_back( pii{cornerx+2, cornery-1}, pii{cornerx+2, cornery});

		//walls.emplace_back( pii{cornerx-2, cornery+1}, pii{cornerx-1, cornery+1});
		
		walls.emplace_back( pii{cornerx-2, cornery+2}, pii{cornerx-1, cornery+2});
		walls.emplace_back( pii{cornerx-2, cornery+3}, pii{cornerx-1, cornery+3});
		//walls.emplace_back( pii{cornerx-1, cornery+3}, pii{cornerx-1, cornery+4});
		//walls.emplace_back( pii{cornerx+0, cornery+3}, pii{cornerx+0, cornery+4});
		
		//walls.emplace_back( pii{cornerx+1, cornery+3}, pii{cornerx+1, cornery+4});

		//walls.emplace_back( pii{cornerx+1, cornery-2}, pii{cornerx+1, cornery-1});
		
		walls.emplace_back( pii{cornerx+2, cornery-2}, pii{cornerx+2, cornery-1});
		walls.emplace_back( pii{cornerx+3, cornery-2}, pii{cornerx+3, cornery-1});
		//walls.emplace_back( pii{cornerx+3, cornery-1}, pii{cornerx+4, cornery-1});
		//walls.emplace_back( pii{cornerx+3, cornery+0}, pii{cornerx+4, cornery-0});
		
		//walls.emplace_back( pii{cornerx+3, cornery+1}, pii{cornerx+4, cornery+1});

		if (i == bc-1) {
			walls.emplace_back( pii{cornerx+2,cornery+2}, pii{cornerx+3,cornery+2});
			walls.emplace_back( pii{cornerx+2,cornery+2}, pii{cornerx+2, cornery+3});
		}

		if (bits[i] == 0) {
			walls.emplace_back(pii{cornerx, cornery+2}, pii{cornerx, cornery+3});
			walls.emplace_back(pii{cornerx+1, cornery+2}, pii{cornerx+1, cornery+3});
		}
		else if (bits[i]) {
			if (bits[i] >= 3) bits[i]-=3;
			else {
				walls.emplace_back(pii{cornerx+1, cornery+2}, pii{cornerx+1, cornery+3}); 
			}

			if (bits[i] >= 1) bits[i]--;
			else {
				walls.emplace_back( pii{cornerx, cornery+2}, pii{cornerx, cornery+3} );
			}
		}

		if (bits[i]) bits[i]--;
		else {
			walls.emplace_back(pii{cornerx+2, cornery}, pii{cornerx+3, cornery});
		}
		walls.emplace_back(pii{cornerx+2, cornery+1}, pii{cornerx+3, cornery+1});

		cornerx += 2, cornery += 2;
	}

	printf("%d %d\n", size, size);

	vector< pair< pii, pii> > filtered;
	for (pair< pii, pii > pp : walls) {
		if (min(pp.first.first, min(pp.first.second, min(pp.second.first, pp.second.second))) < 1) continue;
		if (max(pp.first.first, max(pp.first.second, max(pp.second.first, pp.second.second))) > size) continue;
		filtered.push_back(pp);
	} 

	printf("%d\n", (int)filtered.size());
	for (pair< pii, pii > pp : filtered) {
		printf("%d %d %d %d\n", pp.first.first, pp.first.second, pp.second.first, pp.second.second);
	}
}


int main() {
    solve();
}