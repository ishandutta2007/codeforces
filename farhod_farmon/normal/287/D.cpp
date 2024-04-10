#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1000010;

using namespace std;

int n, a[N + N];

int main()
{
	//fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        a[i] = i;
    for(int i = 2; i <= n; i++){
        int lst = a[i - 1];
        for(int j = i - 1; j <= n + i - 2; j += i){
            int r = min(n + i - 1, j + i);
            int tmp = a[r];
            a[r] = lst;
            lst = tmp;
        }
    }
    for(int i = n; i <= n + n - 1; i++)
        cout << a[i] << " ";
}