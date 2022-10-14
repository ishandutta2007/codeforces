/**
 *    author:  gary
 *    created: 30.10.2021 22:30:33
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        scanf("%d %d",&x,&y);
        int ans;
        if(x>y){
            ans=x+y;
            printf("%d\n",x+y);
        }
        if(x==y){
            ans=x;
            printf("%d\n",x);
        }
        if(x<y){
            int Cnt=(y-x)/x;
            x+=Cnt*x;
            ans=(x+y)/2;
            printf("%d\n",(x+y)/2);
        }
        assert(ans%x==y%ans);
    }
    return 0;
}