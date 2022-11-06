
#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define debug(x)    clog << #x << " = " << x << endl;
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n; cin >> n;

    string l,r; cin >> l >> r;

    vector<pair<int,int>> ans;

    vector<int> lq;
    vector<int> rq;
    auto locc = vector<vector<int>>(26);
    auto rocc = vector<vector<int>>(26);
    rep(i, l.size())
        if(l[i]=='?') lq.push_back(i+1);
        else locc[l[i]-'a'].push_back(i+1);
    rep(i, r.size())
        if(r[i]=='?') rq.push_back(i+1);
        else rocc[r[i]-'a'].push_back(i+1);

    vector<int> lleft;
    vector<int> rleft;
    rep(i,26){
        int j=0;
        for(; j<locc[i].size() && j<rocc[i].size();++j)
            ans.emplace_back(locc[i][j], rocc[i][j]);
        for(int k=j; k<locc[i].size(); ++k) lleft.push_back(locc[i][k]);
        for(int k=j; k<rocc[i].size(); ++k) rleft.push_back(rocc[i][k]);
    }

    // combine left ? with right left
    int i=0;
    for(; i<lq.size(); ++i)
        if(i<rleft.size()) ans.emplace_back(lq[i], rleft[i]);
        else break;
    // combine right ? with left left
    int j=0;
    for(; j<rq.size(); ++j)
        if(j<lleft.size()) ans.emplace_back(lleft[j], rq[j]);
        else break;

    // combine right and left ?
    for(; i<lq.size() && j < rq.size(); i++, j++)
        ans.emplace_back(lq[i], rq[j]);

    cout << ans.size() << endl;
    for(auto each : ans) cout << each.first << ' ' << each.second << endl;

    return 0;
}