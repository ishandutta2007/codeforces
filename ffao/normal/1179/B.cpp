#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


void generate(int n, int m, int off) {
	if (n == 0) return;

	printf("%d %d\n", off+1, 1);

	if (n == 1) {
		int cur = -1;
		for (int i = 1; i < m; i++) {
			int act = (cur+m)%m;
			printf("%d %d\n", off+1, act+1);

			if (cur < 0) cur = -cur;
			else cur = -cur-1;
		}
		return;
	}

	for (int i = 0; i < m; i++) {
		printf("%d %d\n", off+n, m-i);
		if (i < m-1) printf("%d %d\n", off+1, (i+1)+1);
	}

	generate(n-2, m, off+1);
}

int n,m;
void solve()
{
    scanf("%d %d", &n, &m);
    generate(n,m,0);
}


#include <fstream>


int main() {


    solve();
}