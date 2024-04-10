#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
using ll = long long;
struct Tree {
	typedef pair<int,int> T;
	static constexpr T unit = make_pair(0,0);
	T f(T a, T b) {
        int sum = a.first+b.first;
        int mn = min(b.second, b.first+a.second);
        return make_pair(sum,mn);
    } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
    void add(int pos, int delta) {
        int x = query(pos,pos+1).first;
        x+=delta;
        update(pos, make_pair(x,min(0,x)));
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> pos(n);
    rep(i,0,n) {
        int pi;
        cin>>pi;
        --pi;
        pos[pi] = i;
    }
    vector<int> q(n);
    rep(i,0,n) {
        cin>>q[i];
        --q[i];
    }
    Tree tree(n);
    vector<int> ans(n);
    int j = n;
    rep(i,0,n) {
        ans[i]=j;
        tree.add(q[i],1);
        while(j>0 && tree.query(0,n).second>=0) {
            --j;
            tree.add(pos[j],-1);
        }
    }
    ans[0]=n-1;
    rep(i,0,n) cout<<ans[i]+1<<" ";
    cout<<"\n";
    
}