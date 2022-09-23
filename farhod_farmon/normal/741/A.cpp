#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 110;

using namespace std;

int n;
int p[N];
bool used[N];

void df(int x)
{
    if(used[x])
        return;
    used[x] = true;
    df(p[x]);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    long long ans = 1;
    for(int i = 1; i <= n; i++){
        int x = p[i];
        for(long long j = 1; j <= n; j++){
            if(x == i){
                if(j % 2)
                    ans = ans * j / __gcd(ans, j);
                else
                    ans = ans * (j / 2) / __gcd(ans, j / 2);
                df(i);
                break;
            }
            else
                x = p[x];
        }
    }
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}