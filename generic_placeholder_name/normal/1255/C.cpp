#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

struct st {
    int x, y, z;
};

int32_t main() {
    int n; cin>>n; vector<int> occ[n+1]; st sets[n+1];
    for(int i=1; i<=n-2; i++) {
        cin>>sets[i].x>>sets[i].y>>sets[i].z;
        occ[sets[i].x].pb(i); occ[sets[i].y].pb(i); occ[sets[i].z].pb(i);
    }
    bool chk=0; int last, pen;
    int s, cnt=0; for(int i=1; i<=n; i++) {if(occ[i].size()==1&&chk==0) {s=i; chk=1;}; if(occ[i].size()==1&&chk==1) last=i;}
    int k=occ[s][0]; int a=sets[k].x, b=sets[k].y, c=sets[k].z;
    for(int i=1; i<=n; i++) {if(occ[i].size()==2&&i!=a&&i!=b&&i!=c) pen=i;}
    while(cnt<n-2) {
        cout<<s<<" "; int k=occ[s][0]; int a=sets[k].x, b=sets[k].y, c=sets[k].z;
        if(s==a) swap(a, c); if(s==b) swap(b, c);
        if(occ[a].size()!=2||a==pen) swap(a, b);
        for(int i=0; i<occ[a].size(); i++) if(occ[a][i]==k) occ[a].erase(occ[a].begin()+i);
        for(int i=0; i<occ[b].size(); i++) if(occ[b][i]==k) occ[b].erase(occ[b].begin()+i);
        s=a;
        cnt++;
    }
    cout<<pen<<" "<<last<<endl;
}