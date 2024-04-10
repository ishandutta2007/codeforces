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
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
vector<int> go[200005];
int vis[200005];
int Size=450;
bool solve(){
    int n;
    scanf("%d",&n);
    vector<vector<int> > v;
    v.pb(vector<int>(0));
    map<int,int> m;
    for(int i = 1;i<=n;i++){
        int k;
        vector<int> tmp;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int x;
            scanf("%d",&x);
            tmp.pb(x);
            m[x];
        }
        v.pb(tmp);
        vis[i]=0;
    }
    int index=0;
    for(auto& it:m){
        it.y=++index;
        go[index].clear();
        vis[index]=0;
    }
    for(int i = 1;i<=n;i++){
        for(auto &it2:v[i]){
            it2=m[it2];
            go[it2].pb(i);
        }
    }
    for(int i = 1;i<=n;i++){
        if(v[i].size()>Size){
            for(auto it:v[i]){
                for(auto it2:go[it]){
                    if(it2==i)continue;
                    if(vis[it2]){
                        printf("%d %d\n",i,it2);
                        return true;
                    }
                    vis[it2]=1;
                }
            }
             for(auto it:v[i]){
                for(auto it2:go[it]){
                    vis[it2]=0;
                }
            }
        }
    }
    for(int i = 1;i<=index;i++){
        for(auto it:go[i]){
            if(v[it].size()<=Size){
                for(auto it2:v[it]){
                    if(it2==i)continue;
                    // printf("%d %d\n",it2,it);
                    if(vis[it2]){
                        printf("%d %d\n",it,vis[it2]);
                        return true;
                    }
                    vis[it2]=it;
                   
                }
            }
        }
        for(auto it:go[i]){
            if(v[it].size()<=Size){
                for(auto it2:v[it]){
                    vis[it2]=0;
                }
            }
        }
    }
    printf("-1\n");
    return true;
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/