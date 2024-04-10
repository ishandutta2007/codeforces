#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back

const int MAXN = 100*1000+1;
int n,x;
pi cnt[MAXN];
int a[MAXN];
int ans=3;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>x;
    for(int i=0; i<n;i++) {
        cin>>a[i];
        cnt[a[i]].ST++;
        if(a[i]!=(a[i]&x)) {
            cnt[a[i]&x].ST++;
            cnt[a[i]&x].ND++;
        }
    }
    for(int i=0; i<MAXN;i++) {
        if(cnt[i].ST>1) {
            if(cnt[i].ND==cnt[i].ST) ans=min(ans,2);
            else if(cnt[i].ND+2<=cnt[i].ST) ans=min(ans,0);
            else if(cnt[i].ND+1==cnt[i].ST) ans=min(ans,1);
            //cout<<i<<" "<<cnt[i].ST<<" "<<cnt[i].ND<<"\n";
        }
    }
    if(ans==3) cout<<"-1";
    else cout<<ans;
}