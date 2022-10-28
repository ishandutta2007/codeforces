#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
void solve(){
    int n;
    cin>>n;
    vector<array<ll, 2>> games(n);
    for(auto &[s, e] : games){
        cin>>s>>e;
    }
    array<array<int, 2>, 2> cases;
    cases[0][0] = 1;
    cases[0][1] = 0;
    cases[1][0] = 0;
    cases[1][1] = 1;
    reverse(games.begin(), games.end());
    function<int(ll, ll)> force_win = [&](ll s, ll e) -> int{
        if(e <= 3 || e % 2 == 1 || 2 * s > e){
            return (s % 2 == e % 2);
        }
        if(s > e / 4){
            return 0;
        }
        return force_win(s, e / 4);
        return 1;
    };
    auto force_lose = [&](ll s, ll e){
        if(2 * s > e) return 0;
        return force_win(s, e / 2);
    };
    auto game_solve = [&](ll s, ll e){
        array<array<int, 2>, 2> win;
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) win[i][j] = 0;
        win[force_win(s, e)][1] = 1;
        win[force_lose(s, e)][0] = 1;
        return win;
    };
    for(auto &[s, e] : games){
        array<array<int, 2>, 2> win = game_solve(s, e);
        auto newcases = cases;
        newcases[0][0] = (win[0][0] & cases[0][0]) | (win[0][1] & cases[1][0]);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                newcases[i][j] = (win[i][0] & cases[0][j]) | (win[i][1] & cases[1][j]);
            }
        }
        cases = newcases;
    }
    cout<<cases[0][1]<<" "<<cases[0][0]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}