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

int n;
int a[N];
int p[N];
bool used[N];
vector < int > v;
vector < pair < int, int > > ans;

void f(int i, int j)
{
    if(i > j)
        swap(i, j);
    swap(a[i], a[j]);
    swap(p[a[i]], p[a[j]]);
    ans.pb({i, j});
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    for(int i = 2; i * i < N; i++){
        if(used[i])
            continue;
        for(int j = i * i; j < N; j += i)
            used[j] = 1;
    }
    for(int i = 2; i < N; i++)
        if(!used[i])
            v.pb(i);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        while(p[i] != i){
            int g = lower_bound(v.begin(), v.end(), p[i] - i + 1) - v.begin();
            while(v[g] > p[i] - i + 1)
                g--;
            f(p[i], p[i] - v[g] + 1);
        }
    }
    cout << ans.size() << endl;
    for(auto x: ans)
        cout << x.fi << " " << x.se << endl;
}