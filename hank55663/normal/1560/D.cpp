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
void solve(){
    int n;
    scanf("%d",&n);
    int aans=100;
    for(LL i = 0;i<=61;i++){
        LL ans=1ll<<i;
        vector<int> v1,v2;
        while(ans){
            v1.pb(ans%10);
            ans/=10;
        }
        LL tmp=n;
        while(tmp){
            v2.pb(tmp%10);
            tmp/=10;
        }
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        int now=0;
        for(auto it:v2){
            if(now!=v1.size()&&v1[now]==it)now++;
        }
        aans=min(aans,(int)(v2.size()-now+v1.size()-now));
    }
    printf("%d\n",aans);
        
}
int main(){
    int t=1;//00;//00;
    scanf("%d",&t);
    while(t--){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/