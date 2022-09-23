#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 303;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        n *= 2;
        vector < int > a(n);
        for(int i = 0; i < n; i++){
                cin >> a[i];
        }
        sort(a.begin(), a.end());
        if(a[0] == a[n - 1]){
                cout << -1 << "\n";
        } else{
                for(int x: a){
                        cout << x << " ";
                }
        }
}