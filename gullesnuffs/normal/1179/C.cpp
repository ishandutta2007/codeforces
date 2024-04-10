#include <bits/stdc++.h>
#define OFFSET (1<<20)
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

struct Tree {
	typedef int T;
	vector<T> s; int n;
    vector<int> maxVal;
	Tree(int n = 0) : s(2*n, 0), n(n), maxVal(2*n, 0) {}
	void update(int b, int e, T diff) {
        if (b < e) {
            if (b%2) {
                s[b] += diff;
            }
            if (e%2) {
                s[e-1] += diff;
            }
        }
        /*fix(b-1);
        fix(b);
        fix(e);
        fix(e+1);*/
        /*rep(i,b-2,b+3) {
            fix(i);
        }
        rep(i,e-2,e+3) {
            fix(i);
        }*/
        fix((b/2)*2);
        fix((b/2)*2+1);
        fix((e/2)*2);
        fix((e/2)*2+1);
        if (b == 1)
            return;
        update((b+1)/2, e/2, diff);
	}

    void doUpdate(int b, int e, T diff) {
        if (b > e) {
            doUpdate(e, b, -diff);
        }
        update(b, e, diff);
    }

    void fix(int pos) {
        /*if (pos < 0 || pos >= 2*n)
            return;*/
        if (pos < n) {
            maxVal[pos] = max(maxVal[pos*2], maxVal[pos*2+1]);
            maxVal[pos] += s[pos];
        }
        else {
            maxVal[pos] = s[pos];
        }
    }
};

int bruteforce(vi a, vi b) {
    vector<bool> used(sz(a));
    for (int B : b) {
        int best = -1;
        rep(i,0,sz(a)) {
            if (B >= a[i] && !used[i] && (best == -1 || a[i] >= a[best])) {
                best = i;
            }
        }
        if (best != -1)
            used[best] = 1;
    }
    int ans = -1;
    rep(i,0,sz(a))
        if (!used[i] && a[i] > ans)
            ans = a[i];
    return ans;
}

int getRand(int from, int to) {
    int r = (rand()%(to-from))+from;
    cerr << r << " ";
    return r;
}

void solve() {
    Tree tree(OFFSET);
	ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    //n = getRand(1, 4);
    //m = getRand(1, 4);
    vector<int> a(n), b(m);
    /*rep(i,0,OFFSET-1) {
        tree.update(OFFSET+i, OFFSET+i+1, 0);
    }*/
    rep(i,0,n) {
        cin >> a[i];
        //a[i] = getRand(1, 10);
        tree.update(OFFSET, OFFSET+a[i]+1, 1);
    }
    rep(i,0,m) {
        cin >> b[i];
        //b[i] = getRand(1, 10);
        tree.update(OFFSET, OFFSET+b[i]+1, -1);
    }
    int q;
    cin >> q;
    //q = getRand(1, 3);
    while(q--) {
        int type, i, x;
        cin >> type >> i >> x;
        //type=getRand(1, 3);
        //i = getRand(1, type == 1 ? (n+1) : (m+1));
        //x = getRand(1, 10);
        --i;
        if (type == 1) {
            //tree.doUpdate(OFFSET+a[i]+1, OFFSET+x+1, 1);
            tree.update(OFFSET, OFFSET+a[i]+1, -1);
            a[i] = x;
            tree.update(OFFSET, OFFSET+a[i]+1, 1);
        }
        else {
            //tree.doUpdate(OFFSET+b[i]+1, OFFSET+x+1, -1);
            tree.update(OFFSET, OFFSET+b[i]+1, 1);
            b[i] = x;
            tree.update(OFFSET, OFFSET+b[i]+1, -1);
        }
        int myAns = -1;
        if (tree.maxVal[1]> 0) {
            int cur = 1;
            int add = tree.s[1];
            while (cur < OFFSET) {
                if (add+tree.maxVal[2*cur+1]> 0) {
                    cur = 2*cur+1;
                }
                else {
                    cur = 2*cur;
                }
                add += tree.s[cur];
            }
            myAns = cur - OFFSET;
        }
        /*auto ans = tree.maxVal[1];
        int myAns = (ans.first > 0) ? ans.second : -1;*/
        printf("%d\n", myAns);
        /*if (tree.maxVal[1]> 0) {
            assert(myAns > 0 && myAns <= 1000000);
        }
        assert(myAns == bruteforce(a, b));*/
    }
}

int main() {
    //while (true)
        solve();
}