#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

struct Block
{
	int start, size;
	char letter;
	bool operator<(Block o) const { return start < o.start; }
	
	int end() const { return start + size; }
};

const int SIGMA = 26;
int h[SIGMA];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin >> n >> q;
	string cad;
	cin >> cad;
	set<Block> blocks;
	forn(i,n)
		blocks.insert({i, 1, cad[i]});
	forn(qnum,q)
	{
		int qi,qj,qk;
		cin >> qi >> qj >> qk;
		qi--;
		forn(i, SIGMA) h[i] = 0;
		auto it = blocks.upper_bound({qi,0,0});
		assert(it != blocks.begin());
		auto nextIt = it;
		--it;
		if (it->end() >= qj) continue;
		Block leftBlock = *it;
		blocks.erase(it);
		assert(leftBlock.start <= qi);
		assert(qi < leftBlock.end());
		h[leftBlock.letter-'a'] += leftBlock.size - (qi - leftBlock.start);
		if (qi > leftBlock.start)
			blocks.insert({leftBlock.start, qi - leftBlock.start , leftBlock.letter});
		while (nextIt != blocks.end() && nextIt->end() <= qj)
		{
			auto eraseIt = nextIt;
			++nextIt;
			h[eraseIt->letter-'a'] += eraseIt->size;
			blocks.erase(eraseIt);
		}
		if (nextIt != blocks.end() && qj > nextIt->start)
		{
			assert(qj < nextIt->end());
			h[nextIt->letter-'a'] += qj - nextIt->start;
			blocks.insert({qj, nextIt->end() - qj , nextIt->letter});
			blocks.erase(nextIt);
		}
		int delta = qk ? 1 : -1;
		int finish = qk ? SIGMA : -1;
		int nextBlockStart = qi;
		int s = 0;
		forn(i,SIGMA) s += h[i];
		assert(s == qj - qi);
		for (int i = qk ? 0 : SIGMA-1; i != finish; i += delta)
		if (h[i] > 0)
		{
			blocks.insert({nextBlockStart, h[i], char('a'+i)});
			nextBlockStart += h[i];
		}
	}
	for (Block b : blocks)
		cout << string(b.size, b.letter);
	cout << "\n";
	return 0;
}