#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                int n;
                cin >> n;
                vector < int > a;
                for(int i = 0; i < n; i++){
                        int x;
                        cin >> x;
                        x += i;
                        x %= n;
                        if(x < 0){
                                x += n;
                        }
                        a.push_back(x);
                }
                sort(a.begin(), a.end());
                int res = 1;
                for(int i = 0; i < n; i++){
                        if(a[i] != i){
                                res = 0;
                        }
                }
                cout << (res ? "YES" : "NO") << "\n";
        }
}