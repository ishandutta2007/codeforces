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
#define N 200005
#define rank Rank
#define index Index
pii p[2][1005];
bool check(vector<int> v,int axis){
    if(v.size()==1)
    return true;
    vector<int> tmp;
    vector<pair<int,pii> > vv;
    for(auto it:v){
        vv.pb(mp(p[axis][it].x,mp(1,it)));
        vv.pb(mp(p[axis][it].y,mp(-1,it)));
    }
    sort(vv.begin(),vv.end());
    bool res=true;
    int sum=0;
    for(auto it:vv){
        if(it.y.x==1){
            tmp.pb(it.y.y);
        }
        sum+=it.y.x;
        if(sum==0){
            if(tmp.size()==v.size())return false;
            res&=check(tmp,axis^1);
            tmp.clear();
        }
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        p[0][i]=mp(a,c);
        p[1][i]=mp(b,d);
    }
    vector<int> v;
    for(int i = 0;i<n;i++){
        v.pb(i);
    }
    if(check(v,0)||check(v,1)){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}