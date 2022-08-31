#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    int N;
    cin>>N;
    vector<string>S(N);
    rep(i,N)cin>>S[i];

    int ma=0;
    rep(i,7){
        int s=0;
        rep(j,N)s+=S[j][i]=='1';
        chmax(ma,s);
    }
    cout<<ma<<endl;
    return 0;
}