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
//pii p[1005];
void solve(){
    int n;
    scanf("%d",&n);
    priority_queue<int> v[2];
    for(int i = 1;i<=n;i++){
        v[i&1].push(i);
    }
    vector<pii> ans;
    while(v[0].size()>1||v[1].size()>1){
        if(v[0].size()>1&&(v[1].size()<=1||v[0].top()>v[1].top())){
            int x=v[0].top();
            v[0].pop();
            
            int y=v[0].top();
            v[0].pop();
            ans.pb(mp(x,y));
            //printf("%d %d\n",x,y);
            x=(x+y)/2;
            v[x&1].push(x);
        }
        else{
            int x=v[1].top();
            v[1].pop();
            int y=v[1].top();
            v[1].pop();
            ans.pb(mp(x,y));
            //printf("%d %d\n",x,y);
            x=(x+y)/2;
            v[x&1].push(x);
        }
    }
    int tot=0;
    if(v[0].size()&&v[1].size()){
        ans.pb(mp(v[0].top(),v[1].top()));
    }
    if(v[0].size())tot+=v[0].top();
    if(v[1].size())tot+=v[1].top();
    //for(auto it:v[0])tot+=it;
    //for(auto it:v[1])tot+=it;
    printf("%d\n",(tot+v[0].size()+v[1].size()-1)/(v[0].size()+v[1].size()));
    for(auto it:ans){
        printf("%d %d\n",it.x,it.y);
    }
}
int main(){
/*    for(int i = 0;i<=1000;i++){
        p[i]=mp(-1,-1);
    }
    for(int i = 0;i*5<=1000;i++){
        for(int j = 0;i*5+j*7<=1000;j++){
            p[i*5+j*7]=mp(i,j);
        }
    }*/
    int t;
    scanf("%d",&t);
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