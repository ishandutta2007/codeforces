#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long MX = 1000100;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int a[N];
int b[N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= k; i++){
                cin >> b[i];
        }
        sort(b + 1, b + k + 1);
        int j = k;
        bool ans = false;
        for(int i = 1; i <= n; i++){
                if(a[i] == 0){
                        a[i] = b[j];
                        j--;
                }
                if(a[i] <= a[i - 1]){
                        ans = true;
                }
        }
        if(ans){
                cout << "Yes" << "\n";
        }
        else{
                cout << "No" << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("cowjog.in");
        //fout("cowjog.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}