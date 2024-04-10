#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>

#define MAXN 5000

using namespace std;

char str[MAXN+1];
bool ispalin[MAXN][MAXN];

int bit_get(vector <int>& bit, int id)
{
	int ret = 0;
	while (id >= 0) {
		ret += bit[id];
		id -= id?id&-id:1;
	}
	return ret;
}

void bit_add(vector <int>& bit, int id, int val)
{
	while (id < (int)bit.size()) {
		bit[id] += val;
		if (!id) break;
		id += id&-id;
	}
}

int main()
{
	int n, nq;

	scanf(" %s %d", str, &nq);
	n = strlen(str);

	for (int i = 0; i < n; i++) ispalin[i][i] = true;
	for (int i = 0; i+1 < n; i++) ispalin[i][i+1] = str[i] == str[i+1];
	for (int d = 2; d < n; d++)
		for (int i = 0; i+d < n; i++)
			ispalin[i][i+d] = str[i] == str[i+d] && ispalin[i+1][i+d-1];

	vector <pair <pair <int, int>, int> > queries;
	vector <int> result(nq);

	for (int i = 0; i < nq; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--, r--;
		queries.push_back(make_pair(make_pair(l, r), i));
	}
	sort(queries.begin(), queries.end());

	vector <int> bit(n, 0);
	
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (ispalin[i][j])
				bit_add(bit, j, 1);

	int next = 0;

	for (int i = 0; i < nq; i++) {
		int left = queries[i].first.first, right = queries[i].first.second, qid = queries[i].second;
		
		while (next < left) {
			for (int j = next; j < n; j++)
				if (ispalin[next][j])
					bit_add(bit, j, -1);
			next++;
		}

		result[qid] = bit_get(bit, right);
	}

	for (int i = 0; i < nq; i++)
		printf("%d\n", result[i]);
	
	return 0;
}