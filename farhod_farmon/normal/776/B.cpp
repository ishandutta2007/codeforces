#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;
const int MX = 1024;
const int MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
bool used[N];

void solve()
{
    for(int i = 2; i < N; i++){
        if(used[i])
            continue;
        for(int j = i + i; j < N; j += i)
            used[j] = true;
    }
    cin >> n;
    if(n <= 2)
        cout << 1 << endl;
    else
        cout << 2 << endl;
    for(int i = 2; i <= n + 1; i++){
        cout << used[i] + 1 << " ";
    }
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