#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;

int n,t,a,b;
long long na,nb;
vector<ii> v;
int type[200005];
int time[200005];
int solve(long long i,long long j,int time){
    long long rem=time-i*a-j*b;
    if (rem<0) return -1;
    if (rem<(na-i)*a) return i+j+rem/a;
    else return na+min(nb,(time-na*a)/b);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%d%d%d%d",&n,&t,&a,&b);
        v.clear();
        int temp;
        na=nb=0;
        for (int x=0;x<n;x++) scanf("%d",&type[x]);
        for (int x=0;x<n;x++) scanf("%d",&time[x]);
        for (int x=0;x<n;x++){
            if (type[x]==0) na++;
            else nb++;
        }
        
        for (int x=0;x<n;x++) v.push_back(ii(time[x],type[x]));
        v.push_back(ii(t+1,-1));
        
        sort(v.begin(),v.end());
        
        int ans=0;
        int ca=0,cb=0;
        ans=max(ans,solve(ca,cb,v[0].first-1));
        
        for (int x=0;x<n;x++){
            if (v[x].second==0) ca++;
            else cb++;
            if (v[x].first!=v[x+1].first) ans=max(ans,solve(ca,cb,v[x+1].first-1));
        }
        printf("%d\n",ans);
    }
}