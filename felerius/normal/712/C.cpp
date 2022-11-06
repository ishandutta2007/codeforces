#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    // bi = ai + a_i+1

    int x,y; cin>>x>>y; // grow from y to x

    array<int,3> sides{y,y,y};
    int res = 0;
    while(*min_element(all(sides)) < x) {
        auto mn = min_element(all(sides));
        auto next = 0;
        for(auto it=begin(sides); it!=end(sides); ++it) {
            if(it!=mn) next += *it;
        }
        *mn = next-1;
        res++;
    }
    cout << res << endl;


    return 0;
}