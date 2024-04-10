#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int cnt, n, m, k;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x == 1){
            if(m)
                m--;
            else
                cnt++;
        }
        else{
            if(k)
                k--;
            else if(m)
                m--;
            else
                cnt++;
        }
    }
    cout << cnt << endl;
}