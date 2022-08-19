#include<bits/stdc++.h>
using namespace std;
int N;
pair<int, int> A[int(3e5)];
int main() {
ios_base::sync_with_stdio(0);
cin >> N;
for (int i = 0; i < N; i++) { cin >> A[i].first; A[i].second=i+1; }
sort(A,A+N);
int l = 0, r = N;
while (r && A[r-1].first > 0) r--;
while (l+1<r && A[l].first<0 && A[l+1].first<0) l+=2;
if (r-l==N) r--;
if (l<r) {
 for (int i = l; i+1<r; i++) cout << 1 << ' '<< A[i].second << ' ' << A[i+1].second << '\n';
 cout << 2 << ' ' << A[r-1].second << '\n';
}
for (int i = 0; i+1 < l; i++) {
 cout << 1 << ' ' << A[i].second << ' ' << A[i+1].second << '\n';
}
if (l>0 && r<N) {
 cout << 1 << ' ' << A[l-1].second << ' ' << A[r].second << '\n';
}
for (int i = r; i+1 < N; i++) {
cout << 1 << ' ' << A[i].second << ' ' << A[i+1].second << '\n';
}
}