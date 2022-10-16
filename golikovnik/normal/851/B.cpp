#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'
#define X first
#define Y second

struct point{
    int x, y;

    point operator-(const point &other) const{
        return {x - other.x, y - other.y};
    }

    long long operator*(const point &other) const{
        return 1LL * x * other.y - 1LL * y * other.x;
    }

    long long operator %(const point &other) const {
        return 1LL * (other.x - x) * (other.x - x) + 1LL * (other.y - y) * (other.y - y);
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    point a = {ax, ay};
    point b = {bx, by};
    point c = {cx, cy};
    if ((b - a) * (c - a) == 0 || (a % b != b % c)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}