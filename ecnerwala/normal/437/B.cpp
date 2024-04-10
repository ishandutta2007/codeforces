#include<bits\stdc++.h>

using namespace std;

pair<int, int> vals[200000];
int n;
int res[200000];

int main() {
int sum, limit; cin >> sum >> limit;
for(int i = 1; i <= limit; i++) {
vals[i - 1] = make_pair(i - (i & (i - 1)), i);
}
sort(vals, vals + limit);
reverse(vals, vals + limit);
n = 0;
for(int i = 0; i < limit; i++) {
if(sum >= vals[i].first) sum -= vals[i].first, res[n++] = vals[i].second;
}
if(sum) { cout << -1 << '\n'; return 0; }
cout << n;
for(int i = 0; i < n; i++) cout << (i ? ' ' : '\n') << res[i];
cout << '\n';
return 0;
}