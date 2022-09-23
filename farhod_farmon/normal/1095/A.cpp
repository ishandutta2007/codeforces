#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
char c[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        for(int i = 1, j = 1; i <= n; i += j){
                j++;
                cout << c[i];
        }
}