#include<bits/stdc++.h>
using namespace std;
int main() {
int T; cin >> T;
while (T--) {

int N; cin >> N;
vector<int> A(N);
for (int i = 0; i < N; i++) cin >> A[i];

auto isPerm = [&](vector<int> v) {
sort(v.begin(), v.end());
return *max_element(v.begin(), v.end()) == int(v.size()) && unique(v.begin(), v.end()) == v.end();
};

vector<pair<int, int>> ans;
int L = *max_element(A.begin(), A.end());
if (isPerm(vector<int>(A.begin(), A.begin()+L)) && isPerm(vector<int>(A.begin()+L, A.end()))) ans.emplace_back(L, int(A.size())-L);
if (L != int(A.size())-L && isPerm(vector<int>(A.begin(), A.end()-L)) && isPerm(vector<int>(A.end()-L, A.end()))) ans.emplace_back(int(A.size())-L, L);

cout << ans.size() << '\n';
for (auto it : ans) cout << it.first << ' ' << it.second << '\n';

}}