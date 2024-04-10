/**
 *    author:  gary
 *    created: 08.03.2022 10:17:31
**/ 
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse","avx")
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
const double pi = 3.1415926535897932384626433832795;
const double eps = 1e-10;
struct vec {
    double x, y;
    vec() {}
    vec(double X, double Y) {
        x = X;
        y = Y;
    }
    bool operator < (const vec &oth) const{
        if (x != oth.x)
            return x < oth.x;

        return y < oth.y;
    }
    double operator * (vec oth) {
        return x * oth.y - oth.x * y;
    }
    vec operator - (vec oth) {
        return vec(x - oth.x, y - oth.y);
    }
    vec operator + (vec oth) {
        return vec(x + oth.x, y + oth.y);
    }
    bool operator != (vec oth) {
        return (abs(x - oth.x) > eps) || (abs(y - oth.y) > eps);
    }
};
double angle(vec v) {
    if (v.y >= 0) {
        if (abs(v.x) <= eps)
            return pi / 2.0;

        if (v.x > eps) {
            return atan(v.y / v.x);
        } else
            return atan(v.y / v.x) + pi;
    }

    if (abs(v.x) <= eps)
        return pi / 2.0 + pi;

    if (v.x > eps) {
        return atan(v.y / v.x) + 2.0 * pi;
    }

    return atan(v.y / v.x) + pi;
}
bool cmp(vec A, vec B) {
    return angle(A) < angle(B);
}
vector<int> sta;
bool used[22];
struct convex_hull {
    vector<vec> v;
    convex_hull() {}
    convex_hull(vector<vec> points) {
        if(points.size()==2){
            v=points;
            return;
        }
        memset(used, 0, sizeof(used));
        sta.clear();
        sta.PB(0);
        sort(ALL(points));
        rep(i, points.size()) {
            if (!i)
                continue;

            while (sta.size() > 1 &&
                    (points[sta.back()] - points[sta[sta.size() - 2]]) * (points[i] - points[sta.back()]) <= 0) {
                used[sta.back()] = 0;
                sta.POB();
            }

            used[i] = 1;
            sta.PB(i);
        }
        int tmp = sta.size();
        rl(i, points.size() - 1, 0) {
            if (used[i])
                continue;

            while (sta.size() > tmp &&
                    (points[sta.back()] - points[sta[sta.size() - 2]]) * (points[i] - points[sta.back()]) <= 0)
                sta.POB();

            sta.PB(i);
        }

        for (auto it : sta)
            v.PB(points[it]);

        v.POB();
    }
};
int n,l,k;
double x[50000+10],y[50000+10];
vector<int> v;
SRAND;
double radius;
double dist(int A,int B){
    return sqrt((x[A]-x[B])*(x[A]-x[B])+(y[A]-y[B])*(y[A]-y[B]));
}
bool checkp(vector<vec> & ve,double X,double Y){
    for(auto it:ve){
        if((X-it.x)*(X-it.x)+(Y-it.y)*(Y-it.y)>radius*radius) return false;
    }
    return 1;
}
tuple<double,double,double> line(vec A,vec B){
    // ax+by+c=0
    if(A.x==B.x){
        return {0,1,-(A.y+B.y)/2.0};
    }
    if(A.y==B.y){
        return {1,0,-(A.x+B.x)/2.0};
    }
    double k=(B.y-A.y)/(B.x-A.x);
    k=-1.0/k;
    auto mid=(A+B);
    mid.x/=2;
    mid.y/=2;
    return {k,-1,-mid.x*k+mid.y};
}
bool checkv(){
    vector<vec> conv;
    for(auto it:v) conv.PB(vec(x[it],y[it]));
    conv=convex_hull(conv).v;
    rep(i,conv.size()){
        rep(j,i){
            if(checkp(conv,(conv[i].x+conv[j].x)/2,(conv[i].y+conv[j].y)/2)){
                return true;
            }
        }
    }
    rep(i,conv.size()){
        rep(j,i){
            rep(z,j){
                vec a,b,c;
                a=conv[i];
                b=conv[j];
                c=conv[z];
                if(a.x==b.x&&b.x==c.x) continue;
                if(a.y==b.y&&b.y==c.y) continue;
                auto A=line(a,b);
                auto B=line(b,c);
                double d[3]={get<0>(A),get<1>(A),get<2>(A)};
                double e[3]={get<0>(B),get<1>(B),get<2>(B)};
                d[0]*=114,d[1]*=114,d[2]*=114;
                e[0]*=514,e[1]*=514,e[2]*=514;
                rep(i,3){
                    double T,S;
                    T=d[i]+e[i];
                    S=d[i]-e[i];
                    d[i]=T;
                    e[i]=S;
                }
                double o=d[0];
                d[0]/=o,d[1]/=o,d[2]/=o;
                double h=e[0];
                e[0]/=h,e[1]/=h,e[2]/=h;
                double Y=(d[2]-e[2])/(e[1]-d[1]);
                double X=(-d[2]-d[1]*Y);
                if(checkp(conv,X,Y)) return 1;
            }
        }
    }
    return false;
}
bool findtwo(vector<int> g){
    if(v.size()==k) return checkv();
    int now=g.back();
    g.pop_back();
    if(g.size()+v.size()>=k)
    if(findtwo(g)) return 1;
    rep(i,g.size()){
        if(dist(g[i],now)>2*radius){
            swap(g[i],g.back());
            i--;
            g.pop_back();
        }
    }
    v.PB(now);
    if(v.size()+g.size()>=k)
    if(findtwo(g)) return 1;
    v.pop_back();
    return 0;
}
void mergesort(vector<int> &A,vector<int> B){
    if(A.empty()) A=B;
    else{
        vector<int> C;
        int p1=0,p2=0;
        while(p1<A.size()||p2<B.size()){
            if(p1==A.size()){
                C.PB(B[p2++]);
                continue;
            }
            if(p2==B.size()){
                C.PB(A[p1++]);
                continue;
            }
            if(A[p1]<B[p2]){
                C.PB(A[p1++]);
                continue;
            }
            else{
                C.PB(B[p2++]);
                continue;
            }
        }
        A=C;
    }
}
int cnt;
int vis[50000+10];
bool findone(vector<int> &can){
    int r=0;
    rep(i,can.size()){
        while(r+1<can.size()&&can[r+1]-can[i]<=l-1) r++;
        if(can.size()-i<k) return 0;
        if(r-i+1>=k&&vis[can[i]]==cnt){
            vector<int> EMP;
            EMP.swap(v);
            vector<int> g;
            rb(j,i+1,r) if(dist(can[j],can[i])<=2*radius) g.PB(can[j]);
            v.PB(can[i]);
            if(g.size()+1>=k)
            if(findtwo(g)) return 1;
        }
    }
    return 0;
}
int grid[9][2]={
{0,0},
{-1,0},
{1,0},
{-1,-1},
{0,-1},
{1,-1},
{-1,1},
{0,1},
{1,1}
};
const int SIZ=(1<<25)-1;
struct hash_table{
    vector<pair<LL,LL> > fir;
    vector<vector<int> > sec;
    vector<int> nex;
    int tp[SIZ+1];
    hash_table(){
        rb(i,0,SIZ) tp[i]=-1;
    }
    int tokey(pair<LL,LL> A){
        unsigned LL k=abs(A.first)^abs(A.second);
        k^=k>>3;
        k^=k<<13;
        k^=k>>7;
        k^=k<<17;
        return (k^abs(A.second))&SIZ;
    }
    void push_back(pair<LL,LL> A,int val){
        int x=-1;
        int t=tokey(A);
        for(int i=tp[t];i!=-1;i=nex[i]){
            if(fir[i]==A){
                x=i;
                break;
            }
        }
        if(x==-1){
            nex.PB(tp[t]);
            tp[t]=nex.size()-1;
            fir.PB(A);
            sec.PB(vector<int> (0));
            x=nex.size()-1;
        }
        sec[x].PB(val);
    }
    int query(pair<LL,LL> A){
        int t=tokey(A);
        for(int i=tp[t];i!=-1;i=nex[i]){
            if(fir[i]==A) return i;
        }
        return -1;
    }
    void clear(){
        for(auto it:fir) tp[tokey(it)]=-1;
        nex.clear();
        fir.clear();
        sec.clear();
    }
}ht;
bool check(double r){
    ht.clear();
    radius=r;
    double len=r*2;
    v.clear();
    rb(i,1,n) ht.push_back(II(llround(floor((x[i])/len)),llround(floor((y[i])/len))),i);
    for(auto &it:ht.sec){
        sort(ALL(it));
        if(it.size()>=k&&findone(it)) return 1;
    }
    rep(i,ht.sec.size()){
        long long x,y;
        x=ht.fir[i].first;
        y=ht.fir[i].second;
        vector<int> Tmp;
        ++cnt;
        rep(z,9){
            long long nx,ny;
            nx=grid[z][0]+x;
            ny=grid[z][1]+y;
            auto xx=ht.query(II(nx,ny));
            if(xx!=-1) mergesort(Tmp,ht.sec[xx]);
            if(z==0){
            	for(auto it:Tmp) vis[it]=cnt;
			}
        }
        if(Tmp.size()>=k&&findone(Tmp)) return 1;
    }
    return 0;
}
void solve(){
    cin>>n>>l>>k;
    rb(i,1,n) scanf("%lf %lf",&x[i],&y[i]);
    if(check(1)){
        double L,R;
        L=0,R=1;
        rb(i,1,40){
            if(abs(R-L)<1e-9) break;
            double M=(L+R)/2.0;
            if(check(M)){
                R=M;
            }
            else{
                L=M;
            }
        }
        printf("%.10f\n",L);
    }
    else{
        double L=1,R=2e8;
        rb(i,1,40){
            if(abs(R-L)/L<1e-9) break;
            double M=sqrt(L*R);
            if(check(M)){
                R=M;
            }
            else{
                L=M;
            }
        }
        printf("%.10f\n",L);
    }
}
int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}