#include <bits/stdc++.h>
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define Unique(v) sort(all(v));v.erase(unique(all(v)),v.end());
#define sz(v) (int)v.size()
//#define int long long
using namespace std;
typedef vector<int> vi;
#define y1 abacaba
#define left sefude
#define db(x) cerr << #x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl; 
#define prl cerr<<"called: "<< __LINE__<<endl;
typedef long long ll;
typedef pair<int,int> pii;
inline ll mod(ll n, ll m ){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
ll exp(ll a,ll b,ll m){
    if(b==0LL) return 1LL;
    if(b==1LL) return mod(a,m);
    ll k = mod(exp(a,b/2,m),m);
    if(b&1LL){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}

struct pt {
    ld x, y;
    pt(ld x, ld y) : x(x), y(y) {}
};

const ld EPS = 1e-12;

struct seg {
    pt p, q;
    int id;
    seg(pt& x, pt& y, int& id) : p(x), q(y), id(id) {}
 
    ld get_y (ld x) const {
        if (abs (p.x - q.x) < EPS)  return p.y;
        return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
    }
};
 
 
inline bool intersect1d (ld l1, ld r1, ld l2, ld r2) {
    if (l1 > r1)  swap (l1, r1);
    if (l2 > r2)  swap (l2, r2);
    return max (l1, l2) <= min (r1, r2) + EPS;
}
 
inline int vec (const pt & a, const pt & b, const pt & c) {
    ld s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return abs(s)<EPS ? 0 : s>0 ? +1 : -1;
}
 
bool intersect (const seg & a, const seg & b) {
    return intersect1d (a.p.x, a.q.x, b.p.x, b.q.x)
           && intersect1d (a.p.y, a.q.y, b.p.y, b.q.y)
           && vec (a.p, a.q, b.p) * vec (a.p, a.q, b.q) <= 0
           && vec (b.p, b.q, a.p) * vec (b.p, b.q, a.q) <= 0;
}
 
 
bool operator< (const seg & a, const seg & b) {
    ld x = max (min (a.p.x, a.q.x), min (b.p.x, b.q.x));
    return a.get_y(x) < b.get_y(x) - EPS;
}
 
 
struct has_inter {
 
    struct event {
        ld x;
        int tp, id;
 
        event() {}
 
        event(ld x, int tp, int id)
            : x(x), tp(tp), id(id) {}
 
        bool operator<(const event &e) const {
            if (abs(x - e.x) > EPS) return x < e.x;
            return tp > e.tp;
        }
    };
 
    set<seg> s;
    vector<set<seg>::iterator> where;
 
    inline set<seg>::iterator prev(set<seg>::iterator it) {
        return it == s.begin() ? s.end() : --it;
    }
 
    inline set<seg>::iterator next(set<seg>::iterator it) {
        return ++it;
    }
 
    pair<int, int> solve(const vector<seg> &a) {
        int n = (int) a.size();
        vector<event> e;
        for (int i = 0; i < n; ++i) {
            e.push_back(event(min(a[i].p.x, a[i].q.x), +1, i));
            e.push_back(event(max(a[i].p.x, a[i].q.x), -1, i));
        }
        sort(e.begin(), e.end());
 
        s.clear();
        where.resize(a.size());
        for (size_t i = 0; i < e.size(); ++i) {
            int id = e[i].id;
            if (e[i].tp == +1) {
                auto nxt = s.lower_bound(a[id]), prv = prev(nxt);
                if (nxt != s.end() && intersect(*nxt, a[id]))
                    return make_pair(nxt->id, id);
                if (prv != s.end() && intersect(*prv, a[id]))
                    return make_pair(prv->id, id);
                where[id] = s.insert(nxt, a[id]);
            } else {
                if (where[id] == s.end()) continue;
                auto nxt = next(where[id]), prv = prev(where[id]);
                if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
                    return make_pair(prv->id, nxt->id);
                s.erase(where[id]);
            }
        }
 
        return make_pair(-10, -10);
    }
};

int n;
const int N = 25100;
int x[N],y[N],dx[N],dy[N],s[N];

bool ok(ld t){

  vector<seg> vec;
  for(int i=0;i<n;i++){
    ld sq = (ld)sqrt((ld)dx[i]*dx[i] + (ld)dy[i]*dy[i]);
    pt a = pt((ld)x[i],(ld)y[i]);
    pt b = pt((ld)x[i] + (ld)t*s[i]*dx[i]/sq,(ld)y[i] + (ld)t*s[i]*dy[i]/sq);
    vec.pb(seg(a,b,i));

  }
  has_inter iter;
  if(iter.solve(vec).ff>-1)return 1;
  return 0;
}

int32_t main(){
  fastio;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> x[i] >> y[i] >> dx[i] >> dy[i] >> s[i];
  }

  ld l = 0 ,r = 1e12, ans = -100;
  if(!ok(r)){
    cout<<"No show :("<<endl;
    return 0;
  }
  rep(iter,0,75){

    ld mid = (l+r)/2.0;
    if(ok(mid)){
      ans = mid;
      r = mid;
    }else l = mid ;
  }
  cout << setprecision(10) << fixed;
  cout << ans << endl;
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}