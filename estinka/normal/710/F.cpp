#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

const int abc = 26;
class aho_corasick
{
	class node
	{
	public:
		int back;
		vector<int> step;
		int words; // how many words end here
		node() :words(0), back(-1)
		{
			step.resize(abc, -1);
		}
	};
	vector<node> nodes;
	void ac_step(int &s, int x)
	{
		while (s && nodes[s].step[x] == -1)
		{
			s = nodes[s].back;
		}
		if (nodes[s].step[x] != -1)
		{
			s = nodes[s].step[x];
		}
	}
	void add_string(string& s)
	{
		int v = 0;
		for (char& ch : s)
		{
			int c = ch - 'a';
			if (nodes[v].step[c] == -1)
			{
				nodes[v].step[c] = nodes.size();
				nodes.push_back(node());
			}
			v = nodes[v].step[c];
		}
		nodes[v].words++;
	}
public:
	void ac_build(vector<string>& s)
	{
		// constructs trie necessary for aho-corasick algorithm
		for (string& i : s)
		{
			add_string(i);
		}
		queue<int>f;
		for (int i = 0; i < abc; i++)
		{
			if (nodes[0].step[i] != -1)
			{
				f.push(nodes[0].step[i]);
				nodes[nodes[0].step[i]].back = 0;
			}
		}
		while (!f.empty())
		{
			int v = f.front();
			f.pop();
			for (int i = 0; i < abc; i++)
			{
				int u = nodes[v].step[i];
				if (u != -1)
				{
					int z = nodes[v].back;
					ac_step(z, i);
					nodes[u].back = z;
					nodes[u].words += nodes[z].words;
					f.push(u);
				}
			}
		}
	}
	ll search(const string& s)
	{
		int state = 0;
		ll answer = 0;
		for (const char& ch : s)
		{
			int c = ch - 'a';
			ac_step(state, c);
			answer += nodes[state].words;
		}
		return answer;
	}
	aho_corasick()
	{
		nodes.resize(1);
	}
};
class online_aho_corasick
{
	// Will keep at most log(number of added words)
	// tries
	vector<aho_corasick> trie;
	vector<vector<string>> words;
	int N;
public:
	online_aho_corasick() :N(0)
	{

	}
	void add_string(const string& s)
	{
		vector<string> new_words(1, s);
		for (int digit = 0;; digit++)
		{
			if ((1 << digit) & N)
			{
				for (string& j : words.back())
				{
					new_words.push_back(j);
				}
				trie.pop_back();
				words.pop_back();
			}
			else
			{
				aho_corasick ac;
				ac.ac_build(new_words);
				trie.push_back(ac);
				words.push_back(new_words);
				break;
			}
		}
		N++;
	}
	int search_for_string(const string& s)
	{
		ll answer = 0;
		for (int i = 0; i < trie.size(); i++)
		{
			answer += trie[i].search(s);
		}
		return answer;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	online_aho_corasick deleted, added;
	for (int i = 0; i < q; i++)
	{
		int t;
		string s;
		cin >> t >> s;
		if (t == 1)
		{
			added.add_string(s);
		}
		else if (t == 2)
		{
			deleted.add_string(s);
		}
		else
		{
			cout << added.search_for_string(s) - deleted.search_for_string(s) << endl;
			cout.flush();
		}
	}
	return 0;
}