#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const long long mod = 1e9 + 7;

using namespace std;

int n;
vector < int > a[200];
vector < int > b[200];
vector < pair < int, int > > res;

bool add(int x, int y)
{
        if(!a[x].empty() && !b[y].empty()){
                res.push_back({a[x].back(), b[y].back()});
                a[x].pop_back();
                b[y].pop_back();
                return true;
        }
        return false;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                a[c].push_back(i);
        }
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                b[c].push_back(i);
        }
        for(int i = 'a'; i <= 'z'; i++){
                while(add(i, i));
        }
        for(int i = 'a'; i <= 'z'; i++){
                while(add(i, '?'));
                while(add('?', i));
        }
        while(add('?', '?'));
        cout << res.size() << "\n";
        for(auto p: res){
                cout << p.fi << " " << p.se << "\n";
        }
}