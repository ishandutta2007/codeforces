#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;

using namespace std;

int n;
bool used[10];

bool f(int x)
{
    for(int i = 0; i <= 9; i++)
        used[i] = 0;
    while(x){
        if(used[x % 10])
            return false;
        used[x % 10] = true;
        x /= 10;
    }
    return true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    n = n + 1;
    while(!f(n))
        n = n + 1;
    cout << n << endl;
}