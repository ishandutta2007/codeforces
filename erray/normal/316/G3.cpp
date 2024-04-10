#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
const int alph = 'z'-'a'+13;
string str;
int n, rulecnt;
int val[500009], nval[500009];
vector<int> vals[500009];
vector<int> suf;
int rval[500009], lcp[500009];
int gang[500009];
int minlcp[500009][20];
int gangpre[500009][11];

struct rule{
    string s;
    int l, r;
} rules[11];

vector<int> boundaries;

pii getokay(int idx, int val){
    int r = idx;
    for(int i = 19; i >= 0; --i)
        if(r+(1<<i) < n && minlcp[r][i] >= val)
            r += (1<<i);
    
    int l = idx;
    for(int i = 19; i >= 0; --i)
        if(l-(1<<i) >= 0 && minlcp[l-(1<<i)][i] >= val)
            l -= (1<<i);
    

    pii ans = {1, 1};
    //cout << l << ' ' << r << '\n';
    for(int i = 1; i <= rulecnt; ++i){
        int curval = gangpre[r][i];
        if(l)
            curval -= gangpre[l-1][i];
        //cout << i << ' ' << curval << '\n';
        if(curval < rules[i].l)
            ans.ff = 0;
        if(curval > rules[i].r)
            ans.ss = 0;
    }
    //cout << ans.ff << ' ' << ans.ss << '\n';
    return ans;
}
void calc(){
    ll ans = 0;
    int gangbef = 0;
    for(int i = 0; i < n; ++i){
        if(gang[i]){
            gangbef = min(gangbef, lcp[i]);
            continue;
        }
        
        int l1 = gangbef+1, r1 = boundaries[0]-suf[i];
        while(l1 < r1){
            int m = (l1+r1+1)/2;
            if(getokay(i, m).ff == 0)
                r1 = m-1;
            else
                l1 = m;
        }

        int l2 = gangbef+1, r2 = boundaries[0]-suf[i];
        while(l2 < r2){
            int m = (l2+r2)/2;
            if(getokay(i, m).ss == 0)
                l2 = m+1;
            else
                r2 = m;
        }
        //cout << i << ' ' << l1 << ' ' << getokay(i, l1).ff << '\n'; 
        if(getokay(i, l1).ff && getokay(i, l2).ss){
            //cout << i << ' ' << l1 << ' ' << getokay(i, l1).ff << '\n'; 

            //cout << i << ' ' << l1 << ' ' << l2 << ' ' << max(0, l1-l2+1) << ' ' << gangbef << '\n';
            ans += max(0, l1-l2+1);
        }

        gangbef = lcp[i];
    }

    cout << ans << '\n';
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    string s;
    cin >> s;
    boundaries.pb(s.size());
    str = s;

    cin >> rulecnt;

    for(int i = 1; i <= rulecnt; ++i){
        cin >> rules[i].s >> rules[i].l >> rules[i].r;
        str.pb('a'-rulecnt-1+i);
        str += rules[i].s;
        boundaries.pb(boundaries.back()+1+rules[i].s.size());
    }
    n = str.size();
    
    vector<int> alpcnt(alph);
    for(int i = 0; i < n; ++i){
        alpcnt[str[i]-'a'+rulecnt] = 1;
    }
    for(int i = 1; i < alph; ++i)
        alpcnt[i] += alpcnt[i-1];
    for(int i = 0; i < n; ++i)
        val[i] = alpcnt[str[i]-'a'+rulecnt];
    
    for(int i = 1; i <= alph; ++i)
        for(int j = 0; j < n; ++j)
            if(val[j] == i)
                suf.pb(j);
    
    
    for(int len = 1; (1<<(len-1)) < n; ++len){
        int k = (1<<(len-1));
    
        for(int i = 0; i <= n; ++i)
            vals[i].clear();
        for(int i = n-1; i+k >= n; --i)
            vals[val[i]].pb(i);
        for(auto u : suf)
            if(u-k >= 0){
                u -= k;
                vals[val[u]].pb(u);
            }
        suf.clear();
        for(int i = 0; i <= n; ++i)
            for(auto u : vals[i])
                suf.pb(u);
    
        pii befval = {-1, -1};
        int befrank = 0;
    
        for(int i : suf){
            if(pii(val[i], ((i+k < n) ? val[i+k] : 0)) == befval)
                nval[i] = befrank;
            else{
                befval = pii(val[i], ((i+k < n) ? val[i+k] : 0));
                nval[i] = ++befrank;
            }
        }
        for(int i = 0; i < n; ++i)
            val[i] = nval[i];
    }
    
    
    for(int i = 0; i < n; ++i)
        rval[suf[i]] = i;
    
    int len = 0;
    for(int i = 0; i < n; ++i){
        if(rval[i] == n-1){
            len = 0;
            continue;
        }
        int j = suf[rval[i]+1];
        while(i+len < n && j+len < n && str[i+len] == str[j+len])
            ++len;
        lcp[rval[i]] = len;
        if(len)
            --len;
    }

    for(int i = n-1; i >= 0; --i){
        minlcp[i][0] = lcp[i];
        for(int j = 1; j < 20; ++j){
            if(i+(1<<(j-1)) < n)
                minlcp[i][j] = min(minlcp[i][j-1], minlcp[i+(1<<(j-1))][j-1]);
            else
                minlcp[i][j] = minlcp[i][j-1];
        }
    }

    for(int i = 0; i < n; ++i)
        gang[i] = upper_bound(all(boundaries), suf[i])-boundaries.begin();
    
    for(int i = 0; i < n; ++i){
        if(i)
            for(int j = 0; j <= rulecnt; ++j)
                gangpre[i][j] = gangpre[i-1][j];
        gangpre[i][gang[i]]++;
    }

    //for(int i = 0; i < n; ++i)
    //    cout << i << ' ' << gang[i] << ' ' << str.substr(suf[i]) << '\n';

    //getokay(14, 2);return 0;

    calc();
    
    
    

    //cout << (ld)clock()/CLOCKS_PER_SEC << '\n';
}