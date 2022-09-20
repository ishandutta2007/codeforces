#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 155;

using namespace std;

int n;
int m;

void add(int &x, int y)
{
        x += y;
        if(x >= m){
                x -= m;
        } else if(x < 0){
                x += m;
        }
}

int d[4000004];
int s[4000004];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        d[1] = 1;
        for(int i = 1; i <= n; i++){
                add(s[i], s[i - 1]);

                add(d[i], s[i]);
                add(s[i + 1], d[i]);
                for(int k = 2; i * k <= n; k++){
                        add(s[i * k], d[i]);
                        add(s[min(n + 1, (i + 1) * k)], -d[i]);
                        //cout << i << " " << i * k << "\n";
                }
                //cout << i << " " << d[i] << " " << s[i] << "\n";
        }

        cout << d[n] << "\n";
}