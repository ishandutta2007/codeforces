/**
 *    author:  gary
 *    created: 10.10.2021 17:46:46
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
#define double long double
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e5+1;
int n,k;
int p=0;
mp a[MAXN];
double dist(mp A,mp B){
    double d1,d2;
    d1=A.FIR-B.FIR;
    d2=A.SEC-B.SEC;
    return sqrt(d1*d1+d2*d2);
}
double solvetor(vector<mp> x){
    double tmp=dist(x[0],x.back());
    tmp+=dist(x.back(),a[p]);
    rep(i,x.size()-1) check_min(tmp,dist(x[i],x[0])+dist(x[i+1],x.back())+dist(x[i],a[p])+dist(a[p],x[i+1]));
    return tmp;
}
double solvetol(vector<mp> x){
    double tmp=dist(x[0],x.back());
    tmp+=dist(x[0],a[p]);
    rep(i,x.size()-1) check_min(tmp,dist(x[i],x[0])+dist(x[i+1],x.back())+dist(x[i],a[p])+dist(a[p],x[i+1]));
    return tmp;
}
int main(){
    scanf("%d%d",&n,&k);
    rb(i,1,n) scanf("%d%d",&a[i].FIR,&a[i].SEC);
    SRAND;
    while (true)
    {
        int x,y;
        x=random(n)+1;
        y=random(n)+1;
        if(x!=y){
            vector<int> tmp;
            rb(i,1,n) if(i!=y&&i!=x){
                if(1ll*(a[i].SEC-a[y].SEC)*(a[i].FIR-a[x].FIR)==1ll*(a[i].SEC-a[x].SEC)*(a[i].FIR-a[y].FIR));
                else tmp.PB(i);
            }
            if(tmp.size()==1){
                p=tmp[0];
                break;
            }
        }
    }
    vector<mp> ano;
    rb(i,1,n) if(i!=p) ano.PB(a[i]);
    sort(ALL(ano));
    // cout<<p<<endl;
    if(k==p){
        double ans=1e18;
        double dis=dist(ano[0],ano.back());
        rb(i,1,n) if(i!=p) check_min(ans,dis+dist(a[i],a[p])+min(dist(a[i],ano[0]),dist(a[i],ano.back())));
        printf("%.10Lf\n",ans);
    }
    else{
        double ans=1e18;
        if(a[k]==ano[0]){
            check_min(ans,solvetor(ano));
        }
        else
        if(a[k]==ano.back()){
            check_min(ans,solvetol(ano));
        }
        else{
            ano.clear();
            rb(i,1,n) if(i!=p&&i!=k) ano.PB(a[i]);
            sort(ALL(ano));
            check_min(ans,solvetor(ano)+dist(a[k],ano[0]));
            check_min(ans,solvetol(ano)+dist(a[k],ano.back()));
            rep(i,ano.size()){
                if(i!=ano.size()-1){
                    check_min(ans,dist(a[k],ano[i])+dist(ano[0],ano[i])+dist(ano[i+1],ano.back())+dist(ano[0],a[p])+dist(ano[i+1],a[p]));   
                    check_min(ans,dist(a[k],ano[i+1])+dist(ano[i+1],ano.back())+dist(ano[i],ano[0])+dist(ano.back(),a[p])+dist(ano[i],a[p]));
                }
            }
        }
        ano.clear();
        rb(i,1,n) if(i!=p&&i!=k) ano.PB(a[i]);
        sort(ALL(ano));
        check_min(ans,dist(a[k],a[p])+dist(ano[0],ano.back())+min(dist(a[p],ano[0]),dist(a[p],ano.back())));
        printf("%.10Lf\n",ans);
    }
    return 0;
}