#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

int bi(int n,int k){
    int ret=1;
    for(int i=0;i<k;i++){
        ret*=n-i;
    }
    for(int i=0;i<k;i++)ret/=i+1;
    return ret;
}

void solve(){
    int n;cin>>n;
    vint cnt(30);
    int R=2;
    while(true){
        cnt[n%R]++;
        n/=R;
        if(n==0)break;
        R++;
    }

    int cand=0;
    int ans=1;

    for(int i=R;i>=2;i--){
        cand++;
        ans*=bi(cand,cnt[i-1]);
        cand-=cnt[i-1];
    }

    int tmp=1;
    cand=0;
    for(int i=R;i>=2;i--){
        if(i!=R)cand++;
        tmp*=bi(cand,cnt[i-1]);
        cand-=cnt[i-1];
    }
    ans-=tmp;

    cout<<ans-1<<endl;
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--)solve();
    return 0;
}