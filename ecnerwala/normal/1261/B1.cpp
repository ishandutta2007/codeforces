#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<pair<int, int>> evts(N);
	for (int i = 0; i < N; i++) {
		evts[i] = {-A[i], i};
	}
	sort(evts.begin(), evts.end());

	int M; cin >> M;
	vector<pair<pair<int, int>, int>> requests(M);
	for (int j = 0; j < M; j++) {
		cin >> requests[j].first.first >> requests[j].first.second;
		requests[j].second = j;
	}
	sort(requests.begin(), requests.end());

	vector<int> ans(M);

	ordered_set st;
	for (int i = 0, j = 0; i < N; i++) {
		st.insert(evts[i].second);
		while (j < M && requests[j].first.first == i+1) {
			ans[requests[j].second] = A[*st.find_by_order(requests[j].first.second-1)];
			j++;
		}
	}
	for (int j = 0; j < M; j++) {
		cout << ans[j] << '\n';
	}
	return 0;
}