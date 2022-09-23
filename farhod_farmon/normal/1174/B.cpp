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
        int good = 0;
        vector < int > a(n);
        for(int i = 0; i < n; i++){
                cin >> a[i];
                good |= 1 << (a[i] & 1);
        }
        if(good == 3){
                sort(a.begin(), a.end());
        }
        for(int x: a){
                cout << x << " ";
        }
}