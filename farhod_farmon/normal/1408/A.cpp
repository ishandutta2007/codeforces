#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n), b(n), c(n);
                for(int i = 0; i < n; i++) cin >> a[i];
                for(int i = 0; i < n; i++) cin >> b[i];
                for(int i = 0; i < n; i++) cin >> c[i];
                cout << a[0] << " ";
                int last = a[0];
                set < int > S;
                for(int i = 1; i < n; i++){
                        S.clear();
                        S.insert(last);
                        if(i == n - 1){
                                S.insert(a[0]);
                        }
                        for(int x: {a[i], b[i], c[i]}){
                                if(S.find(x) == S.end()){
                                        last = x;
                                }
                        }
                        cout << last << " ";
                }
                cout << "\n";
        }
}