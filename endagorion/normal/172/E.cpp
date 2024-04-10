#pragma comment(linker, "/STACK:50000000")

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

typedef unsigned long long hash_t;
const hash_t P = 353;
const hash_t Q = 1902137821;

class TTrieNode {
public:
	vector<TTrieNode *> Children;
	vector<hash_t> Hashes;
	int Depth;

	TTrieNode(int _depth)
		: Depth(_depth)
	{
	}

	TTrieNode *AddChild(const hash_t hash) {
		TTrieNode *newNode = new TTrieNode(Depth + 1);
		Children.push_back(newNode);
		Hashes.push_back(hash);
		return newNode;
	}
};


hash_t HashStringSegment(const string &s, size_t begin, size_t end) {
	hash_t hash = 0;
	for (size_t cur = begin; cur < end; ++cur) {
		hash = hash * P + s[cur];
	}
	return hash;
}

size_t ParseStringIntoHashTrie(const string &code, size_t start, TTrieNode *node) {
	size_t cur = start;
	while (cur < code.size()) {
		++cur;
		if (code[cur] == '/') {
			++cur;
			while (code[cur] != '>') {
				++cur;
			}
			return cur + 1;
		}
		size_t first = cur;
		while (code[cur] != '/' && code[cur] != '>') {
			++cur;
		}
		if (code[cur] == '/') {
			node->AddChild(HashStringSegment(code, first, cur));
			cur += 2;
		} else {
			hash_t hash = HashStringSegment(code, first, cur);
			cur = ParseStringIntoHashTrie(code, cur + 1, node->AddChild(hash));
		}
	}
	return cur;
}

size_t countHashes(TTrieNode *node, const vector<hash_t> &toFindHashes, size_t toFindCurrent) {
	size_t result = 0;
	
	size_t childCount = node->Children.size();
	for (size_t childId = 0; childId < childCount; ++childId) {
		TTrieNode *childNode = node->Children[childId];
		hash_t childHash = node->Hashes[childId];
		size_t toFindNext = toFindCurrent;
		if (childHash == toFindHashes[toFindCurrent]) {
			if (toFindCurrent + 1 == toFindHashes.size()) {
				++result;
			} else {
				++toFindNext;
			}
		}
		result += countHashes(childNode, toFindHashes, toFindNext);
	}

	return result;
}

int main() {
	fout.precision(10);
	fout << fixed;

	string s;
	fin >> s;
	TTrieNode *root = new TTrieNode(0);
	ParseStringIntoHashTrie(s, 0, root);
	int M;
	fin >> M;
	fin.ignore(1, '\n');
	for (int i = 0; i < M; ++i) {
		char query[3000];
		fin.getline(query, 3000);
		string token = "";
		vector<hash_t> hashes;
		for (size_t j = 0; query[j]; ++j) {
			if (query[j] == ' ') {
				if (!token.empty()) {
					hashes.push_back(HashStringSegment(token, 0, token.size()));
					token = "";
				}
			} else {
				token.push_back(query[j]);
			}
		}
		if (!token.empty()) {
			hashes.push_back(HashStringSegment(token, 0, token.size()));
			token = "";
		}
		fout << countHashes(root, hashes, 0) << '\n';
	}

	return 0;
}