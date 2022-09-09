#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        int k = 0;
        while(k * 2 + 1 < n) k = k * 2 + 1;
        cout << k << "\n";
    }
	return 0;
}