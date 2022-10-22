#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1000*100+1;
long long n,k;
long long a[MAXN];
long long b[MAXN];
long long cnt[MAXN];
vector<int>timet[MAXN];

bool cheq(long long c) {
    for(int i=0; i<k;i++) timet[i].clear();
    for(int i=0; i<n;i++) {
        if(a[i]/b[i]<k) timet[(int)(a[i]/b[i])].push_back(i);
        cnt[i] = 0;
    }
    long long t=0;
    for(int i=0; i<k;i++) {
        while(t<k&&timet[t].size()==0) t++;
        if(t>=k) break;
        int pom = timet[t].back();
        cnt[pom]++;
        if(t<i) return 0;
        if((a[pom]+(long long)c*cnt[pom])/b[pom]<(long long)k) {
            timet[(a[pom]+(long long)c*cnt[pom])/b[pom]].push_back(pom);
        }
        timet[t].pop_back();
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0; i<n;i++) cin>>a[i];
    for(int i=0; i<n;i++) cin>>b[i];
    long long pocz = 0,kon=(long long)1000*1000*1000*1000*1000,sr;
    while(pocz<=kon) {
        sr = (pocz+kon)/2;
        if(cheq(sr)) kon=sr-1;
        else pocz=sr+1;
    }
    if(kon==(long long)1000*1000*1000*1000*1000) cout<<"-1";
    else cout<<kon+1;
    return 0;
}