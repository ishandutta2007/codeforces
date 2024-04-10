#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 220;

using namespace std;

int n;
int k;
int a[N];

int get(int l, int r)
{
    vector < int > v1, v2;
    for(int i = 1; i <= n; i++){
        if(l <= i && i <= r)
            v1.push_back(a[i]);
        else
            v2.push_back(a[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int j = v2.size() - 1;
    int s = 0;
    int g = k;
    for(int i = 0; i < v1.size(); i++){
        if(j >= 0 && v2[j] > v1[i] && g){
            v1[i] = v2[j];
            j--;
            g--;
        }
        s += v1[i];
    }
    return s;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    int ans = -1e9;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            ans = max(ans, get(i, j));
    cout << ans << endl;
}