
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
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(int T){
    int n;
    scanf("%d",&n);
    vector<int> v[2];
    int a[100005],b[100005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 0;i<n;i++){
        scanf("%d",&b[i]);
        v[a[i]].pb(b[i]);
    }
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    LL ans=0;
    while(v[0].size()&&v[1].size()&&(v[0].size()!=1||v[1].size()!=1)){
        ans+=v[0].back()*2;
        v[0].pop_back();
        ans+=v[1].back()*2;
        v[1].pop_back();
    }
    if(v[0].size()&&v[1].size()){
        if(v[0].back()>v[1].back())ans+=v[0].back();
        else ans+=v[1].back();
    }
    for(auto it:v[0])ans+=it;
    for(auto it:v[1])ans+=it;
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
       // cerr<<T<<endl;
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
*/