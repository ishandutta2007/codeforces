#include <bits/stdc++.h>
using namespace std;

const int K = 7;
const int N = 1000;

long long  ax[K], ay[K], mx[N], my[N];
int n, k, nxt[N][K], que[N + N], added[N];

inline bool isInbetween(int x1, int y1, int x2, int y2, int x3, int y3){
	if(x2 < x1 && x2 < x3)return false;
	if(y2 < y1 && y2 < y3)return false;
	if(x2 > x1 && x2 > x3)return false;
	if(y2 > y1 && y2 > y3)return false;
	return 1LL*(y3 - y1)*(x3 - x2) == 1LL*(y3 - y2)*(x3 - x1);
}

bool canBeCleared(int lo, int hi, int mask, int cnt){
	if(lo > hi)return true;
	if(hi - lo + 1 > cnt)return false;
	for(int i = 0; i < k; i++){
		if((mask >> i) & 1){
			int x = que[lo], nhi = hi;
			while(nxt[x][i] != -1){
				if(!added[nxt[x][i]]){
					++nhi; que[nhi] = nxt[x][i];
					added[nxt[x][i]] = 1;
				}
				x = nxt[x][i];
				if(nhi - lo + 1 > cnt)break;
			}
			bool tmp = canBeCleared(lo + 1, nhi, mask^(1 << i), cnt - 1);
			while(nhi > hi){
				added[que[nhi]] = 0;
				nhi--;
			}
			if(tmp)return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> k >> n;
	for(int i = 0; i < k; i++){
		cin >> ax[i] >> ay[i];
	}
	for(int i = 0; i < n; i++){
		cin >> mx[i] >> my[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			int ind = -1;
			long long dist = 1e18;
			for(int r = 0; r < n; r++){
				if(r == i)continue;
				if(isInbetween(mx[i], my[i], mx[r], my[r], ax[j], ay[j])){
					if(dist > abs(mx[i] - mx[r]) + abs(my[i] - my[r])){
						dist = abs(mx[i] - mx[r]) + abs(my[i] - my[r]);
						ind = r;
					}
				}
			}
			nxt[i][j] = ind;
		}
	}
	int answer = 0;
	memset(added, 0, sizeof(added));
	for(int i = 0; i < n; i++){
		que[0] = i;
		added[que[0]] = 1;
		if(canBeCleared(0, 0, (1 << k) - 1, k))answer++;
		added[que[0]] = 0;
	}
	cout << answer << '\n';

	return 0;
}