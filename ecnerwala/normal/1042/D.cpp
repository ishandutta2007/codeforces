#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 3e5;
ll T;
int N;
ll P[MAXN];
int M;
ll V[MAXN];
int bit[MAXN];
void update(int a) {
 a++;
 for (; a<=M; a += a&(-a)) {
  bit[a]++;
 }
}
int query(int a) {
 int res = 0;
 for (; a; a -= a&(-a)) res += bit[a];
 return res;
}
int main() {
 ios_base::sync_with_stdio(0);
 cin >> N >> T;
 for (int i = 0; i < N; i++) {
  cin >> P[i+1]; V[i+1] = (P[i+1] += P[i]);
 }
 sort(V,V+N+1);
 M=unique(V,V+N+1)-V;
 ll tot = 0;
 for (int i = 0; i <= N; i++) {
  tot+=i-query(upper_bound(V,V+M,P[i]-T)-V);
  update(lower_bound(V,V+M,P[i])-V);
 }
 cout << tot << '\n';
}