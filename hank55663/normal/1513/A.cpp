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
//const int mod=1e9+7;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(k>(n-1)/2){
        printf("-1\n");
    }
    else{
        vector<int> v;
        for(int i = 0;i<n;i++){
            if(i%2==1){
                if(k){
                    v.pb(0);
                    k--;
                }
                else{
                    v.pb(1);
                }
            }
            else{
                v.pb(1);
            }
        }
        int now=1;
        for(auto &it:v){
            if(it==1)it=now++;
        }
        for(auto &it:v){
            if(it==0)it=now++;
        }
        for(auto it:v){
            printf("%d ",it);
        }
        printf("\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}