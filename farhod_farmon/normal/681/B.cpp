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

using namespace std;

int n;
int a = 1234567;
int b = 123456;
int c = 1234;

void f()
{
    for(int i = 0; i <= n / a; i++){
        for(int j = 0; j <= n / b; j++){
            int h = (n - a * i - b * j) / c;
            if(h >= 0 && a * i + b * j + c * h == n){
                cout << "YES" << endl;
                exit(0);
            }
        }
    }
}

int main()
{
    cin >> n;
    f();
    cout << "NO" << endl;
}