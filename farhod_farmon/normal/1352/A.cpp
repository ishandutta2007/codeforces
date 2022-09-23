#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                vector < int > v;
                int n;
                cin >> n;
                int cnt = 0;
                while(n > 0){
                        v.push_back(n % 10);
                        n /= 10;
                        cnt += (v.back() != 0);
                }
                cout << cnt << "\n";
                int p = 1;
                for(int x: v){
                        if(x){
                                cout << x * p << " ";
                        }
                        p *= 10;
                }
                cout << "\n";
        }
}