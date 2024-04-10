/**
 *    author:  gary
 *    created: 16.11.2021 19:46:04
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
namespace random_rotate{
    const double S=sin(2.14514),C=cos(2.14514);
    void rot(pair<double,double> & tmp) {
        tmp=II(tmp.FIR*C-S*tmp.SEC,tmp.FIR*S+tmp.SEC*C);
    }
}
const int MAXN=3003;
const double eps=1e-9;
const double pie=2.0*acos(0);
int n;
double R;
pair<double,double> a[MAXN];
int cntt[MAXN][MAXN];
int temp[MAXN];
int answer=0;
double dist(pair<double,double> A,pair<double,double> B){
    return sqrt((A.FIR-B.FIR)*(A.FIR-B.FIR)+(A.SEC-B.SEC)*(A.SEC-B.SEC));
}
pair<double,int> v[200000];
int siz;
int main(){
    cin>>n>>R;
    rb(i,1,n) scanf("%lf%lf",&a[i].FIR,&a[i].SEC),random_rotate::rot(a[i]);
    rb(j,1,n) rb(i,1,n) if(dist(a[i],a[j])<=R) temp[i]++;
    rb(i,1,n) rb(j,i+1,n) cntt[i][j]+=temp[i];
    rb(i,1,n){
        siz=0;
        rb(j,i+1,n){
            double tmp=atan2(a[j].SEC-a[i].SEC,a[j].FIR-a[i].FIR);
            v[++siz]=II(tmp,j*10);// + query
        }
        rb(j,1,i-1){
            double tmp=atan2(a[i].SEC-a[j].SEC,a[i].FIR-a[j].FIR);
            v[++siz]=II(tmp,j*10+1);// - query
        }
        rb(j,1,n){
            if(dist(a[i],a[j])<=R) continue;
            // j in i
            double ag1=atan2(a[j].SEC-a[i].SEC,a[j].FIR-a[i].FIR);
            double len=dist(a[i],a[j]);
            double delta=asin(R/len);
            double l,r;
            l=ag1-delta,r=ag1+delta;
            if(l<-pie) l+=2*pie;
            if(r>pie) r-=2*pie;
            if(l>r) swap(l,r);
            if(ag1<=r+eps&&ag1>=l-eps){
                v[++siz]=(II(l-eps,2));// + event
                v[++siz]=(II(r+eps,3));// - event
            }
            else{
                v[++siz]=(II(-pie-eps,2));
                v[++siz]=(II(r-eps,2));
                v[++siz]=(II(l+eps,3));
                v[++siz]=(II(pie+eps,3));
            }
        }
        sort(v+1,v+1+siz);
        int cnt=0;
        rb(j,1,siz){
            auto it=v[j];
            if(it.SEC>=10){
                if(it.SEC&1) cntt[it.SEC/10][i]-=cnt;
                else cntt[i][it.SEC/10]+=cnt;
                continue;
            }
            if(it.SEC==2) cnt++;
            if(it.SEC==3) cnt--;
        }
    }
    rb(i,1,n) rb(j,i+1,n){
        answer+=cntt[i][j]==n;
    }
    cout<<answer<<endl;
    return 0;
}