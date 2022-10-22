#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

void solve(vector <pii> now, int flag = 1){
	if (now.size() == 0){
		printf("0\n");
		return ;
	}
	if (now.size() == 1){
		printf("pushStack\n");
		if (flag) printf("1 popStack\n");
		return ;
	}
	if (now.size() == 2){
		printf("pushStack\npushQueue\n");
		if (flag) printf("2 popStack popQueue\n");
		return ;
	}
	sort(now.rbegin(), now.rend());
	for (int i = 0; i < now.size(); i++){
		if (i == now[0].se) printf("pushStack\n");
		else if (i == now[1].se) printf("pushQueue\n");
		else if (i == now[2].se) printf("pushFront\n");
		else printf("pushBack\n");
	}
	if (flag) printf("3 popStack popQueue popFront\n");
}

int main(){
	int n; scanf("%d", &n);
	vector <pii> now;
	for (int _ = 0; _ < n; _++){
		int x; scanf("%d", &x);
		if (x == 0) solve(now), now.clear();
		else now.push_back(mp(x, (int)now.size()));
	}
	if (now.size()) solve(now, 0);
	return 0;
}