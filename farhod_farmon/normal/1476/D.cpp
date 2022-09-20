#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 600600;

using namespace std;

int n;
int s[N];
int p[N];

int get(int x) { return p[x] == x ? x : p[x] = get(p[x]); }

void make(int x, int y)
{
        x = get(x);
        y = get(y);
        if(x != y){
                p[x] = y;
                s[y] += s[x];
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                string f;
                cin >> n >> f;
                for(int i = 0; i <= n * 2 + 1; i++){
                        p[i] = i;
                        s[i] = 1;
                }
                for(int i = 0; i < n; i++){
                        if(f[i] == 'L'){
                                make(i + 1, (n + 1) + i);
                        } else{
                                make(i, (n + 1) + i + 1);
                        }
                }
                for(int i = 0; i <= n; i++){
                        cout << s[get(i)] << " ";
                }
                cout << "\n";
        }
}