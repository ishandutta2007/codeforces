#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
vector<int> h[maxn];
ll first , last , a[maxn] , res , t;
void fx()
{
    while(h[last].size() == 0)
        last--;
}
int main()
{
    int n , s;
    cin >> n >> s;
    s--;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i == s && a[i] != 0)
        {
            h[0].pb(i);
            res++;
            continue;
        }
        if(a[i] == 0 && i != s)
        {
            t++;
            continue;
        }
        last = max(last , a[i]);
        h[a[i]].pb(i);
    }
    while(first <= last)
    {
        while(h[first].size() != 0)
            first++;
        if(first > last)
            break;
        if(t)
            t-- , h[first].pb(1);
        else
        {
            h[first].pb(h[last].back());
            h[last].pop_back();
            fx();
        }
        res++;
    }
    cout << res + t;
}