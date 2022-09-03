#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define next Next
int main() {
    int q;
    scanf("%d",&q);
    while(q--){
        int b,w;
        scanf("%d %d",&b,&w);
        if(b>w){
            if(w*3+1<b){
                printf("NO\n");
                continue;
            }
            vector<pii> bb,ww;
            ww.pb(mp(3,3));
            bb.pb(mp(2,3));
            for(int i=5;ww.size()<w;i+=2){
                ww.pb(mp(i,3));
                bb.pb(mp(i-1,3));
            }
            for(int i = 3;bb.size()<b&&i<=ww.back().x;i+=2){
                bb.pb(mp(i,4));
            }
            for(int i = 3;bb.size()<b&&i<=ww.back().x;i+=2){
                bb.pb(mp(i,2));
            }
            if(bb.size()<b){
                bb.pb(mp(ww.back().x+1,3));
            }
            printf("YES\n");
            for(auto it:bb)
            printf("%d %d\n",it.x,it.y);
            for(auto it:ww)
            printf("%d %d\n",it.x,it.y);
        }
        else{
            if(b*3+1<w){
                printf("NO\n");
                continue;
            }
            vector<pii> bb,ww;
            ww.pb(mp(1,3));
            bb.pb(mp(2,3));
            for(int i=4;bb.size()<b;i+=2){
                bb.pb(mp(i,3));
                ww.pb(mp(i-1,3));
            }
            for(int i = 2;ww.size()<w&&i<=bb.back().x;i+=2){
                ww.pb(mp(i,4));
            }
            for(int i = 2;ww.size()<w&&i<=bb.back().x;i+=2){
                ww.pb(mp(i,2));
            }
            if(ww.size()<w){
                ww.pb(mp(bb.back().x+1,3));
            }
            printf("YES\n");
            for(auto it:bb)
            printf("%d %d\n",it.x,it.y);
            for(auto it:ww)
            printf("%d %d\n",it.x,it.y);
        }
    }
}