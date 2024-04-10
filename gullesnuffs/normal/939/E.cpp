#include <bits/stdc++.h>
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

vector<int> S;

int main(){
	ios::sync_with_stdio(0);
    int Q;
    cin >> Q;
    double ans = 0;
    double sum = 0;
    int pos = 0;
    while(Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s;
            cin >> s;
            S.push_back(s);
            while (pos+1 < S.size()) {
                double newSum = sum + S[pos];
                double M1 = (sum+S.back())/(pos+1.0);
                double M2 = (newSum+S.back())/(pos+2.0);
                if (M2 < M1) {
                    sum = newSum;
                    ++pos;
                }
                else {
                    break;
                }
            }
            ans = S.back() - (sum+S.back())/(pos+1.0);
        }
        else {
            cout << setprecision(9) << fixed << ans << endl;
        }
    }
}