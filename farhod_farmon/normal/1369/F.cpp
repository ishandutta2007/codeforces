#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;

using namespace std;

int w(long long s, long long e)
{
        if(e % 2){
                return (s % 2) ^ 1;
        }
        if(s > e / 2){
                return s % 2;
        }
        if(s > e / 4){
                return 1;
        }
        return w(s, e / 4);
}

int l(long long s, long long e)
{
        if(s * 2 > e){
                return 1;
        }
        return w(s, e / 2);
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int n;
        cin >> n;
        vector < pair < int, int > > v;
        for(int i = 0; i < n; i++){
                long long s, e;
                cin >> s >> e;
                v.push_back({w(s, e), l(s, e)});
        }
        int x = 0, y = 1;
        for(auto p: v){
                int nx = x, ny = x;
                if(p.fi) nx = y;
                if(p.se) ny = y;
                x = nx;
                y = ny;
        }
        cout << x << " " << y << "\n";
}