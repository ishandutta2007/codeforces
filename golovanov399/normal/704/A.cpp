#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt(), q = nxt();
	vector<char> seen;
	int lst = 0;
	vector<int> last(n, -1), pr;
	vector<int> llst(n, -1);
	int cur = 0;
	while (q--){
		int t = nxt();
		if (t == 1){
			int x = nxt() - 1;
			seen.push_back(0);
			pr.push_back(last[x]);
			last[x] = (int)pr.size() - 1;
			cur++;
		} else if (t == 2){
			int x = nxt() - 1;
			for (int i = last[x]; i != llst[x]; i = pr[i]){
				if (!seen[i])
					cur--;
				seen[i] = 1;
			}
			llst[x] = last[x];
		} else {
			int tt = nxt();
			for (int i = lst; i < tt; i++){
				if (!seen[i])
					cur--;
				seen[i] = 1;
			}
			lst = max(lst, tt);
		}
		printf("%d\n", cur);
	}

	return 0;
}