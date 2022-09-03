#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
#define MXN 2005
void solve(){
    int n;
    scanf("%d",&n);
    pii p[200005];
    map<pii,pii> s;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        s[mp(x,y)]=mp(-1000000000,-1000000000);
        p[i]=mp(x,y);
    }
    queue<pii> q;
    for(auto &it:s){
        int X[4]={0,0,1,-1};
        int Y[4]={1,-1,0,0};
        for(int j = 0;j<4;j++){
            int x=X[j]+it.x.x,y=Y[j]+it.x.y;
            if(s.find(mp(x,y))==s.end()){
                q.push(it.x);
                it.y=mp(x,y);
            }
        }
    }
   // for(auto it:s){
    //    printf("%d %d %d %d\n",it.x.x,it.x.y,it.y.x,it.y.y);
   // }
    while(!q.empty()){
        pii p=q.front();
        //printf("%d %d\n",p.x,p.y);
        q.pop();
        int X[4]={0,0,1,-1};
        int Y[4]={1,-1,0,0};
        for(int j = 0;j<4;j++){
            int x=X[j]+p.x,y=Y[j]+p.y;
            if(s.find(mp(x,y))!=s.end()&&s[mp(x,y)]==mp(-1000000000,-1000000000)){
                q.push(mp(x,y));
                s[mp(x,y)]=s[p];
               // printf("?%d %d\n",x,y);
            }
        }
    }
    for(int i =0;i<n;i++){
        printf("%d %d\n",s[p[i]].x,s[p[i]].y);
    }
}
int main(){
    int t=1;0000;
   //   scanf("%d",&t);
   //  while(solve());
     
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
342475
784728
394591
622354
489948
37187.5
586271
70934.1
463806
235009
528719
786392
717050
936731
250005
382783
953168
610086
*/