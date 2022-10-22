#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N;
        vector<string> S(N); for(auto&x: S) cin >> x;
        bool ans = false;
        for(auto x: S)
            if(x.back() == x.front()) ans = true;

        if(!ans)
        {
            set<string> f2, f3, f2p;
            for(auto x: S)
            {
                if(x.size() == 2) f2.insert(x);
                else f3.insert(x);
                f2p.insert(string({x[0], x[1]}));
                if(x.size() == 2)
                    if(f2p.count({x[1], x[0]})) ans = true;

                if(x.size() == 3)
                {
                    if(f2.count(string({x[2], x[1]}))) ans = true;
                    if(f3.count(string({x[2], x[1], x[0]}))) ans = true;
                }
            }
        }
        cout << (ans ? "YES": "NO") << endl;
    }
}