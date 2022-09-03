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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
#define MXN 10000
const int mod=998244353;
map<int,vector<int> > v;
vector<int> p[200005];
vector<int> qu[200005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[200005];
    v.clear();
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        p[i].clear();
        qu[i].clear();
    }
    for(int i = 1;i<=m;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        p[l].pb(l);
        p[r+1].pb(l);
        
    }
    multiset<int> s;
    int cnt=0;
    for(int i = 1;i<=n;i++){
        for(auto it:p[i]){
            if(it==i)s.insert(i);
            else{
                s.erase(s.find(it));
            }
        }
        if(s.size()){
            auto it=lower_bound(v[a[i]].begin(),v[a[i]].end(),*s.begin());
            if(it!=v[a[i]].end()){
                qu[*it].pb(*it);
                qu[i].pb(i);
                qu[i].pb(*it);
                auto it2=next(it);
                if(it2!=v[a[i]].end()){
                    qu[*it2].pb(*it2);
                    qu[v[a[i]].back()].pb(v[a[i]].back());
                    cnt+=2;    
                }
                //printf("?%d %d\n",*it,i);
                cnt++;
            }
            v[a[i]].pb(i);
        }
    }
    s.clear();
    int ans=1e9;
    if(cnt==0)ans=0;
    else{
    for(int i = 1;i<=n;i++){
        for(auto it:qu[i]){
            if(it==i){
                s.insert(i);
            }
            else{
                s.erase(s.find(it));
            }
        }
        if(s.size()==cnt){
            ans=min(ans,i-*s.begin()+1);
        }
    }
    }
    printf("%d\n",ans);
}
int main(){
   // srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}