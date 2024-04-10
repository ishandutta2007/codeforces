#include <algorithm>
#include <iostream>
const int N = 17, MASK = 1 << 16, RED = 121;
bool chk[MASK][RED];
char type[N];
int r[N], b[N], cr[MASK], cb[MASK], f[MASK][RED];
inline void mini(int &l, int r) { if (l > r) l = r; }
inline void maxi(int &l, int r) { if (l < r) l = r; }

int main()
{
	int n; std::cin >> n;
	int sumred = 0, sumblue = 0;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> type[i] >> r[i] >> b[i];
		sumred += r[i];
		sumblue += b[i];
	}
	int res = 1e9+7;
	chk[0][0] = true;
	for (int mask = 0; mask < 1 << n; ++mask)
		for (int red = 0; red <= n * (n - 1) / 2; ++red)
			if (chk[mask][red])
			{
				mini(res, std::max(sumred - red, sumblue - f[mask][red]));
				for (int i = 1; i <= n; ++i)
					if (!(mask >> i - 1 & 1))
					{
						int newmask = mask + (1 << i - 1);
						cr[newmask] = cr[mask] + (type[i] == 'R');
						cb[newmask] = cb[mask] + (type[i] == 'B');
						chk[newmask][red + std::min(r[i], cr[mask])] = true;
						maxi(f[newmask][red + std::min(r[i], cr[mask])], f[mask][red] + std::min(b[i], cb[mask]));
					}
			}
	std::cout << res + n;
	return 0;
}