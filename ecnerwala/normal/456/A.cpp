#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
pii V[200000];
int N;
main() {
cin >> N;
for(int i = 0; i < N; i++) cin >> V[i].first >> V[i].second;
sort(V, V + N);
bool inc = true;
for(int i = 0; i + 1 < N; i++) if(V[i].second > V[i + 1].second) inc = false;
if(inc) cout << "Poor Alex\n";
else cout << "Happy Alex\n";
}