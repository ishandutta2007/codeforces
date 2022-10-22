#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;
long long a[8], b[8];
vector<long long> fac[8];
vector<bool> left[8];

int rec(int ind, int saved, bool all){
    if(ind == n)
        return saved+all;
    int best=saved;
    for(int i=0; i < ind; ++i){
        int k=0;
        bool ok=1;
        vector<int> use;
        for(int j=0; j < fac[ind].size(); ++j){
            while(true){
                if(k >= fac[i].size() || fac[i][k] > fac[ind][j]){
                    ok=0;
                    break;
                }
                if(!left[i][k] || fac[i][k] < fac[ind][j]){
                    ++k;
                    continue;
                }
                use.push_back(k);
                ++k;
                break;
            }
        }
        if(!ok)
            continue;
        for(int j=0; j < use.size(); ++j)
            left[i][use[j]]=0;
        int r=rec(ind+1, saved+(fac[ind].size() == 1 ? 1 : fac[ind].size()), all);
        if(r > best)
            best=r;
        for(int j=0; j < use.size(); ++j)
            left[i][use[j]]=1;
    }
    int r=rec(ind+1, saved, (ind == 0 ? 1 : 0));
    if(r > best)
        best=r;
    return best;
}

int main()
{
    scanf("%d", &n);
    int ans=1;
    for(int i=0; i < n; ++i){
        scanf("%I64d", b+i);}
    sort(b, b+n);
    for(int i=0; i < n; ++i)
        a[i]=b[n-i-1];
    for(int i=0; i < n; ++i){
        for(long long j=2; j*j <= a[i]; ++j){
            while(!(a[i]%j)){
                fac[i].push_back(j);
                left[i].push_back(1);
                a[i] /= j;
            }
        }
        if(a[i] > 1){
            fac[i].push_back(a[i]);
            left[i].push_back(1);
        }
        if(fac[i].size() == 1)
            ++ans;
        else
            ans += fac[i].size()+1;
    }
    ans -= rec(0, 0, 1);
    printf("%d", ans);
    return 0;
}