#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

long long n;
char c;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> c;
    int g;
    if(c == 'f')
        g = 1;
    if(c == 'e')
        g = 2;
    if(c == 'd')
        g = 3;
    if(c == 'a')
        g = 4;
    if(c == 'b')
        g = 5;
    if(c == 'c')
        g = 6;
    if(n % 4 == 1 || n % 4 == 2){
        long long x = (n / 4) * 2 + 1;
        if(n % 4 == 2)
            x++;
        cout << (x - 1) * 6 + n - 1 + g << endl;
    }
    else{
        long long x = ((n - 1) / 4) * 2 + 1;
        if(n % 4 == 0)
            x++;
        cout << (x - 1) * 6 + n - 3 + g << endl;
    }
}