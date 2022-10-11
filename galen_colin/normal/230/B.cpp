/* testing code by satyampandey, https://codeforces.com/blog/entry/68709 */

#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1000001;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,i,j;
    long long n;
    cin >> t;
    bool prime[N];
    memset(prime, true, N);
    for(i = 2; i <= sqrt(N); i++) {
     if(prime[i] == true) {
      for(j = i * i; j < N; j = j + i) {
       prime[j] = false;
	  }
	 }
	}
	prime[0] = prime[1] = 0;
    while(t--) {
	 cin >> n;
	 if((long long)sqrt(n) * (long long)sqrt(n) == n && prime[(int)sqrt(n)])
	  cout << "YES" << endl;
	 else
	  cout << "NO" << endl;
    }
    return 0;
}