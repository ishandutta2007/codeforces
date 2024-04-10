#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int sum[N],cnt[N];
int c[N][2],n,m;
vector<int>x[N];
void add(int x,int v) {
    for(int i=x;i<=m;i+=i&-i) {
        c[i][0]+=v;
        c[i][1]+=v*x;
    }
}
int qry(int x,int f) {
    int sum=0;
    for(int i=x;i;i-=i&-i)
        sum+=c[i][f];
    return sum;
}
signed main() {
    int c;
    long long ans=0;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            scanf("%lld",&c);
            ans+=i*cnt[c]-sum[c];
            cnt[c]++;
            sum[c]+=i;
            x[c].push_back(j);
        }
    for(int i=1;i<=100000;i++) {
        int sum=0,cnt=0;
        for(int j:x[i]) {
            int t1=qry(j,0),t2=qry(j,1);
            ans+=t1*j-t2;
            ans+=(sum-t2)-(cnt-t1)*j;
            add(j,1);
            cnt++;
            sum+=j;
        }
        for(int j:x[i])
            add(j,-1);
    }
    printf("%lld\n",ans);
}