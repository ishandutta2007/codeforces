/**
 *    author:  gary
 *    created: 02.10.2022 22:42:27
**/
#include<bits/stdc++.h>
#define double long double
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
double p[300000+20],q[300000+20];
struct cmp{
    bool operator () (const pair<double,double> &x,const pair<double,double> &y)const{
        return x.second*y.first>y.second*x.first;
    }
};
void solve(){
    multiset<pair<double,double>,cmp> ds;
    pair<double,double> l,r;
    int n;
    cin>>n;
    double a,b;
    cin>>a>>b;
    rb(i,1,n) cin>>p[i];
    rb(i,1,n) cin>>q[i];
    l=r=II(a,b);
    rb(i,1,n){
        double dx=p[i],dy=-q[i];
        l.first-=dx,l.second-=dy;
        r.first+=dx,r.second+=dy;
        ds.insert(II(dx*2,dy*2));
        while (l.first<0){
            auto ite=*ds.begin();
            ds.erase(ds.begin());
            if(ite.first>-l.first){
                double z=ite.second*-l.first/ite.first;
                ite.first+=l.first;
                l.first=0;
                l.second+=z;
                ite.second-=z;
                ds.insert(ite);
            }
            else{
                l.first+=ite.first;
                l.second+=ite.second;
            }
        }
        while (r.second<0){
            auto ite=*prev(ds.end());
            ds.erase(prev(ds.end()));
            if(-ite.second>-r.second){
                double z=ite.first*-r.second/-ite.second;
                ite.second-=r.second;
                r.first-=z;
                r.second=0;
                ite.first-=z;
                ds.insert(ite);
            }
            else{
                r.first-=ite.first;
                r.second-=ite.second;
            }
        }
        cout<<fixed<<setprecision(10)<<r.first<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}