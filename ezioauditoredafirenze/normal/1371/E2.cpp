#include<bits/stdc++.h>
using namespace std;
template<class T1, class T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return true;} return false; }
template<class T1, class T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return true;} return false; }
int main(){
	long long N,p; cin >> N >> p;
    vector<long long> A(N);
    for(long long i=0;i<N;i++) cin >> A[i];
    sort(A.begin(),A.end());
    long long l = 1, r = 1e18;
    set<long long> dic;
    for(long long i=0;i<N;i++) {
        long long val = N-A[i]-(N-1-i);
        chmax(l,1LL-val);
        if ((i+1)%p==0) chmin(r,(long long)(i+1)-val);
        if (i+1>=p) {
            dic.emplace(p-val);
        }
    }
    if (r < l) {
        cout << 0 << endl << endl;
        return 0;
    }
    vector<bool> check(r-l+1);
    vector<long long> ans;
    for (long long i = l; i <= r; i++) {
        if (check[i-l]) continue;
        if (dic.count(i)) {
            for (long long j = i; j <= r; j += p) {
                check[j-l] = 1;
            }
        }
        if (!check[i-l]) {
            ans.emplace_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << " ";
    cout << endl;
	return 0;
}