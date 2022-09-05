#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;

vector<vector<string>> read(int h, int w) {
    vector<vector<string>> grid(h, vector<string>(w));
    for(int row = 0; row < h; ++row) {
        for(int col = 0; col < w; ++col) {
            cin >> grid[row][col];
        }
    }
    return grid;
}

vector<vector<int>> all;

void _add(int r, int c, int r2, int c2) {
    assert(make_pair(r, c) != make_pair(r2, c2));
    assert(r == r2 || c == c2);
    all.push_back({r, c, r2, c2});
}

void f(int r, int c, int r2, int c2) {
    if(make_pair(r, c) == make_pair(r2, c2)) {
        // two moves
        assert(false);
    }
    else if(r == r2 || c == c2) {
        _add(r, c, r2, c2);
    }
    else {
        _add(r, c, r, c2);
        _add(r, c2, r2, c2);
    }
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int h, w;
    cin >> h >> w;
    auto A = read(h, w);
    int total = 0;
    for(auto rr : A) {
        for(auto ss : rr) {
            total += ss.length();
        }
    }
    auto B = read(h, w);
    vector<vector<int>> cnt(w, vector<int>(2));
    for(int row = 0; row < h; ++row) {
        for(int col = 0; col < w; ++col) {
            reverse(A[row][col].begin(), A[row][col].end());
            for(char ch : A[row][col]) {
                int type = ch - '0';
                if(row == type) {
                    if(col == 0) {
                        _add(row, col, row, 1);
                        ++cnt[1][type];
                    }
                    else {
                        _add(row, col, row, 0);
                        ++cnt[0][type];
                    }
                }
                else {
                    _add(row, col, type, col);
                    ++cnt[col][type];
                }
            }
            reverse(A[row][col].begin(), A[row][col].end());
        }
    }
    for(int row = 0; row < 2; ++row) {
        for(int col = 0; col < w; ++col) {
            if(row != col) {
                for(int rep = 0; rep < cnt[col][row]; ++rep) {
                    _add(row, col, row, row);
                    //~ ++cnt[0][row];
                }
            }
        }
    }
    //~ debug() << imie(cnt[0][0]) imie(cnt[0][1]);
    
    for(int row = h - 1; row >= 2; --row) {
        for(int col = w - 1; col >= 0; --col) {
            //~ if(col == 0 && row <= 1) {
                //~ continue;
            //~ }
            string s = B[row][col];
            //~ if(col == 1 && row <= 1) {
                //~ s += B[row][0];
            //~ }
            reverse(s.begin(), s.end());
            for(char ch : s) {
                int type = ch - '0';
                f(type, type, row, col);
            }
        }
    }
    string one = B[0][1] + B[0][0];
    for(int col = 2; col < w; ++col) {
        one += B[0][col];
    }
    reverse(one.begin(), one.end());
    for(char ch : one) {
        int type = ch - '0';
        _add(type, type, 0, 1);
    }
    string two;
    for(int col = 0; col < w; ++col) {
        two += B[1][col];
    }
    reverse(two.begin(), two.end());
    for(char ch : two) {
        int type = ch - '0';
        _add(type, type, 1, 0);
    }
    for(int row = 0; row < 2; ++row) {
        for(int col = w - 1; col >= 0; --col) {
            if(!(col < 2 && col != row)) {
                for(int rep = 0; rep < (int) B[row][col].length(); ++rep) {
                    _add(row, row^1, row, col);
                }
            }
        }
    }
    debug() << imie(4 * total) imie(all.size());
    assert((int) all.size() <= 4 * total);
    //~ return 0;
    printf("%d\n", (int) all.size());
    for(vector<int> vec : all) {
        
        //~ int r = vec[0], c = vec[1], r2 = vec[2], c2 = vec[3];
        //~ assert(!A[r][c].empty());
        //~ A[r2][c2] = A[r][c].back() + A[r2][c2];
        //~ A[r][c].pop_back();
        
        for(int x : vec) printf("%d ", x + 1);
        puts("");
    }
    //~ for(int row = 0; row < h; ++row) {
        //~ debug dd;
        //~ for(int col = 0; col < w; ++col) {
            //~ dd << ">" << A[row][col] << " ";
            //~ assert(A[row][col] == B[row][col]);
        //~ }
        
    //~ }
}