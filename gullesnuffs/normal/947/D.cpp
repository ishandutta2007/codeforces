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

int trailingAs[2][100005];
int numBCs[2][100005];

string rec2(string s, int depth) {
    if (depth > 20)
        return s;
    int ind = rand()%s.size();
    int i = ind;
    string t;
    if (s[i] == 'B') {
        t = s.substr(0, ind) + "AC" + s.substr(ind+1);
    }
    else if(s[i] == 'C')
        t = s.substr(0, ind) + "AC" + s.substr(ind+1);
    else if(s[i] == 'A') {
        if (rand()%10 && ind+2 < s.size() && s[i+1] == 'A' && s[i+2] == 'A') {
            t = s.substr(0, ind) + s.substr(ind+3);
        }
        else {
            t = s.substr(0, ind) + "BC" + s.substr(ind+1);
        }
    }
    if (t.size() == 0)
        return s;
    return rec2(t, depth+1);
}

bool rec(string s, string T, int depth) {
    if (s == T)
        return true;
    if (depth > 20)
        return false;
    int ind = rand()%s.size();
    int i = ind;
    string t;
    if (s[i] == 'B') {
        t = s.substr(0, ind) + "AC" + s.substr(ind+1);
    }
    else if(s[i] == 'C')
        t = s.substr(0, ind) + "AC" + s.substr(ind+1);
    else if(s[i] == 'A') {
        if (rand()%2 && ind+2 < s.size() && s[i+1] == 'A' && s[i+2] == 'A') {
            t = s.substr(0, ind) + s.substr(ind+3);
        }
        else {
            t = s.substr(0, ind) + "BC" + s.substr(ind+1);
        }
    }
    return rec(t, T, depth+1);
}

bool getAns(int bc, int ta, int bc2, int ta2) {
    assert(bc > 0 || ta > 0);
    assert(bc2 > 0 || ta2 > 0);
    if (bc%2 != bc2%2)
        return false;
    else if(bc > bc2)
        return false;
    else if(bc < bc2) {
        assert(bc%2 == bc2%2);
        if (bc == 0 && ta == ta2)
            return false;
        else if (ta >= ta2)
            return true;
        else
            return false;
    }
    else {
        assert(bc == bc2);
        if (ta%3 != ta2%3)
            return false;
        else if (ta < ta2)
            return false;
        else
            return true;
    }
}

string getRandomString() {
    int len = (rand()%7) + 1;
    string s;
    rep(i,0,len) {
        if (rand()%3 == 0)
            s.push_back('A');
        else if (rand()%2 == 1)
            s.push_back('B');
        else
            s.push_back('C');
    }
    return s;
}

int getTrailingAs(string s) {
    int i;
    for (i = 0; i < s.size() && s[s.size()-i-1] == 'A'; i++);
    return i;
}

int getBCs(string s) {
    int ans = 0;
    rep(i,0,sz(s))
        if (s[i] == 'B' || s[i] == 'C')
            ++ans;
    return ans;
}

int main(){
    while (false) {
        string s1 = getRandomString();
        string s2 = rec2(s1, rand()%25);
        //cout << s1 << " " << s2 << endl;
        bool myAns = getAns(getBCs(s1), getTrailingAs(s1), getBCs(s2), getTrailingAs(s2));
        assert(myAns);
    }
	ios::sync_with_stdio(0);
    string s[2];
    cin >> s[0] >> s[1];
    rep(i,0,2) {
        rep(j,0,sz(s[i])) {
            if (s[i][j] == 'A') {
                trailingAs[i][j+1] = trailingAs[i][j] + 1;
                numBCs[i][j+1] = numBCs[i][j];
            }
            else {
                trailingAs[i][j+1] = 0;
                numBCs[i][j+1] = numBCs[i][j] + 1;
            }
        }
    }
    int Q;
    cin >> Q;
    while(Q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a;--c;
        int bc = numBCs[0][b] - numBCs[0][a];
        int ta = min(trailingAs[0][b], b-a);
        int bc2 = numBCs[1][d] - numBCs[1][c];
        int ta2 = min(trailingAs[1][d], d-c);
        if (getAns(bc, ta, bc2, ta2)) {
            assert(ta >= ta2);
            cout << "1";
        }
        else
            cout << "0";
    }
}