#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

int reg[30], n;
vector <string> sol;

int solve(int i, int d)
{
	if (d == 0)
		return 0;

	for (int y = 0; y <= i; y++)
		for (int z = 0; z <= i; z++)
			for (int k = 0; k < 4; k++) {
				reg[i] = 0;
				reg[i] = reg[y] + ((1<<k)*reg[z]);

				if (k != 0) {
					char ss[100] = "";
					strcat(ss, "lea e?x, [e?x + !*e?x]");
					
					ss[5] = 'a'+i;
					ss[11] = 'a'+y;
					ss[16] = '0'+(1<<k);
					ss[19] = 'a'+z;
					
					sol.push_back(string(ss));
				} else {
					char ss[100] = "";
					strcat(ss, "lea e?x, [e?x + e?x]");
					
					ss[5] = 'a'+i;
					ss[11] = 'a'+y;
					ss[17] = 'a'+z;
					
					sol.push_back(string(ss));					
				}

				if (reg[i] == n)
					return 1;
				if (solve(i+1, d-1))
					return 1;
				sol.pop_back();
			}

	return 0;
}

int main()
{
	scanf("%d", &n);
	if (n == 1) {
		printf("0\n");
		return 0;
	}

	memset(reg, 0, sizeof(reg));
	reg[0] = 1;

	int d;
	for (d = 1; !solve(1, d); d++);
	
	printf("%d\n", d);
	assert(d == (int)sol.size());
	for (int i = 0; i < (int)sol.size(); i++)
		printf("%s\n", sol[i].c_str());

	return 0;
}