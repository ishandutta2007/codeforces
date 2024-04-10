#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 2020;

using namespace std;

int n;
char a[N];
char b[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    int l = (n + 1) / 2,
        r = l + 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i % 2){
            b[l] = a[i];
            l--;
        }
        else{
            b[r] = a[i];
            r++;
        }
    }
    if(n % 2){
        for(int i = n; i >= 1; i--)
            cout << b[i];
    }
    else{
        for(int i = 1; i <= n; i++)
            cout << b[i];
    }
}