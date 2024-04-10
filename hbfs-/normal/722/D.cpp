#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define N 100050

using namespace std;

int n,a[N];

struct Trie{
	int son[50*N][2],leef[50*N],vist[50*N],cnt;
	queue<int> pool;
	
	inline int get() {
		if (!pool.empty()) {
			int tmp = pool.front(); 
			pool.pop(); 
			return tmp;
		} else {
			return ++cnt;
		}
	}
	
	inline void add(int x) {
		int p = 1;
		for (int i=30;i>=0;i--) {
			int paul = 1 << i;
			int g = ( x&(1<<i) ) ? 1 : 0;
			if (!son[p][g]) son[p][g] = get();
			p = son[p][g];
			vist[p]++;
		}
		leef[p] = 1;
	}
	
	inline void del(int x) {
		int p = 1;
		for (int i=30;i>=0;i--) {
			int g = ( x&(1<<i) ) ? 1 : 0;
			int tmp = son[p][g];
			if (--vist[ son[p][g] ] == 0) {
				pool.push(son[p][g]);
				son[p][g] = 0;
			}
			p = tmp;
		}
	}
	
	inline bool find(int x) {
		int p = 1;
		for (int i=30;i>=0;i--) {
			int g = ( x&(1<<i) ) ? 1 : 0;
			if (!son[p][g]) return false;
			p = son[p][g];
		}
		return leef[p];
	}
}trie;

priority_queue<int> q;

int main()
{
	scanf("%d",&n);

	trie.cnt = 1;
	
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		trie.add(a[i]);
		q.push(a[i]);
	}
	
	bool flag = true;
	while (flag) {
		flag = false;
		int u = q.top(); q.pop();
		for (int i=(u>>1);i;i>>=1)
			if (!trie.find(i)) {
				trie.del(u);
				trie.add(i);
				flag = true;
				q.push(i);
				break;
			}
		if (!flag) q.push(u);
	}
	
	flag = true;
	while (!q.empty()) {
		int u = q.top(); q.pop();
		if (flag) {
			printf("%d",u);
			flag = false;
		} else {
			printf(" %d",u);
		}
	}
	printf("\n");
	
	return 0;
}