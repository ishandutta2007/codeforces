#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;
const int MX = 10010;

using namespace std;

int n;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    int a = 1, b = n;
    for(int i = 2; i * i <= n && i <= n / i; i++){
        if(n % i == 0 && abs(i - n / i) < abs(a - b)){
            a = i;
            b = n / i;
        }
    }
    cout << a << " " << b << endl;
}