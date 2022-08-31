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

const int mod1=1000000007,mod2=1000000009;
const int p1=8931919,p2=1333119;

int N;
string S[1111111];


int po1[1111111],po2[1111111];

void solve(){
    cin>>N;
    rep(i,N)cin>>S[i];

    vector<vector<int>>H1(N);
    vector<vector<int>>H2(N);

    rep(i,N){
        H1[i].resize(S[i].size()+1);
        H2[i].resize(S[i].size()+1);
        for(int j=0;j<S[i].size();j++){
            H1[i][j+1]=(H1[i][j]*p1+S[i][j])%mod1;
            H2[i][j+1]=(H2[i][j]*p2+S[i][j])%mod2;
        }
    }

    vpint ord;
    rep(i,N)ord.pb({S[i].size(),i});
    sort(all(ord));reverse(all(ord));

    set<pint>prohibited;
    int ans=0;

    for(int i=ord[0].fi;i>0;i--){
        set<pint>prohibited_;
        for(int j=0;j<ord.size();j++){
            if(ord[j].fi<i)break;
            if(prohibited.find(pint(H1[ord[j].se][i],H2[ord[j].se][i]))!=prohibited.end())continue;
            ans++;
            prohibited.insert(pint(H1[ord[j].se][i],H2[ord[j].se][i]));
            prohibited_.insert(pint((H1[ord[j].se][i]-H1[ord[j].se][1]*po1[i-1]%mod1+mod1)%mod1,(H2[ord[j].se][i]-H2[ord[j].se][1]*po2[i-1]%mod2+mod2)%mod2));
        }
        prohibited=prohibited_;
    }
    cout<<ans<<endl;
}

signed main(){
    po1[0]=1;
    for(int i=1;i<1111111;i++)po1[i]=po1[i-1]*p1%mod1;


    po2[0]=1;
    for(int i=1;i<1111111;i++)po2[i]=po2[i-1]*p2%mod2;

    cin.tie(0);ios_base::sync_with_stdio(0);

    int T;cin>>T;while(T--)solve();
    return 0;
}