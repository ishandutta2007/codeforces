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
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005];
    int last=1;
    vector<pii> v;
    vector<int> v2,v3;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==0){
        }
        else if(a[i]==1){
            if(v2.size()){
                v.pb(mp(v2.back(),i));
                v2.pop_back();
            }
            else if(v3.size()){
                v.pb(mp(v3.back()+1,i));
                v.pb(mp(v3.back(),i));
                v3.pop_back();
            }
            else{
                v.pb(mp(last++,i));
            }
        }
        else if(a[i]==2){
            if(v3.size()){
                v.pb(mp(v3.back()+1,i));
                v.pb(mp(v3.back(),i));
                v2.pb(v3.back()+1);
                v3.pop_back();
            }
            else{
                v.pb(mp(last,i));
                v2.pb(last);
                last++;
            }
        }
        else{
            if(v3.size()){
                v.pb(mp(v3.back()+1,i));
                v.pb(mp(v3.back(),i));
                int x=v3.back();
                v3.pop_back();
                v3.pb(x+1);
                last++;
            }
            else{
                v.pb(mp(last,i));
                v3.pb(last);
                last+=2;
            }
        }
      //  printf("%d %d\n",v2.size(),v3.size());
    }
    int cnt[100005];
    fill(cnt,cnt+100005,0);
    if(v3.size()||v2.size()){
        printf("-1\n");
        return;
    }
    for(auto it:v){
    //    printf("%d %d\n",it.x,it.y);
        cnt[it.x]++;
        if(it.x>n||it.y>n||cnt[it.x]>2){
            printf("-1\n");//%d %d %d\n",it.x,it.y,cnt[it.x]);
            return;
        }
    }
    printf("%d\n",v.size());
    for(auto it:v){
        printf("%d %d\n",it.x,it.y);
    }
}



int main(){
    int t=1;
  //  scanf("%d",&t);
   
    while(t--){
        solve();
    }
}
/*
5 0 5
10 0
-10 0
-20 10
0 30
20 10
*/