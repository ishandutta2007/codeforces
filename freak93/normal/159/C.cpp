#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class FenwickTree {
  public:
	FenwickTree(int N);
	void update(int, int);
	int query(int);
	int search(int);
  private:
	vector<int> buffer;
};

inline FenwickTree::FenwickTree(int N) {
	buffer.resize(N);
}

inline void FenwickTree::update(int position, int value) {
	for (; position < static_cast<int>(buffer.size()); position += (position & -position))
		buffer[position] = buffer[position] + value;
}

inline int FenwickTree::query(int position = -1) {
	if (position == -1)
		position += buffer.size();
	
	int sum = 0;
	for (; position > 0; position -= (position & -position))
		sum = sum + buffer[position];
	return sum;
}

inline int FenwickTree::search(int value) {
	int step, i, sum = 0;
	for (step = 1; step < static_cast<int>(buffer.size()); step <<= 1);
	for (i = 0; step; step >>= 1)
		if ((i + step) < static_cast<int>(buffer.size()) && sum + buffer[i + step] <= value) {
			i += step;
			sum += buffer[i];
		}
	return i;
}

class BadPositions {
  public:
    void add(int badPosition) {
		buffer.push_back(badPosition);
	}
	vector<int> rebuild() {
		
		//cerr << "From -> \n";
		//for (auto &it: buffer)
		//	cerr << it << " ";
		//cerr << "\n";

		FenwickTree tree(N + 1);
		for (int i = 1; i <= N; ++i)
			tree.update(i, 1);
		vector<int> newBuffer;
		for (auto &it: buffer) {
			newBuffer.push_back(tree.search(it - 1) + 1);
			tree.update(tree.search(it - 1) + 1, -1);
		}

		sort(newBuffer.begin(), newBuffer.end());
		//cerr << "To -> \n";
		//for (auto &it: newBuffer)
		//	cerr << it << " ";
		//cerr << "\n";
	
		return (buffer = newBuffer);
	}

	bool isGoodPosition(int x) {
		return binary_search(buffer.begin(), buffer.end(), x) == false;
	}
	int N;
  private:
	vector<int> buffer;
};

int main() {
	int K; cin >> K;
	string s; cin >> s;

	vector<int> many(26);
	for (int i = 0; i < static_cast<int>(s.size()); ++i)
		++many[s[i] - 'a'];
	
	vector<BadPositions> badPositions(26);
	for (int i = 0; i < 26; ++i)
		badPositions[i].N = many[i] * K;

	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		int occurence; char character;
		cin >> occurence >> character;
		badPositions[character - 'a'].add(occurence);
	}
	
	for (auto &it: badPositions)
		it.rebuild();
	
	vector<int> currentPosition(26, 0);
	string answer = "";
	for (int i = 0; i < K; ++i)
		for (auto &j: s) {
			int current = ++currentPosition[j - 'a'];
			if (badPositions[j - 'a'].isGoodPosition(current))
				answer += j;
		}
	
	cout << answer;
}