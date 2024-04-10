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
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    vector<pii> v;
    int ans=0;
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        for(auto &it:v){
            it.x=__gcd(it.x,x);
        }
        vector<pii> tmp;
        for(auto it:v){
            if(tmp.size()&&it.x==tmp.back().x)continue;
            tmp.pb(it);
        }
       
        tmp.pb(mp(x,i));
      //   for(auto it:tmp)printf("%d %d\n",it.x,it.y);
        int rm=0;
        int last=0;
        reverse(tmp.begin(),tmp.end());
        for(auto it:tmp){
        //    printf("%d %d %d\n",it.x,i-it.y+1,last);
            if(it.x<=i-it.y+1&&it.x>last){
                ans++;
                rm=1;
                tmp.clear();
                break;
            }
            last=i-it.y+1;
        }
          reverse(tmp.begin(),tmp.end());
        swap(v,tmp);
        printf("%d ",ans);
    }
    printf("\n");
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
(k_1x+b)k_2+b=y

36
0123
0123 4567
*/