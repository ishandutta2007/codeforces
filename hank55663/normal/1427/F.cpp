#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> E[2005];
int bln[2005];
int cnt[2005];
vector<int> num[2005];
void solve(){
    int n;
    scanf("%d",&n);
    int ok[2005];
    fill(ok,ok+2005,0);
    for(int i = 0;i<3*n;i++){
        int x;
        scanf("%d",&x);
        ok[x]++;
    }
    vector<pii> v;
    for(int i = 1;i<=n*6;i++){
        if(v.size()>=2){
            if(v.back().y==ok[i]&&v[v.size()-2].y==ok[i]){
                int x=v.back().x;
                v.pop_back();
                int x2=v.back().x;
                v.pop_back();
                bln[i]=x2;
                bln[x]=x2;
                bln[x2]=x2;
                num[x2].pb(i);
                num[x2].pb(x);
                num[x2].pb(x2);
                continue;
            }
        }
        v.pb(mp(i,ok[i]));
    }
    for(int i = 1;i<=n*6;i++){
        if(v.size()>=2){
            if(v.back().y==ok[i]&&v[v.size()-2].y==ok[i]){
                int x=v.back().x;
                v.pop_back();
                int x2=v.back().x;
                v.pop_back();
                if(v.size()){
                    E[x2].pb(bln[v.back().x]);
                    cnt[bln[v.back().x]]++;
                }
                //printf("%d\n",v.back())
                continue;
            }
        }
        v.pb(mp(i,ok[i]));
    }
    priority_queue<pii> q1,q2;
    for(int i = 1;i<=n*6;i++){
        if(bln[i]==i&&cnt[i]==0){
            if(ok[i]==1)q1.push(mp(E[i].size(),i));
            else q2.push(mp(E[i].size(),i));
        }
    }
    for(int i = 0;i<n;i++){
        
        if(q1.size()==0){
            printf("NO\n");
            return;
        //    nnum++;
        }
        int x=q1.top().y;
        q1.pop();
        sort(num[x].begin(),num[x].end());
        for(auto it:num[x]){
            printf("%d ",it);
        }
        printf("\n");
        for(auto it:E[x]){
            if(--cnt[it]==0){
                if(ok[it]==1)q1.push(mp(E[it].size(),it));
                else q2.push(mp(E[it].size(),it));
            }
        }
        assert(q2.size());
        x=q2.top().y;
        q2.pop();
        sort(num[x].begin(),num[x].end());
        for(auto it:num[x]){
            printf("%d ",it);
        }
        printf("\n");
        for(auto it:E[x]){
            if(--cnt[it]==0){
                if(ok[it]==1)q1.push(mp(E[it].size(),it));
                else q2.push(mp(E[it].size(),it));
            }
        }
    }
}

int main(){
    int t=1;
    while(t--){
        solve();
    }
}
/*


*/
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/