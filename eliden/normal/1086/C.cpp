#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    rep(test,0,tests) {
        int k;
        string ss, sa, sb;
        cin >> k >> ss >> sa >> sb;
        int n = ss.size();
        vector<int> s(n), a(n), b(n);
        rep(i,0,n) {
            s[i] = ss[i]-'a';
            a[i] = sa[i]-'a';
            b[i] = sb[i]-'a';
        }
        auto free = [&](vector<int> p, vector<bool> used, int i) {
            while(i<n) {
                if(p[s[i]]==-1) {
                    rep(j,0,k) if(!used[j]) {
                        used[j] = true;
                        p[s[i]] = j;
                        break;
                    }
                }
                ++i;
            }
            return make_pair(true,p);
        };
        auto justa = [&](vector<int> p, vector<bool> used, int i) {
            while(i<n) {
                if(p[s[i]]==-1) {
                    for(int j=k-1;j>=0;--j) {
                        if(!used[j]) {
                            used[j] = true;
                            p[s[i]] = j;
                            break;
                        }
                    }
                }
                if(p[s[i]]<a[i]) return make_pair(false,p);
                if(p[s[i]]>a[i]) return free(p,used,i+1);
                ++i;
            }
            return make_pair(true,p);
        };
        auto justb = [&](vector<int> p, vector<bool> used, int i) {
            while(i<n) {
                if(p[s[i]]==-1) {
                    rep(j,0,k) {
                        if(!used[j]) {
                            used[j] = true;
                            p[s[i]] = j;
                            break;
                        }
                    }
                }
                if(p[s[i]]>b[i]) return make_pair(false,p);
                if(p[s[i]]<b[i]) return free(p,used,i+1);
                ++i;
            }
            return make_pair(true,p);
        };
        auto both = [&](vector<int> p, vector<bool> used, int i) {
            while(i<n) {
                if(p[s[i]]==-1) {
                    rep(j,a[i]+1,b[i]) {
                        if(!used[j]) {
                            used[j] = true;
                            p[s[i]] = j;
                            break;
                        }
                    }
                    if(p[s[i]]==-1) {
                        if(a[i]==b[i]) {
                            if(used[a[i]]) return make_pair(false,p);
                            used[a[i]] = true;
                            p[s[i]] = a[i];
                        }
                        else {
                            if(!used[a[i]]) {
                                p[s[i]] = a[i];
                                used[a[i]] = true;
                                auto res1 = justa(p,used,i+1);
                                if(res1.first) return res1;
                                p[s[i]] = -1;
                                used[a[i]] = false;
                            }
                            if(!used[b[i]]) {
                                p[s[i]] = b[i];
                                used[b[i]] = true;
                                auto res2 = justb(p,used,i+1);
                                if(res2.first) return res2;
                                p[s[i]] = -1;
                                used[b[i]] = false;
                            }
                            if(p[s[i]] == -1) return make_pair(false,p);
                        }
                    }
                }
                if(p[s[i]]>b[i]) return make_pair(false,p);
                if(p[s[i]]<a[i]) return make_pair(false,p);
                if(p[s[i]]<b[i] && p[s[i]]>a[i]) return free(p,used,i+1);
                else if(p[s[i]]<b[i]) return justa(p,used,i+1);
                else if(p[s[i]]>a[i]) return justb(p,used,i+1);
                ++i;
            }
            return make_pair(true,p);
        };
        vector<int> p0(k,-1);
        vector<bool> used0(k,false);
        auto res = both(p0,used0,0);
        if(res.first) {
            cout<<"YES\n";
            auto p = res.second;
            vector<bool> used(k);
            rep(i,0,k) if(p[i]!=-1) used[p[i]] = true;
            rep(i,0,k) if(p[i]==-1) {
                rep(j,0,k) if(!used[j]) {
                    used[j] = true;
                    p[i] = j;
                    break;
                }
            }
            rep(i,0,k) {
                char c = 'a'+p[i];
                cout << c;
            }
            cout<<"\n";
        }
        else cout << "NO\n";
    }
}