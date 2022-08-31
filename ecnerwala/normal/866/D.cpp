#include<bits/stdc++.h>
using namespace std;

int main() {
priority_queue<int> q;
long long result = 0;
ios_base::sync_with_stdio(0);
int N;
cin >> N;
for (int i = 0; i < N; i++) {
int v; cin >> v;
q.push(-v);
q.push(-v);
result += v + q.top();
q.pop();
}
cout << result << '\n';
return 0;
}