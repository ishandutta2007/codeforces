#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;

vector<int> v[2];
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    char c[200005];
    scanf("%s",c);
    for(int i= 0;i+1<n;i++){
        if(c[i]==c[i+1]){
            v[c[i]-'0'].pb(i+1);
        }
    }
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        r--;
        int cnt0=0,cnt1=0;
        cnt0=upper_bound(v[0].begin(),v[0].end(),r)-lower_bound(v[0].begin(),v[0].end(),l);
        cnt1=upper_bound(v[1].begin(),v[1].end(),r)-lower_bound(v[1].begin(),v[1].end(),l);
        int ans=0;
        ans+=min(cnt0,cnt1);
        cnt0-=ans;
        cnt1-=ans;
        ans+=cnt0;
        ans+=cnt1;
        ans++;
        printf("%d\n",ans);
    }
}
int main(){
  //  srand(time(NULL));
    int t=1;0000;
   // scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
*/