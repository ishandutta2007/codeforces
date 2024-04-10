// #bitset #math 

#include <bitset>
#include <iostream>
const int N = 100001, LIM = 7001;
std::bitset<LIM> uoc[LIM], boi[LIM], set[N];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	for (int i = 1; i < LIM; ++i)
		for (int j = 1; i * j < LIM; ++j)
			uoc[i * j].flip(i);
	std::bitset<LIM> check;
	for (int i = 2; i * i < LIM; ++i)
		for (int j = 1; i * i * j < LIM; ++j)
			check[i * i * j] = 1;
	for (int i = 1; i < LIM; ++i) if (check[i] == 0)
		for (int j = 1; i * j < LIM; ++j)
			boi[j].flip(i * j);
	int n, q; std::cin >> n >> q;
	for (int i = 1; i <= q; ++i)
	{
		int t; std::cin >> t;
		switch (t)
		{
			case 1:
			{
				int x, v; std::cin >> x >> v;
				set[x] = uoc[v];
				break;
			}
			case 2:
			{
				int x, y, z; std::cin >> x >> y >> z;
				set[x] = set[y] ^ set[z];
				break;
			}
			case 3:
			{
				int x, y, z; std::cin >> x >> y >> z;
				set[x] = set[y] & set[z];
				break;
			}
			case 4:
			{
				int x, v; std::cin >> x >> v;
				std::cout.put((set[x] & boi[v]).count() & 1 ? '1' : '0');
				break;
			}
		}
	}
	return 0;
}