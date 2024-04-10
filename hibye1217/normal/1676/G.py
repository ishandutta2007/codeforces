#if 0

import sys
from collections import deque
input = sys.stdin.readline
for _ in range( int( input() ) ):
    n = int( input() )
    chl = [ [] for i in range(n) ]
    nxt = tuple( map( int, input().split() ) )
    for i in range(n-1):
        chl[ nxt[i]-1 ].append(i+1)
    clr = input()
    cnt = [ len(chl[i]) for i in range(n) ]
    res = [ [1, 0] if clr[i] == 'W' else [0, 1] for i in range(n) ]
    q = deque()
    for v in range(n):
        if cnt[v] == 0: q.append(v)
    #print(cnt)
    ans = 0
    for _ in range(n):
        now = q.popleft()
        #print(now, res[now-1], nxt[now-1]-1 if now != 0 else -1)
        if now != 0:
            cnt[ nxt[now-1]-1 ] -= 1
            if cnt[ nxt[now-1]-1 ] == 0: q.append(nxt[now-1]-1)
            res[ nxt[now-1]-1 ][0] += res[now][0]
            res[ nxt[now-1]-1 ][1] += res[now][1]
            #print(cnt, res)
        if res[now][0] == res[now][1]: ans += 1
    print(ans)

#endif
#if 0
""" "
#endif

#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

vector<int> chl[4020];
string clr;

pi2 arr[4020]; int ans = 0;
void dfs(int now){
	if (clr[now] == 'W'){ arr[now] = {1, 0}; }
	else{ arr[now] = {0, 1}; }
	for (int nxt : chl[now]){
		dfs(nxt);
		arr[now].fr += arr[nxt].fr;
		arr[now].sc += arr[nxt].sc;
	}
	//cout << "DPF " << now << " = " << arr[now].fr << ' ' << arr[now].sc << endl;
	if (arr[now].fr == arr[now].sc){ ans += 1; }
}

void Main(){
	int t; cin >> t; while (t--){
		int n; cin >> n;
		for (int i = 1; i < n; i++){
			int v; cin >> v; chl[v-1].push_back(i);
		}
		cin >> clr;
		ans = 0; dfs(0); cout << ans << endl;
		for (int i = 0; i < n; i++){ chl[i].clear(); }
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}

#if 0
" """
#endif // 0