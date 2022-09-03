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
const int mod=1e9+7;

void solve(){
    int n;
    scanf("%d",&n);
    pii p[200005];
    map<int,int> m;
    set<int> s;
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        m[x]=i;
        m[y]=i;
        p[i]=mp(x,y);
        s.insert(x);
        s.insert(y);
    }
    int r=2*n,l=1;
    int Min=1,Max=2*n;
    vector<pii> ans;
    int tot=0;
    while(s.size()){
        int x=*s.begin();
        int idx=m[x];
        int sum=1,cnt=0;
        if(p[idx].y==x){
            swap(p[idx].y,p[idx].x);
            cnt++;
        }
        ans.pb(p[idx]);
        s.erase(p[idx].x);
        s.erase(p[idx].y);
        Max=p[idx].y;
        while(r>=Max||l<=Min){
            if(r>=Max){
                if(s.find(r)!=s.end()){
                    sum++;
                    int idx=m[r];
                    if(p[idx].y==r){
                        swap(p[idx].x,p[idx].y);
                        cnt++;
                    }
                    ans.pb(p[idx]);
                    s.erase(p[idx].x);
                    s.erase(p[idx].y);
                    Min=max(Min,p[idx].y);
                }
                r--;
            }
            else{
                if(s.find(l)!=s.end()){
                    sum++;
                    int idx=m[l];
                    if(p[idx].y==l){
                        swap(p[idx].x,p[idx].y);
                        cnt++;
                    }
                    ans.pb(p[idx]);
                    s.erase(p[idx].x);
                    s.erase(p[idx].y);
                    Max=min(Max,p[idx].y);
                }
                l++;
            }
        }
        tot+=min(sum-cnt,cnt);
    }
    sort(ans.begin(),ans.end());
    for(int i = 0;i<ans.size()-1;i++){
        if(ans[i].y<ans[i+1].y){
            printf("-1\n");
            return;
        }
    }
    printf("%d\n",min(tot,n-tot));
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}