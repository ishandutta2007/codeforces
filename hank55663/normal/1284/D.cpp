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
#define MXN 200005
ULL myrand(){
    return ((ULL)rand()<<60)+((ULL)rand()<<45)+((ULL)rand()<<30)+((ULL)rand()<<15)+rand();
}
int main(){ 
    int n;
    scanf("%d",&n);
    tuple<pii,pii,ULL> p[100005];
    ULL sum=0;
    srand(time(NULL));
    for(int i = 0;i<n;i++){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        ULL x=myrand();
        p[i]=make_tuple(mp(a,b),mp(c,d),x);
        sum^=x;
    }
    vector<pair<int,ULL> > v;
    vector<pair<int,ULL> > v2;
    v.pb(mp(0,0));
    v2.pb(mp(0,0));
    for(int i = 0;i<n;i++){
        v.pb(mp(get<0>(p[i]).y,get<2>(p[i])));
        v2.pb(mp(get<0>(p[i]).x,get<2>(p[i])));
    }
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    for(int i = 1;i<v.size();i++){
        v[i].y^=v[i-1].y;
        v2[i].y^=v2[i-1].y;
    }
    LL val1[100005];
    for(int i = 0;i<n;i++){
        int a,b;
        tie(a,b)=get<0>(p[i]);
        val1[i]=((prev(lower_bound(v.begin(),v.end(),mp(a,0ull))))->y^sum^(prev(upper_bound(v2.begin(),v2.end(),mp(b,18446744073709551615ull))))->y);
    }
    v.clear();
    v2.clear();
    v.pb(mp(0,0));
    v2.pb(mp(0,0));
    for(int i = 0;i<n;i++){
        v.pb(mp(get<1>(p[i]).y,get<2>(p[i])));
        v2.pb(mp(get<1>(p[i]).x,get<2>(p[i])));
    }
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    for(int i = 1;i<v.size();i++){
        v[i].y^=v[i-1].y;
        v2[i].y^=v2[i-1].y;
    }
    for(int i = 0;i<n;i++){
        int a,b;
        tie(a,b)=get<1>(p[i]);
        if(val1[i]!=(prev(lower_bound(v.begin(),v.end(),mp(a,0ull)))->y^sum^(prev(upper_bound(v2.begin(),v2.end(),mp(b,18446744073709551615ull)))->y))){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}
/**/