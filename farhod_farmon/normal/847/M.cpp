#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int a[N];

void solve()
{
        cin >> n;
        set < int > s;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(i > 1){
                        s.insert(a[i] - a[i - 1]);
                }
        }
        if(s.size() == 1){
                cout << a[n] + *s.begin() << "\n";
        }
        else{
                cout << a[n] << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}