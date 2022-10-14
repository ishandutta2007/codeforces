/**
 *    author:  gary
 *    created: 03.06.2022 16:40:52
**/
#include<bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <numeric>
#include <string>
#include <vector>

namespace atcoder {

namespace internal {

std::vector<int> sa_naive(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n);
    std::iota(sa.begin(), sa.end(), 0);
    std::sort(sa.begin(), sa.end(), [&](int l, int r) {
        if (l == r) return false;
        while (l < n && r < n) {
            if (s[l] != s[r]) return s[l] < s[r];
            l++;
            r++;
        }
        return l == n;
    });
    return sa;
}

std::vector<int> sa_doubling(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n), rnk = s, tmp(n);
    std::iota(sa.begin(), sa.end(), 0);
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int x, int y) {
            if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
            int rx = x + k < n ? rnk[x + k] : -1;
            int ry = y + k < n ? rnk[y + k] : -1;
            return rx < ry;
        };
        std::sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        std::swap(tmp, rnk);
    }
    return sa;
}

template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
std::vector<int> sa_is(const std::vector<int>& s, int upper) {
    int n = int(s.size());
    if (n == 0) return {};
    if (n == 1) return {0};
    if (n == 2) {
        if (s[0] < s[1]) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }
    if (n < THRESHOLD_NAIVE) {
        return sa_naive(s);
    }
    if (n < THRESHOLD_DOUBLING) {
        return sa_doubling(s);
    }

    std::vector<int> sa(n);
    std::vector<bool> ls(n);
    for (int i = n - 2; i >= 0; i--) {
        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
    }
    std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
    for (int i = 0; i < n; i++) {
        if (!ls[i]) {
            sum_s[s[i]]++;
        } else {
            sum_l[s[i] + 1]++;
        }
    }
    for (int i = 0; i <= upper; i++) {
        sum_s[i] += sum_l[i];
        if (i < upper) sum_l[i + 1] += sum_s[i];
    }

    auto induce = [&](const std::vector<int>& lms) {
        std::fill(sa.begin(), sa.end(), -1);
        std::vector<int> buf(upper + 1);
        std::copy(sum_s.begin(), sum_s.end(), buf.begin());
        for (auto d : lms) {
            if (d == n) continue;
            sa[buf[s[d]]++] = d;
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        sa[buf[s[n - 1]]++] = n - 1;
        for (int i = 0; i < n; i++) {
            int v = sa[i];
            if (v >= 1 && !ls[v - 1]) {
                sa[buf[s[v - 1]]++] = v - 1;
            }
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        for (int i = n - 1; i >= 0; i--) {
            int v = sa[i];
            if (v >= 1 && ls[v - 1]) {
                sa[--buf[s[v - 1] + 1]] = v - 1;
            }
        }
    };

    std::vector<int> lms_map(n + 1, -1);
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms_map[i] = m++;
        }
    }
    std::vector<int> lms;
    lms.reserve(m);
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms.push_back(i);
        }
    }

    induce(lms);

    if (m) {
        std::vector<int> sorted_lms;
        sorted_lms.reserve(m);
        for (int v : sa) {
            if (lms_map[v] != -1) sorted_lms.push_back(v);
        }
        std::vector<int> rec_s(m);
        int rec_upper = 0;
        rec_s[lms_map[sorted_lms[0]]] = 0;
        for (int i = 1; i < m; i++) {
            int l = sorted_lms[i - 1], r = sorted_lms[i];
            int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
            int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
            bool same = true;
            if (end_l - l != end_r - r) {
                same = false;
            } else {
                while (l < end_l) {
                    if (s[l] != s[r]) {
                        break;
                    }
                    l++;
                    r++;
                }
                if (l == n || s[l] != s[r]) same = false;
            }
            if (!same) rec_upper++;
            rec_s[lms_map[sorted_lms[i]]] = rec_upper;
        }

        auto rec_sa =
            sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

        for (int i = 0; i < m; i++) {
            sorted_lms[i] = lms[rec_sa[i]];
        }
        induce(sorted_lms);
    }
    return sa;
}

}  // namespace internal

std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
    assert(0 <= upper);
    for (int d : s) {
        assert(0 <= d && d <= upper);
    }
    auto sa = internal::sa_is(s, upper);
    return sa;
}

template <class T> std::vector<int> suffix_array(const std::vector<T>& s) {
    int n = int(s.size());
    std::vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
    std::vector<int> s2(n);
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (i && s[idx[i - 1]] != s[idx[i]]) now++;
        s2[idx[i]] = now;
    }
    return internal::sa_is(s2, now);
}

std::vector<int> suffix_array(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return internal::sa_is(s2, 255);
}

template <class T>
std::vector<int> lcp_array(const std::vector<T>& s,
                           const std::vector<int>& sa) {
    int n = int(s.size());
    assert(n >= 1);
    std::vector<int> rnk(n);
    for (int i = 0; i < n; i++) {
        rnk[sa[i]] = i;
    }
    std::vector<int> lcp(n - 1);
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (h > 0) h--;
        if (rnk[i] == 0) continue;
        int j = sa[rnk[i] - 1];
        for (; j + h < n && i + h < n; h++) {
            if (s[j + h] != s[i + h]) break;
        }
        lcp[rnk[i] - 1] = h;
    }
    return lcp;
}

std::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return lcp_array(s2, sa);
}

template <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {
    int n = int(s.size());
    if (n == 0) return {};
    std::vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        int& k = z[i];
        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}

std::vector<int> z_algorithm(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return z_algorithm(s2);
}

}  // namespace atcoder

#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=5e6+10;
const int A=337;
const int MOD=998244353;
struct stringhash {
    // 1 based
    int quick(int k1, int k2) {
        int k3 = 1;

        for (; k2; k2 >>= 1, k1 = 1LL * k1 * k1 % MOD)
            if (k2 & 1)
                k3 = 1LL * k3 * k1 % MOD;

        return k3;
    }
    int inv(int A) {
        return quick(A, MOD - 2);
    }
    int pw[MAXN], ipw[MAXN];
    void add(int &A, int B) {
        A += B;

        if (A >= MOD)
            A -= MOD;
    }
    void sub(int &A, int B) {
        A += MOD - B;

        if (A >= MOD)
            A -= MOD;
    }
    int val[MAXN];
    string S;
    stringhash(){
        memset(val, 0, sizeof(val));
        pw[0] = 1;
        rb(i, 1, MAXN - 1) pw[i] = 1ll * A * pw[i - 1] % MOD;
        ipw[MAXN - 1] = inv(pw[MAXN - 1]);
        rl(i, MAXN - 2, 0) ipw[i] = 1ll * A * ipw[i + 1] % MOD;
    }
    void gen(string s) {
        S = s;
        rep(i, s.length()) {
            val[i + 1] = s[i];
        }
        int pww=1;
        rb(i, 1, s.length()) {
            val[i] = (val[i-1] + 1ll*pww*val[i]) % MOD;
            pww=1ll*pww*A%MOD;
        }
    }
    int query(int l, int r) {
        ++l,++r;
        if (r > S.length())
            return MOD;

        // cout<<l<<"__"<<r<<endl;
        return (1ll*(val[r] - val[l - 1]+MOD) * ipw[l-1] % MOD + MOD) % MOD;
    }
}S,RS;
vector<int> Lyndon(string s){
    vector<int> ed;
    int n=s.length();
    s.PB(char(0));
    int p=-1,i=0,u=1,c=1,u2=0;
    for(;i<n;i++){
        if(s[i+1]==s[i+1-u]){
            u2++;
            if(u2==u) u2=0,c++;
        }else
        if(s[i+1]>s[i+1-u]){
            u=i+1-p,u2=0,c=1;
        }else
        if(s[i+1]<s[i+1-u]){
            rb(j,1,c){
                p+=u;
                ed.PB(p);
            }
            i=p,u=1,c=1,u2=0;
        }
    }
    return ed;
}
string R(string S){
    string T=S;
    reverse(ALL(T));
    return T;
}
using namespace atcoder;
string solver00(string s){return s;}
string solver01(string s){
    string T=R(s)+s;
    auto z=z_algorithm(T);
    int ans=0;
    rb(i,1,s.length()-1){
        if(z[ans+s.length()]>=i-ans){
            int x=z[i-ans];
            if(x<s.length()-i){
                if(T[x]<T[x+i-ans]){
                    ans=i;
                }
            }
        }
        else{
            int x=z[ans+s.length()];
            if(s[x+ans]<T[x]){
                ans=i;
            }
        }
    }
    // cout<<ans<<endl;
    reverse(s.begin()+ans,s.end());
    return s;
}
string SS;
int querR(int l,int r){
    return RS.query(SS.length()-1-r,SS.length()-1-l);
}
int query10(int x,int len){
    if(len<=x+1) return querR(x+1-len,x);
    return (querR(0,x)+1ll*S.query(x+1,len-1)*S.pw[x+1])%MOD;
}
int query11(int x,int len){
    if(len<=x+1) return querR(x+1-len,x);
    return (querR(0,x)+1ll*querR(SS.length()-(len-(x+1)),SS.length()-1)*S.pw[x+1])%MOD;
}
char get10(int x,int len){
    if(len<=x+1) return SS[x+1-len];
    return SS[len-1];
}
char get11(int x,int len){
    if(len<=x+1) return SS[x+1-len];
    return SS[SS.length()-(len-x-1)];
}
int lcp10(int x,int y){
    int l=0,r=SS.length()+1;
    while (l+1<r&&get10(x,l+1)==get10(y,l+1)){
        l++;
        if(l==20) break;
    }
    if(l<20) return l;
    l=0,r=SS.length()+1;
    while (l<r-1){
        int mid=(l+r)>>1;
        if(query10(x,mid)==query10(y,mid)) l=mid;
        else r=mid;
    }
    return l;
}
int lcp11(int x,int y){
    int l=0,r=SS.length()+1;
    while (l+1<r&&get11(x,l+1)==get11(y,l+1)){
        l++;
        if(l==20) break;
    }
    if(l<20) return l;
    l=0,r=SS.length()+1;
    while (l<r-1){
        int mid=(l+r)>>1;
        if(query11(x,mid)==query11(y,mid)) l=mid;
        else r=mid;
    }
    return l;
}
string solver10(string s){
    SS=s;
    S.gen(s);
    RS.gen(R(s));
    int ans=0;
    rb(i,1,s.length()-1){
        int l=lcp10(ans,i);
        if(l!=s.length()&&get10(i,l+1)<get10(ans,l+1)){
            ans=i;
        }
    }
    reverse(s.begin(),s.begin()+ans+1);
    return s;
}
string solver11(string s){
    SS=s;
    S.gen(s);
    RS.gen(R(s));
    // cout<<query11(1,1)<<" "<<query11(3,1)<<endl;
    // return "ss";
    int ans=0;
    rb(i,1,s.length()-1){
        int l=lcp11(ans,i);
        if(l!=s.length()&&get11(i,l+1)<get11(ans,l+1)){
            ans=i;
        }
    }
    reverse(s.begin(),s.begin()+ans+1);
    if(ans!=s.size()-1)
    reverse(s.begin()+ans+1,s.end());
    return s;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout<<solver10("jhjhjhiiiiiiiiiiiijjjjjjjjjjjjjj")<<endl;
    // return 0;
    string s;
    cin>>s;
    int n=s.length();
    string sr=s;
    reverse(ALL(sr));
    auto v=Lyndon(sr);
    vector<mp> seg;
    int pre=-1;
    for(auto it:v){
        pre++;
        seg.PB(II(n-1-it,n-1-pre));
        pre=it;
    }
    reverse(ALL(seg));
    vector<string> subs;
    string prestr;
    for(auto it:seg){
        string str;
        rb(j,it.first,it.second) str.PB(s[j]);
        if(prestr==str) subs.back()+=str;
        else subs.PB(str);
        prestr=str;
    }
    vector<string> tmp;
    bool last=0;
    rep(i,subs.size()){
        if(last==(subs[i]<=R(subs[i]))&&last==1) tmp.back()+=subs[i];
        else tmp.PB(subs[i]);
        last=(subs[i]<=R(subs[i]));
    }
    subs=tmp;
    int k;
    cin>>k;
    k=min(k,(int)(subs.size()));
    if(k==1){
        cout<<min(s,R(s))<<endl;
        return 0;
    }
    int alr=0;
    string ans3;
    rep(i,k-2){
        reverse(ALL(subs[i]));
        cout<<min(subs[i],R(subs[i]));
    }
    rb(i,k-2,subs.size()-1) ans3+=subs[i];
    string Ao=solver00(ans3);
    check_min(Ao,solver01(ans3));
    check_min(Ao,solver10(ans3));
    check_min(Ao,solver11(ans3));
    cout<<Ao<<endl;
    return 0;
}