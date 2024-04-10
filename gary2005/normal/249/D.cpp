/**
 *    author:  gary
 *    created: 18.01.2022 18:45:38
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
const int MAXN=1e5+10;
int n;
double alpha3,d;
pair<double,double> p[MAXN];
int dp[MAXN];
map<double,int> heap;
void ins(double key,int val){
    if(heap.find(key)!=heap.end()) check_min(heap[key],val);
    else{
        heap[key]=val;
        auto ite=next(heap.find(key));
        while(ite!=heap.end()&&ite->SEC<=val) ite=heap.erase(ite);
    }
}
vector<pair<double,int> > v;
void f1(int l1,int r1,int l2,int r2){
    v.clear();
    heap.clear();
    rb(i,l1,r1) v.PB(II(p[i].SEC,i));
    rb(i,l2,r2) v.PB(II(p[i].SEC,i));
    sort(ALL(v));
    for(auto it:v){
        if(it.SEC>=l2){
            ins(-p[it.SEC].FIR*d-it.FIR,dp[it.SEC]);
        }
        else{
            auto ite=heap.lower_bound(-p[it.SEC].FIR*d-it.FIR-(1e-10));
            if(ite!=heap.begin()){
                ite--;
                check_max(dp[it.SEC],ite->SEC+1);
            }
        }
    }
}
void f2(int l1,int r1,int l2,int r2){
    heap.clear();
    reverse(ALL(v));
    for(auto it:v){
        if(it.SEC>=l2){
            ins(-p[it.SEC].FIR*d+it.FIR,dp[it.SEC]);
        }
        else{
            auto ite=heap.lower_bound(-p[it.SEC].FIR*d+it.FIR-(1e-10));
            if(ite!=heap.begin()){
                ite--;
                check_max(dp[it.SEC],ite->SEC+1);
            }
        }
    }
}
void cdq(int l,int r){
    if(l==r){
        check_max(dp[l],1);
        return ;
    }
    int mid=(l+r)>>1;
    cdq(mid+1,r);
    f1(l,mid,mid+1,r);
    f2(l,mid,mid+1,r);
    cdq(l,mid);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    char ccc;
    cin>>n;
    double a,b,c,D;
    cin>>a>>ccc>>b;
    cin>>c>>ccc>>D;
    double alpha1,alpha2;
    alpha1=atan2(a,b);
    alpha2=atan2(c,D);
    d=(alpha2-alpha1)/2.0;
    alpha3=2*3.141592653589793-(alpha1+alpha2)/2.0;
    d=tan(d);
    rb(i,1,n){
        double x,y;
        cin>>x>>y;
        auto tmp=II(cos(alpha3)*x-sin(alpha3)*y,sin(alpha3)*x+cos(alpha3)*y);
        tie(x,y)=tmp;
        p[i]=II(x,y);
    }
    p[++n]=II(0,0);
    sort(p+1,p+1+n);
    cdq(1,n);
    cout<<dp[1]-1<<endl;
    return 0;
}