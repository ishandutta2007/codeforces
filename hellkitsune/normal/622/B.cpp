#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;

int getInt(string s) {
    s[2] = ' ';
    istringstream iss(s);
    int h, m;
    iss >> h >> m;
    return 60 * h + m;
}

string getString(int t) {
    ostringstream oss;
    oss << t / 600;
    t %= 600;
    oss << t / 60;
    t %= 60;
    oss << ":";
    oss << t / 10;
    t %= 10;
    oss << t;
    return oss.str();
}

int main() {
    string s;
    int a;
    cin >> s >> a;
    a = (a + getInt(s)) % (24 * 60);
    cout << getString(a) << endl;
    return 0;
}