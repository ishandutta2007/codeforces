    #include <bits/stdc++.h>
    #define ll long long
    #define pb push_back
    #define mp make_pair
    #define fi first
    #define se second
    #define pll pair<ll,ll>
    #define pii pair<int,int>

    using namespace std;

    ll n, m, i, j, k, l, ans, r, a[500001], T, o, an=0, b[101];
    vector <ll> v;

    int main()
    {
        ios_base::sync_with_stdio(0);
        cin >> n;
        for (int i = 1; i <= n; i++)
        {for (int j = 1; j <= n; j++)
            {
                if ((i%2+j%2)%2==0) cout << "W"; else cout << "B";
            }cout << "\n";}
        return 0;
    }
    /*
    8 7
    1 1 30 5 5 1 1 1
    1 2
    2 3
    2 4
    4 5
    2 6
    6 7
    6 8
    2
    */