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

const int N = 100100;

using namespace std;

long long n, k, cnt;
bool used[1000];

void build(long long x, long long mx)
{
    if(x > mx)
        return;
    if(x)
        cnt++;
    build(x * 10 + 4, mx);
    build(x * 10 + 7, mx);
}

bool check(long long x)
{
    while(x){
        if(x % 10 != 4 && x % 10 != 7)
            return false;
        x /= 10;
    }
    return true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    long long f = 1, g = 1;
    for(long long i = 1; i <= n; i++){
        f *= i;
        if(f >= k){
            g = i;
            break;
        }
    }
    if(f < k){
        cout << -1 << endl;
        return 0;
    }
    vector < long long > v;
    for(long long i = g; i >= 1; i--){
        f /= i;
        long long s = 0;
        for(long long j = 1; j <= g; j++){
            if(used[j])
                continue;
            else
                s++;
            if(f * (s - 1) + 1 <= k && k <= f * s){
                k -= f * (s - 1);
                used[j] = true;
                v.pb(j);
                break;
            }
        }
    }
    build(0, n - g);
    for(int i = 0; i < v.size(); i++)
        if(check(n - g + i + 1) && check(n - g + v[i]))
            cnt++;
    cout << cnt << endl;
}