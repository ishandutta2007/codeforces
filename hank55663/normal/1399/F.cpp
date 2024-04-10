#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
bool cmp(const pii &p,const pii &q){
    return p.y-p.x<q.y-q.x;
}
int main(){
    int t;
    scanf("%d",&t);
    pii p[3005];
    while(t--){
        int n;
        scanf("%d",&n);

        map<int,int> m;
        for(int i = 0;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            p[i]=mp(x,y);
            m[x];
            m[y];
        }
        int Index=0;
        for(auto &it:m)it.y=++Index;
        for(int i = 0;i<n;i++){
            p[i].x=m[p[i].x];
            p[i].y=m[p[i].y];
        }
        sort(p,p+n,cmp);
        p[n]=mp(1,Index);
        int val[3005];
        for(int i = 0;i<=n;i++){
            vector<pair<pii,int> > v;
            for(int j=0;j<i;j++){
                if(p[j].x>=p[i].x&&p[j].y<=p[i].y){
                    v.pb(mp(mp(p[j].y,p[j].x),val[j]));
                }
            }
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
            int dp[6005];
            dp[p[i].x-1]=0;
            for(int j=p[i].x;j<=p[i].y;j++){
                dp[j]=dp[j-1];
                while(!v.empty()&&v.back().x.x==j){
                    dp[j]=max(dp[j],dp[v.back().x.y-1]+v.back().y);
                    v.pop_back();
                }
            }
            val[i]=dp[p[i].y]+1;
        }
        printf("%d\n",val[n]-1);
    }
}