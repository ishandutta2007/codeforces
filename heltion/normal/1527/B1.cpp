#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        string s;
        cin >> n >> s;
        int k = count(s.begin(), s.end(), '0');
        if((k & 1) and k != 1) cout << "ALICE\n";
        else cout << "BOB\n";
    }
	return 0;
}