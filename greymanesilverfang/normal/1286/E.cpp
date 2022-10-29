#include <cstdio>
#include <map>
#include <vector>
const int N = 7e5, MASK = 1<<30;
char s[N];
int kmp[N] = {-1};
std::vector<int> loss[N];

struct bigInt 
{
	const static int base = 10;
	std::vector<long long> v;
	void reduce()
	{
		for (int i = 0; v[i] >= base; ++i)
		{
			if (i == v.size() - 1)
				v.push_back(0);
			v[i + 1] += v[i] / base;
			v[i] %= base;
		}
	}
	bigInt(long long x)
	{
		v.clear();
		v.push_back(x);
		reduce();
	}
	bigInt& operator += (long long x)
	{
		v[0] += x;
		reduce();
		return *this;
	}
	void write()
	{
		for (auto it = v.rbegin(); it != v.rend(); ++it)
			putchar(*it + '0');
		putchar(' ');
	}
};

int main()
{
	int n; scanf("%d", &n);
	long long res = 0;
	int sum26 = 0, sum_mask = 0;
	bigInt sum(0);
	std::map<int,std::pair<long long,int>,std::greater<int>> map;
	for (int i = 1; i <= n; ++i)
	{
		char c; int w; scanf(" %c%d", &c, &w);
		s[i] = (c - 'a' + sum26) % 26 + 'a';
		std::pair<long long,int> cur(w ^ sum_mask & MASK - 1, 1);
		while (!map.empty())
		{
			std::pair<long long,int> prv = map.begin()->second;
			if (prv.first >= cur.first)
			{
				res -= prv.first * prv.second;
				cur.second += prv.second;
				map.erase(map.begin());
			}
			else 
				break;
		}
		res += cur.first * cur.second;
		map[i] = cur;
		kmp[i] = kmp[i - 1];
		while (kmp[i] >= 0 && s[kmp[i] + 1] != s[i])
		{
			loss[i].push_back(kmp[i]);
			kmp[i] = kmp[kmp[i]];
		}
		for (int x : loss[++kmp[i]])
			loss[i].push_back(x);
		for (int x : loss[i])
		{
			std::pair<long long,int> &p = std::prev(map.upper_bound(i - x))->second;
			res -= p.first;
			--p.second;
		}
		sum26 = (sum26 + res % 26) % 26;
		sum_mask = (sum_mask + res % MASK) % MASK;
		(sum += res).write();
		printf("\n");
	}
}