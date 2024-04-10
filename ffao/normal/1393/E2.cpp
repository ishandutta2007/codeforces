    #if 1
    #ifdef LOCAL
    #define _GLIBCXX_DEBUG 1
    #define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
    #else
    #define dbg(...) 0
    #endif
     
    #include <bits/stdc++.h>
    using namespace std;
     
    #define rep(i, a, b) for(int i = a; i < (b); ++i)
    #define sz(x) (int)(x).size()
    #define all(x) begin(x), end(x)
    #define FOR(i,a,b) for (int i = (a); i < (b); ++i)
    #define F0R(i,a) FOR(i,0,a)
     
    typedef string str;
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
     
    #define ts to_string
    str ts(char c) { return str(1,c); }
    str ts(bool b) { return b ? "true" : "false"; }
    str ts(const char* s) { return (str)s; }
    str ts(str s) { return s; }
    template<class A> str ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
    str ts(vector<bool> v) { str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);	res += "}"; return res; }
    template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; F0R(i,SZ) res += char('0'+b[i]); return res; }
    template<class A, class B> str ts(pair<A,B> p);
    template<class T> str ts(T v) { bool fst = 1; str res = "{"; for (const auto& x: v) {if (!fst) res += ", ";	fst = 0; res += ts(x);}	res += "}"; return res;}
    template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.f)+", "+ts(p.s)+")"; }
     
    template<class A> void pr(A x) { cout << ts(x); }
    template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
    void ps() { pr("\n"); }
    template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
     
    void DBG() { cerr << "]" << endl; }
    template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }
     
    template<class T>
    struct RMQ {
    	vector<vector<T>> jmp;
    	RMQ(const vector<T>& V) : jmp(1, V) {
    		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
    			jmp.emplace_back(sz(V) - pw * 2 + 1);
    			rep(j,0,sz(jmp[k]))
    				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
    		}
    	}
    	T query(int a, int b) {
            if (a == b) return 1000000000;
    		int dep = 31 - __builtin_clz(b - a);
    		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    	}
    };
     
    template<class T>
    const std::vector<int>& sa_is(std::vector<T> s, int k) {
      int N = s.size();
      static std::vector<int> sa;
      static std::vector<int> cnt;
      sa.resize(N + 1);
     
      if(N == 0) return sa;
     
      for(auto& c: s) c++;
      s.push_back(0);
      k++;
     
      std::vector<bool> iss(N + 1);
      std::vector<int> lms;
      std::vector<int> is_lms(N + 1, -1);
      std::vector<int> bin(k + 1);
     
      iss[N] = true;
      bin[1]++;
      for(int i = N; i --> 0; ) {
        if(s[i] == s[i + 1])
          iss[i] = iss[i + 1];
        else
          iss[i] = s[i] < s[i + 1];
        if(!iss[i] && iss[i + 1]) {
          is_lms[i + 1] = lms.size();
          lms.push_back(i + 1);
        }
        bin[s[i] + 1]++;
      }
     
      for(int i = 1;i <= k;i++)
        bin[i] += bin[i - 1];
     
      auto induce = [&](const std::vector<int>& lms) {
        sa.assign(N + 1, -1);
        cnt.assign(k, 0);
     
        for(int i = 0;i < lms.size();i++) {
          int x = lms[i];
          sa[bin[s[x] + 1] - 1 - cnt[s[x]]] = x;
          cnt[s[x]]++;
        }
     
        cnt.assign(k, 0);
        for(int i = 0;i <= N;i++) {
          int x = sa[i] - 1;
          if(x >= 0 && !iss[x]) {
            sa[bin[s[x]] + cnt[s[x]]] = x;
            cnt[s[x]]++;
          }
        }
     
        cnt.assign(k, 0);
        for(int i = N + 1;i --> 0;) {
          int x = sa[i] - 1;
          if(x >= 0 && iss[x]) {
            sa[bin[s[x] + 1] - 1 - cnt[s[x]]] = x;
            cnt[s[x]]++;
          }
        }
      };
     
      induce(lms);
     
     
      if(lms.size() >= 2) {
        int M = lms.size();
        int li = 0;
        std::vector<int> rec_lms(M);
        for(auto x: sa) {
          if(is_lms[x] != -1) rec_lms[li++] = x;
        }
        int rec_n = 1;
        std::vector<int> rec_s(M);
        rec_s[M - 1 - is_lms[rec_lms[1]]] = 1;
        for(int i = 2;i < M;i++) {
          int xl = rec_lms[i];
          int yl = rec_lms[i - 1];
          int xr = lms[is_lms[xl] - 1];
          int yr = lms[is_lms[yl] - 1];
          if(xr - xl != yr - yl)
            rec_n++;
          else {
            while(xl <= xr) {
              if(s[xl] != s[yl]) {
                rec_n++;
                break;
              }
              xl++;
              yl++;
            }
          }
          rec_s[M - 1 - is_lms[rec_lms[i]]] = rec_n;
        }
     
     
        sa_is(std::move(rec_s), rec_n + 1);
        li = M;
        for(int i = 1;i < M + 1;i++) {
          rec_lms[--li] = lms[M - 1 - sa[i]];
        }
        induce(rec_lms);
      }
      
      return sa;
    }
     
    template<class T>
    vector<int> LCP(const vector<T> &s, const vector<int> &sa) {
        int n = s.size(), k = 0;
        vector<int> lcp(n), rank(n);
        for (int i = 0; i < n; i++)
            rank[sa[i]] = i;
        for (int i = 0; i < n; i++, k ? k-- : 0) {
            if (rank[i] == n - 1) {
                k = 0;
                continue;
            }
            int j = sa[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k])
                k++;
            lcp[rank[i]] = k;
        }
        lcp[n - 1] = 0;
        return lcp;
    }
     
    #endif
     
    const int mod = 1000000007;
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int n;
        cin >> n;
     
        vector< int > concat;
        vector< int > start(n);
        vector< int > len(n);
     
        bool dd = false;
     
        int cur = 0;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
     
            start[i] = cur;
            len[i] = sz(s);
     
            for (int i = 0; i < sz(s); i++) {
                concat.push_back((int)s[i] + 100010);
                cur++;
            }
            concat.push_back(i);
            cur++;
        }
     
        vector<int> SA = sa_is(concat, 100020 + (int)'z');
        SA.erase(SA.begin());
        RMQ lcp = RMQ(LCP(concat, SA));
     
        vector<int> rev(sz(concat),0);
        for (int i = 0; i < sz(concat); i++) rev[SA[i]] = i;
     
        const int INF = 1000000000;
        auto cmp = [&](auto cmp, pair<int,int> a, pair<int,int> b) {
            if (a.first == b.first && min(a.second, b.second) >=10000000) return 0;
            if (a.second > b.second) return -cmp(cmp, b, a);
     
            int lc = lcp.query(min(rev[a.first],rev[b.first]), max(rev[a.first],rev[b.first]));
            if (lc >= a.second) {
                return cmp(cmp, {a.first + a.second + 1, INF}, {b.first + a.second, b.second - a.second});
            }
     
            return concat[a.first + lc] < concat[b.first + lc] ? -1 : 1;
        };
     
        vector<vector<int>> dp;
        dp.push_back(vector<int>(len[0]+1, 1));
     
        for (int i = 1; i < n; i++) {
            dp.push_back(vector<int>(len[i]+1));
            
            vector< pair<int,int> > strings;
            for (int j = 0; j < len[i-1]; j++) strings.push_back({i-1, j});
            for (int j = 0; j < len[i]; j++) strings.push_back({i, j});
            strings.push_back({i-1, INF}); strings.push_back({i, INF});
     
            stable_sort(strings.begin(), strings.end(), [&](pair<int, int> a, pair<int, int> b) { return cmp(cmp, {start[a.first], a.second}, {start[b.first], b.second}) < 0; });
            int tot = 0;
            for (auto [ind, l] : strings) {
                if (ind == i-1) tot = (tot + dp[ind][l == INF ? len[ind] : l]) % mod;
                else dp[ind][l == INF ? len[ind] : l] = tot;
            }
        }
     
        int ans = 0;
        for (int i = 0; i <= len[n-1]; i++) ans = (ans + dp[n-1][i]) % mod;
        cout << ans << endl;
     
        return 0;
    }