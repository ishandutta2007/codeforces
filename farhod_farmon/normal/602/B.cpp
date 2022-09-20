#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }

        int t = 0, p = 0, res = 0;

        for(int i = 1, R = 1; i <= n; i++){
                while(R < n && (a[R + 1] - a[R] != t || a[R + 1] - a[R] == 0)){
                        if(a[R + 1] - a[R] != 0){
                                t = a[R + 1] - a[R];
                                p = R;
                        }
                        R += 1;
                }

                res = max(res, R - i + 1);

                if(i >= p){
                        t = 0;
                }
        }

        cout << res << "\n";
}