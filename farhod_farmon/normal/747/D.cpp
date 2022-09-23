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
int k;
int ans;
int a[N];
vector < int > v;

int sign(int x)
{
    if(x >= 0)
        return 1;
    else
        return -1;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(sign(a[i]) == -1)
            k--;
    }
    if(k < 0){
        cout << -1 << endl;
        return 0;
    }
    int last = -1;
    if(sign(a[1]) == -1){
        ans++;
        last = 1;
    }
    for(int i = 2; i <= n; i++){
        if(sign(a[i]) != sign(a[i - 1])){
            ans++;
            if(sign(a[i]) == -1 && last != -1)
                v.pb(i - last - 1);
        }
        if(sign(a[i]) == -1)
            last = i;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        if(v[i] <= k){
            k -= v[i];
            ans -= 2;
        }
    }
    if(sign(a[n]) != -1 && last != -1 && n - last <= k)
        ans--;
    cout << ans << endl;
}