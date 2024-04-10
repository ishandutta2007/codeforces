#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

bool d[N];
int f[N][7];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        int c[3] = {0, 0, 0};
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                c[x] += 1;
        }
        if(c[2] >= 1){
                cout << 2 << " ";
                c[2] -= 1;
        }
        if(c[1] >= 1){
                cout << 1 << " ";
                c[1] -= 1;
        }
        while(c[2]){
                cout << 2 << " ";
                c[2]--;
        }
        while(c[1]){
                cout << 1 << " ";
                c[1]--;
        }
}