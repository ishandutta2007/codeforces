#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
using ll = long long;
using vi = vector<int>;
array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        string s;
        cin>>s;
        auto man = manacher(s);
        int x=0;
        bool pal=true;
        int n = sz(s);
        rep(i,0,n) if(s[i]!=s[n-i-1]) pal=false;
        if(pal) cout<<s<<"\n";
        else {
            int k=0;
            while(s[k]==s[n-1-k]) ++k;
            int bestl = 0, bestr=0;
            rep(len,1,n-k-k+1) {
                if(man[len%2][k+len/2]>=len/2) bestl = len;
                if(man[len%2][n-k-(len+1)/2]>=len/2) bestr = len;
            }
            string ans;
            if(bestl>bestr) {
                ans = s.substr(0,k+bestl)+s.substr(n-k);
            }
            else ans=s.substr(0,k)+s.substr(n-k-bestr);
            cout<<ans<<"\n";
        }
    }
}