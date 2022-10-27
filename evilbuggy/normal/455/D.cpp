#include <bits/stdc++.h>
using namespace std;

const int maxb = 405;
const int maxn = 100005;
const int maxc = maxn/maxb + 5;

deque<int> arr[maxc];
int cnt[maxc][maxn], ind[maxn], pos[maxn], tot[maxc];

inline void rotate(int i, int l, int r){
	for(int j = r; j > l; j--){
		swap(arr[i][j], arr[i][j - 1]);
	}
}

inline void rotatefull(int i){
	int x = arr[i].back(); arr[i].pop_back();
	arr[i].push_front(x);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(cnt, 0, sizeof(cnt));
	memset(tot, 0, sizeof(tot));

	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x; x--;

		ind[i] = i/maxb;
		pos[i] = i%maxb;
		
		tot[ind[i]]++;
		cnt[ind[i]][x]++;
		arr[ind[i]].emplace_back(x);
	}
	
	int q; cin >> q;
	
	int ans = 0;
	while(q--){
		int t; cin >> t;
		if(t == 1){
			int l; cin >> l;
			int r; cin >> r;
			l = (l - 1 + ans)%n;
			r = (r - 1 + ans)%n;
			if(l > r)swap(l, r);
			if(ind[l] == ind[r]){
				rotate(ind[l], pos[l], pos[r]);
				continue;
			}
			rotate(ind[l], pos[l], tot[ind[l]] - 1);
			for(int i = ind[l] + 1; i < ind[r]; i++){
				rotatefull(i);
			}
			rotate(ind[r], 0, pos[r]);
			for(int i = ind[r]; i > ind[l]; i--){
				int j = i - 1;
				int pi = 0, pj = 0;
				if(j == ind[l])pj = pos[l];
				
				cnt[i][arr[i][pi]]--;
				cnt[j][arr[j][pj]]--;
				swap(arr[i][pi], arr[j][pj]);
				cnt[i][arr[i][pi]]++;
				cnt[j][arr[j][pj]]++;
			}
		}else{
			int l; cin >> l;
			int r; cin >> r;
			int k; cin >> k;
			l = (l - 1 + ans)%n;
			r = (r - 1 + ans)%n;
			k = (k - 1 + ans)%n;
			if(l > r)swap(l, r);
			
			ans = 0;
			for(int i = ind[l] + 1; i < ind[r]; i++){
				ans += cnt[i][k];
			}
			if(ind[l] == ind[r]){
				for(int i = pos[l]; i <= pos[r]; i++){
					if(arr[ind[l]][i] == k)ans++;
				}
			}else{
				int sz = tot[ind[l]];
				for(int i = pos[l]; i < sz; i++){
					if(arr[ind[l]][i] == k)ans++;
				}
				for(int i = 0; i <= pos[r]; i++){
					if(arr[ind[r]][i] == k)ans++;
				}
			}
			cout << ans << '\n';
		}
	}

	return 0;
}