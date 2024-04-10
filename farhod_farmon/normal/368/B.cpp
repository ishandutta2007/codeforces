#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n, m;
int c;
int a[N];
int ans[N];
bool used[N];
pair < int, int > p[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++){
        cin >> p[i].fi;
        p[i].se = i;
    }
    sort(p + 1, p + m + 1);
    int j = m;
    for(int i = n; i >= 1; i--){
        int x = a[i];
        if(!used[x]){
            used[x] = true;
            c++;
        }
        while(j >= 1 && p[j].fi >= i){
            ans[p[j].se] = c;
            j = j - 1;
        }
    }
    for(int i = 1; i <= m; i++)
        cout << ans[i] << endl;
}