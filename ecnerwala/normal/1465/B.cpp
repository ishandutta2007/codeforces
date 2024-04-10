#include<bits/stdc++.h>
using namespace std;
bool good(int64_t a) {
 for (int64_t v = a; v; v /= 10) {
   int d = v % 10;
   if (d && a % d) return false;
 }
 return true;
}
int main() {
int T; cin >> T;
while (T--) { int64_t N; cin >> N; while (!good(N)) N++; cout << N << '\n';}

}