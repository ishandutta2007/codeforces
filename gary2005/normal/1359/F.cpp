/**
 *    author:  gary
 *    created: 15.03.2022 16:24:01
**/
#include<bits/stdc++.h>
#define double long double
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<double,double> mp;
const double eps=1e-12;
const double theta=1.14514;
const int MAXN=25000+10;
mp rotate(mp A){
    double x,y;
    x=A.first;
    y=A.second;
    return II(cos(theta)*x-sin(theta)*y,sin(theta)*x+cos(theta)*y);
}
int n,x[MAXN],y[MAXN];
double dx[MAXN],dy[MAXN],s[MAXN];
mp getline(pair<mp,mp> A){
    // (A.SEC.SEC-y)/(A.SEC.FIR-x)=(A.SEC.SEC-A.FIR.SEC)/(A.SEC.FIR-A.FIR.FIR)
    double t=(A.SEC.SEC-A.FIR.SEC)/(A.SEC.FIR-A.FIR.FIR);
    double k,b;
    b=A.second.second-t*A.second.first;
    k=t;
    return II(k,b);
}
double T;
double crosstime(mp la,mp lb){
    if(abs(la.first-lb.first)<eps) {
        if(abs(la.second-lb.second)<10*eps) return T+eps;
        return 1e18;
    }
    return (lb.second-la.second)/(la.first-lb.first);
}
struct cmp
{
    bool operator () (const pair<mp,int> &A,const pair<mp,int> &B) const{
        if(abs((A.first.first*T+A.first.second)-(B.first.first*T+B.first.second))<10*eps) return A.second<B.second;
        return II(A.first.first*T+A.first.second,A.second)<II(B.first.first*T+B.first.second,B.second);
    }
};
bool check(double t){
    set<pair<mp,int> ,cmp> se;
    vector<pair<mp,mp> > seg;
    rb(i,1,n) seg.PB(II(II(x[i]-3*(eps)*s[i]*dx[i],y[i]-3*(eps)*s[i]*dy[i]),II(x[i]+t*s[i]*dx[i],y[i]+t*s[i]*dy[i])));
    //for(auto & it:seg) it.first=rotate(it.first),it.second=rotate(it.second);
    T=0;
    vector<pair<double,pair<mp,int> > > eve;
    int cnt=0;
    for(auto it:seg){
        if(it.first.first>it.second.first) swap(it.first,it.second);
        // cout<<it.first.first<<" "<<it.first.second<<' '<<it.second.first<<' '<<it.second.second<<endl;
        auto L=getline(it);
        ++cnt;
        eve.PB(II(it.first.first,II(L,cnt)));
        eve.PB(II(it.second.first,II(L,-cnt)));
    }
    sort(ALL(eve));
    multiset<double> cr;
    for(auto it:eve){
        T=it.first;
        auto tmp=it.second;
        if(cr.size()&&*cr.begin()<=T+5*eps) return true;
        // cout<<T<<" "<<tmp.first.first<<" "<<tmp.first.second<<" "<<tmp.second<<"!"<<" "<<cr.size()<<endl;
        if(tmp.second<0){
            auto ite=se.find(II(tmp.first,-tmp.second));
            assert(ite!=se.end());
            // cout<<"!"<<endl;
            if(ite!=se.begin()){
                auto pr=prev(ite);
                auto t=crosstime(pr->first,ite->first);
                if(t>T+3*eps){
                    // cout<<t<<" "<<T<<" "<<cr.size()<<endl;
                    cr.erase(cr.lower_bound(t-eps));
                }
            }
            // cout<<"#"<<endl;
            if(next(ite)!=se.end()){
                auto pr=next(ite);
                auto t=crosstime(pr->first,ite->first);
                if(t>T+3*eps){
                    cr.erase(cr.lower_bound(t-eps));
                }
            }
            if(ite!=se.begin()&&next(ite)!=se.end()){
                auto pr=prev(ite);
                auto t=crosstime(pr->first,next(ite)->first);
                if(t>T-3*eps){
                    cr.insert(t);
                }
            }
            se.erase(ite);
        }
        else{
            se.insert(tmp);
            auto ite=se.find(tmp);
            if(ite!=se.begin()){
                auto pr=prev(ite);
                auto t=crosstime(pr->first,ite->first);
                // cout<<t<<" "<<T<<endl;
                if(abs(t-T)<1e-10) return 1;
                if(t>T-3*eps){
                    cr.insert(t);
                }
            }
            if(next(ite)!=se.end()){
                auto pr=next(ite);
                auto t=crosstime(pr->first,ite->first);
                // cout<<t<<' '<<T<<" "<<endl;
                if(abs(t-T)<1e-10) return 1;
                if(t>T-3*eps){
                    // cout<<"#"<<endl;
                    cr.insert(t);
                }
            }
            if(ite!=se.begin()&&next(ite)!=se.end()){
                auto pr=prev(ite);
                auto t=crosstime(pr->first,next(ite)->first);
                if(t>T+3*eps){
                    cr.erase(cr.lower_bound(t-eps));
                }
            }
        }
        if(cr.size()&&*cr.begin()<=T+10*eps) return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n){ cin>>x[i]>>y[i]>>dx[i]>>dy[i]>>s[i];
    double d=sqrt(dx[i]*dx[i]+dy[i]*dy[i]);
    dx[i]/=d;
    dy[i]/=d;
    }
    double l,r;
    if(!check(6e9)){
        cout<<"No show :(\n";
        return 0;
    }
    // cout<<check(15)<<endl;
    // return 0;
    if(check(1)){
        l=0,r=1;
        while (abs(r-l)>1e-6){
            double mid=(r+l)/2;
            if(check(mid)) r=mid;
            else l=mid;
        }
    }
    else{
        l=1,r=6e9;
        while (abs(r-l)/l>1e-6){
            double mid=sqrt(r*l);
            if(check(mid)) r=mid;
            else l=mid;
        }
    }
    cout<<fixed<<setprecision(10)<<l<<endl;
    return 0;
}