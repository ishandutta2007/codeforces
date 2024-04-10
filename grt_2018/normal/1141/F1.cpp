#include <bits/stdc++.h>

using namespace std;

#define PB push_back

struct Interval {
    long long c;
    int p,k;
    bool operator < (const Interval &x) const {
        if(c==x.c)
            return k<x.k;
        return c<x.c;
    }
};

const int MAXN = 1501;
vector<pair<int,int> >ansv;
int n,ans,res,pos;
int a[MAXN];
long long pref[MAXN];
Interval q[MAXN*MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n;i++) {
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    for(int i=1; i<=n;i++) {
        for(int j=i; j<=n;j++) {
            q[pos++] = {pref[j]-pref[i-1],i,j};
        }
    }
    sort(q,q+pos);
    vector<pair<int,int> >pom;
    for(int i=0; i<pos;i++) {
        res = 1;
        int wsk = q[i].k;
        pom.PB({q[i].p,q[i].k});
        while(i+1<pos&&q[i+1].c==q[i].c) {
            if(q[i+1].p>wsk) {
                res++;
                pom.PB({q[i+1].p,q[i+1].k});
                wsk = q[i+1].k;
            }
            i++;
        }
        if(ans<res) {
            ans = res;
            ansv = pom;
        }
        pom.clear();
    }
    cout<<ans<<"\n";
    for(auto it:ansv) cout<<it.first<<" "<<it.second<<"\n";
    return 0;
}