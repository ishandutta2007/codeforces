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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500
#define hash Hash
int main(){
    int n;
    scanf("%d",&n);
    pair<pair<pii,int>,int> p[50005];
    map<pii,vector<pii> > m;
    for(int i = 0;i<n;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        p[i]=mp(mp(mp(x,y),z),i+1);
        m[mp(x,y)].pb(mp(z,i+1));
    }
    map<int,vector<pii> > m1;
    for(auto& it:m){
        sort(it.y.begin(),it.y.end());
        while(it.y.size()>=2){
            pii p1=it.y.back();
            it.y.pop_back();
            pii p2=it.y.back();
            it.y.pop_back();
            printf("%d %d\n",p1.y,p2.y);
        }
        if(it.y.size()){
            m1[it.x.x].pb(mp(it.x.y,it.y[0].y));
        }
    }
    vector<pii> v;
    for(auto &it:m1){
        sort(it.y.begin(),it.y.end());
        while(it.y.size()>=2){
            pii p1=it.y.back();
            it.y.pop_back();
            pii p2=it.y.back();
            it.y.pop_back();
            printf("%d %d\n",p1.y,p2.y);
        }
        if(it.y.size()){
            v.pb(mp(it.x,it.y[0].y));
        }
    }
    sort(v.begin(),v.end());
    for(int i = 0;i<v.size();i+=2){
        printf("%d %d\n",v[i].y,v[i+1].y);
    }
   
}