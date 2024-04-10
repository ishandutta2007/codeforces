#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {
    int x = 0;
    int c = getchar(), n = 0;
    for(; !isdigit(c); c = getchar())
        n = (c == '-');
    for(; isdigit(c); c = getchar())
        x = x * 10 + c - '0';
    if(n)
        x = -x;
    return x;
}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define timer 1.0*clock()/CLOCKS_PER_SEC
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define ii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
template <int MOD_> struct modnum {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");

private:

    int v;

    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : (int)(m - (long long)minv(m, a) * (long long)m / a);
    }

public:

    modnum() : v(0) {}
    modnum(long long v_) : v(int(v_ % MOD)) {
        if(v < 0)
            v += MOD;
    }
    explicit operator int() const {
        return v;
    }
    friend std::ostream &operator << (std::ostream &out, const modnum &n) {
        return out << int(n);
    }
    friend std::istream &operator >> (std::istream &in, modnum &n) {
        long long v_;
        in >> v_;
        n = modnum(v_);
        return in;
    }

    friend bool operator == (const modnum &a, const modnum &b) {
        return a.v == b.v;
    }
    friend bool operator != (const modnum &a, const modnum &b) {
        return a.v != b.v;
    }

    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    friend modnum inv(const modnum &m) {
        return m.inv();
    }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD - v : 0;
        return res;
    }
    friend modnum neg(const modnum &m) {
        return m.neg();
    }

    modnum operator- () const {
        return neg();
    }
    modnum operator+ () const {
        return modnum(*this);
    }

    modnum &operator ++ () {
        v ++;
        if(v == MOD)
            v = 0;
        return *this;
    }
    modnum &operator -- () {
        if(v == 0)
            v = MOD;
        v --;
        return *this;
    }
    modnum &operator += (const modnum &o) {
        v -= MOD - o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum &operator -= (const modnum &o) {
        v -= o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum &operator *= (const modnum &o) {
        v = (int)((long long)v * (long long)o.v % MOD);
        return *this;
    }
    modnum &operator /= (const modnum &o) {
        return *this *= o.inv();
    }

    friend modnum operator ++ (modnum &a, int) {
        modnum r = a;
        ++a;
        return r;
    }
    friend modnum operator -- (modnum &a, int) {
        modnum r = a;
        --a;
        return r;
    }
    friend modnum operator + (const modnum &a, const modnum &b) {
        return modnum(a) += b;
    }
    friend modnum operator - (const modnum &a, const modnum &b) {
        return modnum(a) -= b;
    }
    friend modnum operator * (const modnum &a, const modnum &b) {
        return modnum(a) *= b;
    }
    friend modnum operator / (const modnum &a, const modnum &b) {
        return modnum(a) /= b;
    }
};

const int N = 200005;
const int T = 500;
int n, m;
int sqrPf[T + 1][N], t[N], res[N];
ii a[N];
vector<int> vec[N];
modnum<1000000007> cnt;
void them(int l, int r, int o)
{
    if(l > m)
        return;
    t[l] += o;
    if(r < m)
        t[r + 1] -= o;
}
void them(int kc, int s, int l, int o)
{
    if(s > m)
        return;
    sqrPf[kc][s] += o;
    if(s + l <= m)
        sqrPf[kc][s + l] -= o;
}
int main()
{

    //freopen("C.inp","r",stdin);
//    n=in,m=in;
ios_base::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
    forinc(i, 1, n) cin>>a[i].fi>>a[i].se;// a[i].fi=in,a[i].se=in;
    forinc(i, 1, m)
    {
        int op, k;
//        op=in,k=in;
cin>>op>>k;
        res[i] = res[i - 1];
        (op == 1 ? res[i]++ : res[i]--);
        vec[k].pb(i);
    }
    forinc(k, 1, n) if(vec[k].size() & 1)
        vec[k].pb(m + 1);
    forinc(i, 1, n) if(vec[i].size())
    {
        for(int j = 0; j < vec[i].size(); j += 2)
        {
            int u = vec[i][j], v = vec[i][j + 1];
            int kc = a[i].fi + a[i].se;
            if(kc >= T)
            {
                for(int s = u; s <= m; s += kc)
                    them(s, s + a[i].fi - 1, 1);
                int last = u + kc * ((v - u) / kc);
                if(last + a[i].fi - 1 >= v)
                    them(v, last + a[i].fi - 1, -1);
                last += kc;
                for(; last <= m; last += kc)
                    them(last, last + a[i].fi - 1, -1);
            }
            else
            {
                them(kc, u, a[i].fi, 1);
                int last = u + kc * ((v - u) / kc);
                if(last + a[i].fi - 1 >= v)
                    them(v, last + a[i].fi - 1, -1);
                else
                {
                    if(vec[0].size())
                        cnt++;
                }
                last += kc;
                them(kc, last, a[i].fi, -1);
            }
        }
    }
    //cerr<<cnt<<endl;
    forinc(i, 1, m) t[i] += t[i - 1];
    forinc(i, 1, T) forinc(j, i, m) sqrPf[i][j] += sqrPf[i][j - i];
    forinc(i, 1, T) forinc(j, 1, m) sqrPf[i][j] += sqrPf[i][j - 1];
    forinc(i, 1, T) forinc(j, 1, m) t[j] += sqrPf[i][j];
    forinc(i, 1, m) cout << res[i] - t[i] << "\n";
}