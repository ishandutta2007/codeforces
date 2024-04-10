#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 1010;

using namespace std;

long long ask(int a, int b, int c)
{
        int g;
        cout << "? " << a << " " << b << " " << c << endl;
        cin >> g;
        return g;
}

long long sum(int a, int b, int c, int d)
{
        vector < long long > v;
        v.push_back(ask(a, b, c));
        v.push_back(ask(a, b, d));
        v.push_back(ask(a, c, d));
        v.push_back(ask(b, c, d));
        sort(v.begin(), v.end());
        return v[0] + v[3];
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector < long long > ans(n);
        ans[0] = sum(2, 3, 4, 5);
        ans[1] = sum(1, 3, 4, 5);
        ans[2] = sum(1, 2, 4, 5);
        ans[3] = sum(1, 2, 3, 5);
        ans[4] = sum(1, 2, 3, 4);
        long long sum5 = (ans[0] + ans[1] + ans[2] + ans[3] + ans[4]) / 4;
        for(int i = 0; i < n; i++){
                if(i < 5){
                        ans[i] = sum5 - ans[i];
                }
                else{
                        ans[i] = sum(1, 2, 3, i + 1) - ans[0] - ans[1] - ans[2];
                }
        }
        cout << "!";
        for(int i = 0; i < n; i++){
                cout << " " << ans[i];
        }
        cout << endl;
}