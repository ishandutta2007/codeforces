#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 1000100;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n);
                set < int > s;
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        for(int j = 0; j < i; j++){
                                s.insert(a[i] - a[j]);
                        }
                }
                cout << s.size() << "\n";
        }
}