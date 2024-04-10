#include <bits/stdc++.h>
#define MOD 998244353 
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

struct Node {
    vector<Node*> same;
    vector<Node*> different;
    bool isFixed;
    bool fixedValue;

    bool setFixed(bool value) {
        if (isFixed && value != fixedValue)
            return false;
        if (isFixed)
            return true;
        isFixed = true;
        fixedValue = value;
        bool ok = true;
        for (Node* to : same) {
            ok &= to->setFixed(value);
        }
        for (Node* to : different) {
            ok &= to->setFixed(!value);
        }
        return ok;
    }

    void addAdj(Node* to, bool areDifferent) {
        if (areDifferent) {
            different.push_back(to);
            to->different.push_back(this);
        } else {
            same.push_back(to);
            to->same.push_back(this);
        }
    }
};

int main(){
	ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int m = sz(s);
    ll ans = 0;
    rep(i,1,m) {
        vector<Node> aNodes(m);
        vector<Node> bNodes(m);
        vector<Node*> allNodes;
        rep(j,0,m) {
            allNodes.push_back(&aNodes[j]);
            allNodes.push_back(&bNodes[j]);
        }
        rep(j,0,m) {
            aNodes[j].addAdj(&aNodes[m-1-j], 0);
        }
        rep(j,i,m) {
            bNodes[j].addAdj(&bNodes[m-1-(j-i)], 0);
        }
        rep(j,0,m) {
            if (s[j] != '?') {
                aNodes[j].addAdj(&bNodes[j], s[j] - '0');
            }
        }
        bool ok = aNodes[0].setFixed(1);        
        ok &= bNodes[i].setFixed(1);        
        rep(j,0,i) {
            ok &= bNodes[j].setFixed(0);
        }
        ll add = ok;
        for (Node* node : allNodes) {
            if (!node->isFixed) {
                node->setFixed(0);
                add = (add*2)%MOD;
            }
        }
        ans += add;
    }
    ans %= MOD;
    cout << ans << endl;
}