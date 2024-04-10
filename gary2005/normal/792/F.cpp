/**
 *    author:  gary
 *    created: 15.11.2021 08:12:40
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
SRAND;
namespace DCH{
    //  y = kx + b
    //  max{fi(x)}
    // k,b,fi(x),x double ,  [-1e9,1e9]
    // in O(log N)
    const double eps=1e-9;
    struct line{
        double k,b;
        line (double A,double B){
            k=A;
            b=B;
        }
        double operator () (double x) const{
            return k*x+b;
        }
    };
    struct cmp1{// slope
        bool operator () (const pair<pair<double,double>,line> & A,const pair<pair<double,double>,line> & B) const{
            return A.SEC.k<B.SEC.k;
        }
    };
    struct cmp2{// segment
        bool operator () (const pair<pair<double,double>,line> & A,const pair<pair<double,double>,line> & B) const{
            return A.FIR.FIR<B.FIR.FIR;
        }
    };
    double work_cross(line A,line B){
        // Ak x+ Ab = Bk x + Bb
        return (B.b-A.b)/(A.k-B.k);
    }
    struct Dynamic_Convex_Hull{
        set<pair<pair<double,double>,line> ,cmp1> s1;
        set<pair<pair<double,double>,line> ,cmp2> s2;
        void ins(pair<pair<double,double>,line> L){s1.insert(L),s2.insert(L);}
        void era(pair<pair<double,double>,line> L){s1.erase(L),s2.erase(L);}
        void add_line(line A){
            auto ite=s1.lower_bound(II(II(0,0),line(A.k-eps,A.b)));
            if(ite!=s1.end()&&abs(ite->SEC.k-A.k)<eps){
                if(ite->SEC.b>A.b-eps) return ;
                s2.erase(*ite);
                ite=s1.erase(ite);
            }
            while(ite!=s1.end()&&work_cross(ite->SEC,A)>ite->FIR.SEC-eps){
                s2.erase(*ite);
                ite=s1.erase(ite);
            }
            if(ite!=s1.end()){
                double r=ite->FIR.SEC;
                double l=max(ite->FIR.FIR,work_cross(ite->SEC,A));
                line tmp=ite->SEC;
                era(*ite);
                ins(II(II(l,r),tmp));
            }
            ite=s1.lower_bound(II(II(0,0),line(A.k-eps,A.b)));
            while(ite!=s1.begin()){
                auto pr=prev(ite);
                if(work_cross(pr->SEC,A)>pr->FIR.FIR+eps) break;
                s2.erase(*pr);
                ite=s1.erase(pr);
            }
            if(ite!=s1.begin()){
                auto pr=prev(ite);
                double l=pr->FIR.FIR;
                double r=min(pr->FIR.SEC,work_cross(pr->SEC,A));
                line tmp=pr->SEC;
                era(*pr);
                ins(II(II(l,r),tmp));
            }
            ite=s1.lower_bound(II(II(0,0),line(A.k-eps,A.b)));
            double l=(ite==s1.begin()? -1e18:work_cross(prev(ite)->SEC,A));
            double r=(ite==s1.end()? 1e18:work_cross(ite->SEC,A));
            if(l<r-eps) ins(II(II(l,r),A));
        }
        double query(double x){
            auto ite=s2.lower_bound(II(II(x,1e18),line(0,0)));
            return prev(ite)->SEC(x);
        }
    };
}
DCH :: Dynamic_Convex_Hull hull;
double P2(double P1){
    return max(0.0,hull.query(P1));
}
const double E=1e-4;
double m;
double query(double t){
    double l=0,r=1e6;
    while(r-l>1e-9){
        double P1=(l+r)/2;
        if(m*P1+t*P2(P1)>m*(P1+(1e-9))+t*P2(P1+(1e-9))) l=P1+E;
        else r=P1;
    }
    return m*l+t*P2(l);
}
int main(){
    int q;
    scanf("%d%lf",&q,&m);
    int j=0;
    rb(i,1,q){
        int k,a,b;
        scanf("%d%d%d",&k,&a,&b);
        ((a+=j)%=1000000)++;
        ((b+=j)%=1000000)++;
        if(k==1){
            hull.add_line(DCH::line(-b,a));
        }
        else{
            if(!hull.s1.empty()&&query(a)+DCH::eps>b){
                j=i;
                puts("YES");
            }
            else{
                puts("NO");
            }
        }
    }
    return 0;
}