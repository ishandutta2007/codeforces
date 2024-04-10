#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100020;

using namespace std;

int n, m, d;
int a[N];
int c[21];
bool used[1 << 21];

void update()
{
    int mask = 0;
    for(int i = 0; i < m; i++)
        if(c[i] == 0)
            mask |= 1 << i;
    used[mask] = true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> d;
    for(int i = 1; i <= m; i++){
        int s;
        cin >> s;
        for(int j = 1; j <= s; j++){
            int x;
            cin >> x;
            a[x] = i - 1;
        }
    }
    for(int i = 1; i < d; i++)
        c[a[i]]++;
    for(int i = d; i <= n; i++){
        c[a[i]]++;
        update();
        c[a[i - d + 1]]--;
    }
    int ans = m;
    for(int i = (1 << m) - 1; i >= 0; i--){
        if(used[i]){
            for(int j = 0; j < m; j++)
                if(i & (1 << j))
                    used[i ^ (1 << j)] = true;
        }
        else
            ans = min(ans, __builtin_popcount(i));
    }
    cout << ans << endl;
}