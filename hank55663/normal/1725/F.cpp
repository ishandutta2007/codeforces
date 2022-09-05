#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
void solve(){
    int n;
    scanf("%d",&n);
    pii p[100005];
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    map<int,int> ans;
    for(int i = 1;i<=1e9;i<<=1){
        int sum=0;
        vector<pii> v;
        for(int j=0;j<n;j++){
            if(p[j].y-p[j].x+1>=i)sum++;
            else{
                int l=p[j].x%i,r=p[j].y%i;
                if(l<=r)v.pb(mp(l,1)),v.pb(mp(r+1,-1));//pr[l]++,pr[r+1]--;
                else v.pb(mp(0,1)),v.pb(mp(r+1,-1)),v.pb(mp(l,1));//pr[0]++,pr[r+1]--,pr[l]++;
            }
        }
        sort(v.begin(),v.end());
        int val=0,Max=0;
        for(auto it:v){
            val+=it.y;
            Max=max(Max,val);
        }
        ans[i]=sum+Max;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int w;
        scanf("%d",&w);
        printf("%d\n",ans[w&-w]);
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve();
    }
   // printf("%d\n",s.size());
}

/*
3 5 7 8
*/