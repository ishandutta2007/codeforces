#include <cassert>
#include <cstdio>
#include <vector>
const long long INF = 1e12;

long long readInt()
{
	long long sum = 0, len = 0;
	while (true)
	{
		char c = getchar();
		if ('0' <= c && c <= '9')
		{
			++len;
			sum = sum * 10 + c - '0';
		}
		else if (len > 0)
			return sum;
	}
}

const int N = 15e6;
char buffer[N + 1], *ans = buffer + N;
void writeInt(long long x)
{
	*--ans = ' ';
	do {
		*--ans = x % 10 + '0';
		x /= 10;
	} while (x > 0);
}

int main()
{
	int n = readInt();
	std::vector<long long> v;
	long long prv = INF;
	for (int i = 1; i <= n; ++i)
	{
		long long h = readInt();
		if (h > prv)
		{
			++v.back();
			h -= ++prv;
			while (h > 0)
			{
				long long tmp = v.back();
				v.pop_back();
				if (v.empty())
				{
					prv += h / tmp;
					h %= tmp;
					if (h > 0)
						v.push_back(h);
					v.push_back(tmp - h);
					break;
				}
				else
					v.back() += tmp;
				if (h < tmp)
				{
					tmp -= h;
					v.back() -= tmp;
					v.push_back(tmp);
					break;
				}
				h -= tmp;
				++prv;
			}
		}
		else 
		{
			prv = h;
			v.push_back(1);
		}
	}
	for (int i = n; i >= 1; --i)
	{
		writeInt(prv);
		if (--v.back() > 0)
			--prv;
		else
			v.pop_back();
	}
	assert(v.empty());
	printf("%s", ans);
}