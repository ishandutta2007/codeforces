#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000005;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> last(n);
	for(int i = 0, j = -1; i < n; i++){
		cin >> a[i];
		if(a[i] == -1){
			last[i] = j;
			j = i;
		}
	}

	int m;
	cin >> m;
	vector<int> b(m);
	vector<int> used(m);
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	sort(b.rbegin(), b.rend());

	vector<int> vec, ind;
	vector<int> prev(n), dp(n);
	for(int i = 0; i < n; i++){
		if(a[i] != -1){
			if(vec.empty()){
				vec.emplace_back(a[i]);
				ind.emplace_back(i);
				prev[i] = -1;
				dp[i] = 1;
			}else if(vec.back() < a[i]){
				vec.emplace_back(a[i]);
				prev[i] = ind.back();
				ind.emplace_back(i);
				dp[i] = (int)vec.size();
			}else{
				int lo = 0, hi = (int)vec.size() - 1;
				while(lo < hi){
					int mi = (lo + hi)/2;
					if(vec[mi] < a[i])lo = mi + 1;
					else hi = mi;
				}
				if(lo == 0){
					prev[i] = -1;
				}else{
					prev[i] = ind[lo - 1];
				}
				vec[lo] = a[i];
				ind[lo] = i;
				dp[i] = lo + 1;
			}
		}else{
			if(vec.empty() || vec.back() < b[0]){
				vec.emplace_back(b[0]);
				ind.emplace_back(i);
			}
			int k = (int)vec.size() - 1;
			for(int j = 0; j < m; j++){
				while(k != 0 && vec[k - 1] >= b[j])k--;
				vec[k] = b[j];
				ind[k] = i;
			}
			prev[i] = -2;
		}
	}
	int len = (int)vec.size();
	vector<vector<int> > lv(len + 1);
	for(int i = 0; i < n; i++){
		if(a[i] != -1){
			lv[dp[i]].emplace_back(i);
		}
	}

	int curval = inf;
	int curind = ind.back();
	while(curind != -1){
		len--;
		if(a[curind] == -1){
			for(int j = 0; j < m; j++){
				if(b[j] < curval){
					a[curind] = b[j];
					curval = b[j];
					used[j] = 1;
					break;
				}
			}
			if(len == 0){
				break;
			}
			bool flg = false;
			while(!lv[len].empty()){
				int i = lv[len].back();
				lv[len].pop_back();
				if(i < curind && a[i] < curval){
					curind = i;
					flg = true;
					break;
				}
			}
			if(flg)continue;
			assert(last[curind] != -1);
			curind = last[curind];
		}else{
			curval = a[curind];
			curind = prev[curind];
		}
	}
	for(int i = 0, j = 0; i < n; i++){
		if(a[i] == -1){
			while(used[j])j++;
			used[j] = 1;
			a[i] = b[j];
		}
		cout << a[i] << " ";
	}
	cout << '\n';

	return 0;
}