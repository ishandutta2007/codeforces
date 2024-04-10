#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define check_max(a,b) a=max(a,b)
#define check_min(a,b) a=min(a,b)
#define LL long long
#define II(a,b) make_pair(a,b)
using namespace std;
const double pie=2*asin(1);
typedef pair<int,int> mp;
const int MAXN=1e5+20;
int n,m,x[MAXN],y[MAXN],fa[MAXN*3][17],mnr[MAXN*3];
int jump(int i,int j){
    rep(k,17) if((j>>k)&1) i=fa[i][k];
    return i;
}
bool chk(double r){
    vector<pair<double,double> > seg;
    rb(i,1,n){
        double L,R,M,D;
        D=sqrt((double)(x[i])*x[i]+(double)(y[i])*y[i]);
        M=atan2(y[i],x[i]);
        L=M-acos(r/D);
        R=M+acos(r/D);
        while(L<0) L+=2*pie,R+=2*pie;
        seg.push_back(II(L,R));
        seg.push_back(II(L+2*pie,R+2*pie));
    }
    sort(seg.begin(),seg.end());
    multiset<double> R,L;
    fa[seg.size()][0]=seg.size();
    int p=seg.size()-1;
    rl(i,seg.size()-1,0){
        L.insert(seg[i].first);
        R.insert(seg[i].second);
        while(*R.begin()<*prev(L.end())){
            R.erase(R.find(seg[p].second));
            L.erase(L.find(seg[p].first));
            p--;
        }
        fa[i][0]=p+1;
    }
    rb(j,1,16) rb(i,0,seg.size()) fa[i][j]=fa[fa[i][j-1]][j-1];
    rb(i,0,seg.size()-n) if(jump(i,m)>=i+n){
        return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rb(i,1,n) cin>>x[i]>>y[i];
    double l=0,r=1e18;
    rb(i,1,n){
        double X=x[i],Y=y[i];
        check_min(r,sqrt(X*X+Y*Y));
    }
    rb(i,1,40){
        double mid=(l>=1? sqrt(l*r):(l+r)/2);
        if(max(mid-l,r-mid)/max(1.0,l)<1e-6){l=mid; break;}
        if(chk(mid)) l=mid;
        else r=mid;
    }
    cout<<fixed<<setprecision(10)<<l<<endl;
    return 0;
}