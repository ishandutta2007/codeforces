#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, tot = 0;
        cin >> n;
        int x = 0, sum = 0;
        for(int i = 1; i <= n; i += 1){
            tot += 1;
            cout << "? 1 " << n - i << "\n";
            cout << i << "\n";
            for(int j = i + 1; j <= n; j += 1) cout << j << " ";
            cout << endl;
            int res = 0;
            cin >> res;
            if(res){
                sum = res;
                x = i;
                break;
            }
        }
        vector<int> v;
        for(int y = x + 1; y <= n - 1; y += 1){
            tot += 1;
            cout << "? 1 1\n";
            cout << x << "\n";
            cout << y << endl;
            int res = 0;
            cin >> res;
            sum -= res;
            if(not res)
                v.push_back(y);
        }
        if(not sum) v.push_back(n);
        int L = 1, R = x;
        while(L < R){
            tot += 1;
            int M = (L + R) >> 1;
            cout << "? 1 " << M << "\n";
            cout << x << "\n";
            for(int j = 1; j <= M; j += 1) cout << j << " ";
            cout << endl;
            int res = 0;
            cin >> res;
            if(res) R = M;
            else L = M + 1;
        }
        for(int i = 1; i < x; i += 1) if(i != L) v.push_back(i);
        sort(v.begin(), v.end());
        cout << "! " << v.size() << " ";
        for(int i : v) cout << i << " ";
        cout << endl;
        assert((1 << (tot - n)) <= n);
    }
    return 0;
}