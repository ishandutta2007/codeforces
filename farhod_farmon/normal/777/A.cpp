#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const ll N = 100100;
const ll MX = 1e16;
const ll MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int f(int n, int k)
{
    if(n <= 0)
        return k;
    if(n % 6 == 1 || n % 6 == 4)
        return 1;
    if(n % 6 == 2 || n % 6 == 3)
        return 2 - k;
    return k;
}

int slow_f(int n, int k)
{
    int a[3] = {0, 0, 0};
    a[k] = 1;
    for(int i = n; i >= 1; i--){
        if(i % 2)
            swap(a[0], a[1]);
        else
            swap(a[1], a[2]);
    }
    if(a[0] == 1)
        return 0;
    if(a[1] == 1)
        return 1;
    return 2;
}

int fast_f(int n, int k)
{
    if(f(n, 0) == k)
        return 0;
    else if(f(n - 1, 2) == k)
        return 2;
    else
        return 1;
}

int n;
int k;

void solve()
{
    cin >> n >> k;
    /*
    for(int i = 1; i <= 10; i++){
        for(int j = 0; j < 3; j++){
            n = i;
            k = j;
            if(slow_f(n, k) != fast_f(n, k))
                break;
        }
        if(slow_f(n, k) != fast_f(n, k))
            break;
    }
    cout << n << " " << k << endl;
    cout << slow_f(n, k) << " " << fast_f(n, k) << endl;
    */
    cout << fast_f(n, k) << endl;
}


bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("friendcross.in");
    //fout("friendcross.out");
    ios_base::sync_with_stdio(0);
    int TE = 1;
    if(mtest)
        cin >> TE;
    while(TE--)
        solve();
}