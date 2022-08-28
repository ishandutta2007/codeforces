#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

string A[3];
int cnt[3][27];
vector<int> aa[3];
vector<string> ans;
void solve()
{
	int mn = INF;
	rep(i, 3) {
		cin >> A[i];
		aa[i].clear();
		rep(j, 26) cnt[i][j] = 0;
		rep(j, A[i].size()) cnt[i][A[i][j] - 'A'] ++;
		mn = min(mn, (int)A[i].size());
	}
	
	ans.clear();
	rep(i, 26) while(mn > 0 && (cnt[0][i] > 0) + (cnt[1][i] > 0) + (cnt[2][i] > 0) >= 2) {
		int tmp = 0;
		rep1(j, 2) if(cnt[j][i] < cnt[tmp][i]) tmp = j;
		rep(j, 3) if(j != tmp) cnt[j][i] --;
		aa[tmp].push_back(i);
		mn --;
	}
	rep(i, 3) rep(j, 26) while(!aa[i].empty() && cnt[i][j] > 0) {
		string cur;
		cur.push_back('A' + aa[i].back());
		cur.push_back('A' + j);
		ans.push_back(cur);
		cnt[i][j] --; aa[i].pop_back();
	}
	rep(i, 3) {
		cnt[i][26] = 0;
		rep(j, 26) cnt[i][26] += cnt[i][j];
	}
	while(cnt[0][26] + cnt[1][26] + cnt[2][26] > 0) {
		int tmp = 0;
		rep1(j, 2) if(cnt[j][26] < cnt[tmp][26]) tmp = j;
		string cur;
		rep(j, 3) if(j != tmp) {
			char x = 'A';
			rep(k, 26) if(cnt[j][k] > 0) {
				cnt[j][k] --; cnt[j][26] --; x = 'A' + k; break;
			}
			cur.push_back(x);
		}
		ans.push_back(cur);
	}
	cout << ans.size() << '\n';
	rep(i, ans.size()) cout << ans[i] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}