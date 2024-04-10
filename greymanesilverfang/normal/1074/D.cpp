#include <algorithm>
#include <iostream>
#include <map>
std::map<int,std::map<int,int>*> m;

int find(int l, int r)
{
	if (m[l] == nullptr || m[l] != m[r])
		return -1;
	return m[l]->at(l) ^ m[r]->at(r);
}

void join(std::map<int,int> *a, std::map<int,int> *b, int diff)
{
	if (a->size() < b->size())
		std::swap(a, b);
	for (auto &p : *b)
	{
		m[p.first] = a;
		a->insert(std::make_pair(p.first, p.second ^ diff));
	}
}

void update(int l, int r, int x)
{
	if (m[l] != nullptr)
	{
		m[l]->insert(std::make_pair(r, m[l]->at(l) ^ x));
		if (m[r] != nullptr)
			join(m[l], m[r], m[l]->at(r) ^ m[r]->at(r));
		else 
			m[r] = m[l];
		return;
	}
	if (m[r] != nullptr)
	{
		m[r]->insert(std::make_pair(l, m[r]->at(r) ^ x));
		if (m[l] != nullptr)
			join(m[l], m[r], m[l]->at(l) ^ m[r]->at(l));
		else 
			m[l] = m[r];
		return;
	}
	m[l] = m[r] = new std::map<int,int>;
	m[l]->insert(std::make_pair(l, 0));
	m[r]->insert(std::make_pair(r, x));
}

int main()
{
	int last = 0;
	int q; std::cin >> q;
	for (int i = 1; i <= q; ++i)
	{
		int t, l, r; std::cin >> t >> l >> r;
		l ^= last;
		r ^= last;
		if (l > r)
			std::swap(l, r);
		++r;
		int res = find(l, r);
		if (t == 2)
		{
			std::cout << res << '\n';
			if (res == -1)
				last = 1;
			else 
				last = res;
		}
		else 
		{
			int x; std::cin >> x;
			if (res == -1)
			{
				x ^= last;
				update(l, r, x);
			}
		}
	}
	return 0;
}