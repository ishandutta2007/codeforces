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
#define double long double
using namespace std;
vector<int> v[200005];
int in[200005],out[200005],id[200005];
int now=0;
bool cmp(const int &x,const int &y){
    return in[x]<in[y];
}
void dfs(int x,int f){
    in[x]=++now;
    id[now]=x;
    for(auto &it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
        else{
            swap(v[x].back(),it);
            if(it!=f)dfs(it,x);
        }
    }
    if(v[x].size()&&v[x].back()==f)
    v[x].pop_back();
    sort(v[x].begin(),v[x].end(),cmp);
    out[x]=now;
}

void solve(){  
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    for(int i = 1;i<=n;i++){
       // printf("%d %d\n",in[i],out[i]);
      //  for(auto it:v[i])printf("%d ",it);
       // printf("?\n");
    }//
    int q;
    scanf("%d",&q);
    while(q--){
        int k;
        scanf("%d",&k);
        vector<int> vv;
        for(int i = 1;i<=k;i++){
            int x;
            scanf("%d",&x);
            vv.pb(x);
        }
        vector<pii> stk;
        sort(vv.begin(),vv.end(),cmp);
        int cnt=0;
        for(auto it:vv){
          //  printf("%d\n",it);
            if(stk.empty()||(stk.back().x<=in[it]&&stk.back().y>=in[it])){
                stk.pb(mp(in[it],out[it]));
            }
            else{
                cnt++;
                int last;
                while(stk.size()&&!(stk.back().x<=in[it]&&stk.back().y>=in[it])){
                    last=stk.back().x;
                    stk.pop_back();
                }
                if(stk.size()){
                    int xx=id[stk.back().x];
                    auto it2=prev(upper_bound(v[xx].begin(),v[xx].end(),id[last],cmp));
                    //printf("%d %d %d\n",xx,*it2,it);
                    if(in[it]>=in[*it2]&&in[it]<=out[*it2]){
                        cnt=2;
                    }
                }
               // printf("%d\n",stk.size());
                if(stk.size()>1)cnt=3;
                stk.pb(mp(in[it],out[it]));
            }
        }
        if(cnt<=1)printf("YES\n");
        else printf("NO\n");
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    //printf("\"");
    while(t--){
        // cerr<<t<<endl;
        solve();
     //   cerr<<t<<endl;
    }
    
   // cerr<<cnt<<endl;
}
/*
*/