#include<bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("O3,unroll-loops")
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
vector<int> v[105];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            int x;
            scanf("%d",&x);
            v[i].pb(x);
        }
    }
    vector<vector<int> > ans;
    while(true){
        int ok=1;
        for(int i =1;i<=n;i++){
            int cnt=0;
            for(auto it:v[i]){
                if(it!=i)cnt++;
            }
            if(cnt>=2){
                ok=0;
                break;
            }
        }
        if(ok)break;
        vector<int> tmp;
        for(int i = 1;i<=n;i++){
            int ok=0;
            int Max=0,val;
            int now=0;
            for(auto &it:v[i]){
                if(it!=i){
                    
                    int d=(it-i+n)%n;
                    if(d>Max){
                        val=now;
                        Max=d;
                    }
                    /*tmp.pb(it);
                    swap(it,v[i].back());
                    v[i].pop_back();*/
                    ok=1;
               //     break;
                }
                now++;
            }
            if(ok){
            tmp.pb(v[i][val]);
           /* printf("%d %d %d\n",i,v[i][now]);
            getchar();*/
            swap(v[i].back(),v[i][val]);
            v[i].pop_back();

            }
            if(!ok){
                tmp.pb(v[i].back());
                v[i].pop_back();
            }
        }
        ans.pb(tmp);
        for(int i = 2;i<=n;i++)v[i].pb(tmp[i-2]);
        v[1].pb(tmp.back());
    }
    int st;
    int c=0;
    while(true){
        int ok=0;
        for(int i = 1;i<=n;i++){
            int cnt=0;
            for(auto it:v[i]){
                if(it!=i)cnt++;
            }
            if(!cnt){
                ok++;
                st=i;
            //    break;
            }
        }
        if(ok==n)c=1;
        if(ok)break;
        vector<int> tmp;
        for(int i = 1;i<=n;i++){
            int ok=0;
            for(auto &it:v[i]){
                if(it!=i){
                    tmp.pb(it);
                    swap(it,v[i].back());
                    v[i].pop_back();
                    ok=1;
                    break;
                }
            }
            if(!ok){
                tmp.pb(v[i].back());
                v[i].pop_back();
            }
        }
        ans.pb(tmp);
        for(int i = 2;i<=n;i++)v[i].pb(tmp[i-2]);
        v[1].pb(tmp.back());
    }
    if(!c){
    for(int i = 1;i<=n-1;i++){
        vector<int> tmp;
        for(int i =1;i<=n;i++){
            int ok=0;
            if(i==st){
                for(auto &it:v[i]){
                    if(it==i){
                        tmp.pb(it);
                        swap(it,v[i].back());
                        v[i].pop_back();
                        ok=1;
                        break;
                    }
                }
            }
            else{
                for(auto &it:v[i]){
                    if(it!=i){
                        tmp.pb(it);
                        swap(it,v[i].back());
                        v[i].pop_back();
                        ok=1;
                        break;
                    }
                }
                if(!ok){
                    tmp.pb(v[i].back());
                    v[i].pop_back();
                }
            }
        }
        ans.pb(tmp);
        for(int i = 2;i<=n;i++)v[i].pb(tmp[i-2]);
        v[1].pb(tmp.back());
    }
    int vis[505];
    fill(vis,vis+n+1,st);
    for(int i = 1;i<=n-1;i++){
        vector<int> tmp;
        for(int j=1;j<=n;j++){
            if(j==st)tmp.pb(((st-i-1)%n+n)%n+1),vis[st]=((st-i-1)%n+n)%n+1;
            else tmp.pb(vis[j]);
        }
        ans.pb(tmp);
        for(int i = n;i>1;i--)swap(vis[i],vis[i-1]);        
    }
    }
    printf("%d\n",ans.size());
    for(auto it:ans){
        for(auto it2:it)printf("%d ",it2);
        printf("\n");
    }
   // printf("\n");
}
int main(){
    int t=1;0000;
//    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}