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
map<int,vector<pii> > X,Y;
int f[200005];
int Min[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    X.clear();
    Y.clear();
    int n,k;
    scanf("%d %d",&n,&k);
    for(int j = 0;j<n;j++){
        int x,y,d;
        scanf("%d %d %d",&x,&y,&d);
        X[x].pb(mp(y,j));
        Y[y].pb(mp(x,j));
        f[j]=j;
        Min[j]=d;
    }
    for(auto it:X){
        sort(it.y.begin(),it.y.end());
        for(int j=1;j<it.y.size();j++){
            if(it.y[j].x-it.y[j-1].x<=k){
                int a=Find(it.y[j].y),b=Find(it.y[j-1].y);
                f[b]=a;
                Min[a]=min(Min[a],Min[b]);
            }
        }
    }
    for(auto it:Y){
        sort(it.y.begin(),it.y.end());
        for(int j=1;j<it.y.size();j++){
            if(it.y[j].x-it.y[j-1].x<=k){
                int a=Find(it.y[j].y),b=Find(it.y[j-1].y);
                f[b]=a;
                Min[a]=min(Min[a],Min[b]);
            }
        }
    }
    vector<int> tmp;
    for(int i = 0;i<n;i++){
        if(f[i]==i)tmp.pb(Min[i]);
    }
    sort(tmp.begin(),tmp.end());
        tmp.pop_back();
    reverse(tmp.begin(),tmp.end());

    if(tmp.empty()){
        printf("0\n");
        return;
    }
    for(int i=0;i<tmp.size();i++){
        if(tmp[i]<=i){
            printf("%d\n",i);
            return;
        }
    }
    printf("%d\n",tmp.size());
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}