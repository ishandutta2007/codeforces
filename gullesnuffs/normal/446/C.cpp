#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;

int a[300005];
int asum[300005];
vector<pair<int, int> > recent;
int F[300005];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i < n; ++i){
        scanf("%d", a+i);
        asum[i+1]=(asum[i]+a[i])%MOD;
    }
    F[1]=1;
    F[2]=1;
    for(int i=3; i < 300005; ++i)
        F[i]=(F[i-1]+F[i-2])%MOD;
    for(int i=0; i < m; ++i){
        int type, l, r;
        scanf("%d%d%d", &type, &l, &r);
        --r;--l;
        if(type == 1){
            recent.push_back(make_pair(l, r));
            if(recent.size() > 600){
                for(int j=0; j < n; ++j)
                    a[j]=0;
                for(int j=0; j < recent.size(); ++j){
                    a[recent[j].first]++;
                    a[recent[j].second+1]=(a[recent[j].second+1]+MOD-F[recent[j].second-recent[j].first+2])%MOD;
                    a[recent[j].second+2]=(a[recent[j].second+2]+MOD-F[recent[j].second-recent[j].first+1])%MOD;
                }
                for(int j=1; j < n; ++j){
                    if(j > 1)
                        a[j]=(a[j]+a[j-2])%MOD;
                    a[j]=(a[j]+a[j-1])%MOD;
                }
                int s=0;
                for(int j=0; j < n; ++j){
                    s=(s+a[j])%MOD;
                    asum[j+1]=(asum[j+1]+s)%MOD;
                }
                recent.clear();
            }
        }
        else{
            int ans=asum[r+1]-asum[l];
            ans=(ans+MOD)%MOD;
            for(int j=0; j < recent.size(); ++j){
                int add;
                int start, stop;
                if(l > recent[j].first)
                    start=l;
                else
                    start=recent[j].first;
                if(r > recent[j].second)
                    stop=recent[j].second;
                else
                    stop=r;
                if(stop < start-1)
                    continue;
                start -= recent[j].first;
                stop -= recent[j].first;
                add=F[stop+3]-F[start+2]+MOD;
                add%=MOD;
                ans=(ans+add)%MOD;
            }
            ans=(ans+MOD)%MOD;
            printf("%d\n", ans);
        }
    }
    return 0;
}