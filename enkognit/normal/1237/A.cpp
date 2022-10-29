#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;

int n, m, it, i, p, k, T, j, A, B, C, y, kol, a[200001], b[200001];
bool tt[200001];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i]%2) tt[i]=1;
        if (a[i]<0 && a[i]%2) a[i]--;

        a[i]/=2;
        //cout << a[i] << "\n";
        T+=a[i];
    }
    //cout << T << "\n";
    for (int i = 0; i < n; i++)
    {
        if (tt[i])
        {
            if (T<0)a[i]++,T++;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << "\n";
}

/*
5 4 4
1 2
3 1
3 4
5 3
4 5 2 3
2 1 3 1
1 3 5
2 3 4 5
2 1 3 1
*/