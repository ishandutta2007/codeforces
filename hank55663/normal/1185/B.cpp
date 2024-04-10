#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char c[1000005],c1[1000005];
        scanf("%s %s",c,c1);
        vector<pair<char,int> > v,v1;
        for(int i = 0;c[i]!=0;i++){
            if(v.empty()||v.back().x!=c[i]){
                v.pb(mp(c[i],1));
            }
            else{
                v.back().y++;
            }
        }
        for(int i = 0;c1[i]!=0;i++){
            if(v1.empty()||v1.back().x!=c1[i]){
                v1.pb(mp(c1[i],1));
            }
            else{
                v1.back().y++;
            }
        }
        if(v.size()!=v1.size()){
            printf("NO\n");
        }
        else{
            int ok=1;
            for(int i =0;i<v.size();i++){
                if(v[i].x!=v1[i].x){
                    ok=0;
                }
                if(v[i].y>v1[i].y){
                    ok=0;
                }
            }
            if(ok)printf("YES\n");
            else printf("NO\n");
        }
    }
}
/*
m3->m2->m->m4
0 1 2 3 4
0 1 3 2 4 4 2
0 1 4 2 3 3 2
0 2 1 3 4
0 2 3 1 4 4 1
0 2 4 1 3 3 1
0 3 1 2 4 4 2
0 3 2 1 4 4 1
0 4 1 
0 4 2
0 4 3

*/