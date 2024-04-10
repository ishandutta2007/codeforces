#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

struct Node {
	Node *next[26];
	int size;
	int mergeSize;
	
	Node() {
		for (int i = 0; i < 26; i++) {
			next[i] = nullptr;
		}
		size = 1;
		mergeSize = 0;
	}	
};

typedef Node* pNode;

vector<Node> nodes;
pNode root;

struct TempEvent {
	pNode node;
	int incSize;
	int changeNext;
	
	TempEvent(pNode node, int incSize, int changeNext)
		: node(node), incSize(incSize), changeNext(changeNext) {
	}
	
	inline void apply(pNode newNode) {
		if (changeNext < 0) {
			node->size += incSize;
		} else {
			node->next[changeNext] = newNode;
		}
	}
	
	inline void revert() {
		if (changeNext < 0) {
			node->size -= incSize;
		} else {
			node->next[changeNext] = nullptr;
		}		
	}
};

vector<TempEvent> tempEvents;

void recount(pNode a) {
	if (a == nullptr) {
		return;
	}
	a->size = 1;
	for (int i = 0; i < 26; i++) {
		if (a->next[i] != nullptr) {
			recount(a->next[i]);
			a->size += a->next[i]->size;
		}
	}
}

void merge(pNode a, pNode b) {
	if (a == nullptr || b == nullptr) {
		return;
	}
	int newSize = 1;
	for (int i = 0; i < 26; i++) {
		if (a->next[i] == nullptr && b->next[i] == nullptr) {
			continue;
		}
		if (a->next[i] == nullptr) {
			tempEvents.emplace_back(a, 0, i);
			tempEvents.back().apply(b->next[i]);
		}
		if (b->next[i] != nullptr) {
			merge(a->next[i], b->next[i]);
		}
		if (a->next[i] != nullptr) {
			newSize += a->next[i]->size;
		}
	}
	tempEvents.emplace_back(a, newSize - a->size, -1);
	tempEvents.back().apply(nullptr);
}

inline void removeTempEdges() {
	reverse(tempEvents.begin(), tempEvents.end());
	for (auto it: tempEvents) {
		it.revert();
	}
	tempEvents.clear();
}

void computeMergeSize(pNode a) {
	if (a == nullptr) {
		return;
	}
	int maxSize = -1, maxNext = -1;
	for (int i = 0; i < 26; i++) {
		if (a->next[i] != nullptr) {
			if (a->next[i]->size > maxSize) {
				maxSize = a->next[i]->size;
				maxNext = i;
			}
		}
	}
	if (maxNext < 0) {
		a->mergeSize = 1;
	} else {
		for (int i = 0; i < 26; i++) {
			if (a->next[i] != nullptr && i != maxNext) {
				merge(a->next[maxNext], a->next[i]);
			}
		}
		a->mergeSize = a->next[maxNext]->size;
		removeTempEdges();
	}	
	for (int i = 0; i < 26; i++) {
		computeMergeSize(a->next[i]);
	}
}

vector<int> ansForDepth;

void calcAnsForDepth(pNode a, int d) {
	if (a == nullptr) {
		return;
	}
	ansForDepth[d] += a->mergeSize - a->size;
	for (int i = 0; i < 26; i++) {
		calcAnsForDepth(a->next[i], d+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	nodes.resize(n);
	for (int i = 1; i < n; i++) {
		int a, b; char c; cin >> a >> b >> c; a--; b--;
		nodes[a].next[c - 'a'] = &nodes[b];
	}
	root = &nodes[0];
	recount(root);
	computeMergeSize(root);
	ansForDepth.resize(n);
	for (int i = 0; i < n; i++) {
		ansForDepth[i] = nodes[0].size;
	}
	calcAnsForDepth(root, 0);
	int best = 0;
	for (int i = 1; i < n; i++) {
		if (ansForDepth[i] < ansForDepth[best]) {
			best = i;
		} 
	}
	cout << ansForDepth[best] << endl << best+1 << endl;
	return 0;
}