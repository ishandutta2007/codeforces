/**
 *    author:  gary
 *    created: 12.11.2021 09:30:14
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
#define make_tuple(a,b,c) II(II(a,b),c)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=5000+5;
const int MAXK=1e9;
/*
%k=(sum-v)%k

k
*/
int n,k,v,a[MAXN];
int sum;
bool dp[MAXN][MAXN];
void solve(){
    sum=0;
    cin>>n>>k>>v;
    rb(i,1,n) cin>>a[i],sum+=a[i];
    if(sum<v){
        cout<<"NO"<<endl;
        return;
    }
    rb(i,0,n) rb(j,0,k-1) dp[i][j]=0;
    dp[0][0]=1;
    rb(i,0,n-1) rep(j,k) if(dp[i][j]){
        dp[i+1][(j+a[i+1])%k]=1;
        dp[i+1][j]=1;
    }
    int ano=(sum-v)%k;
    if(dp[n][ano]){
        cout<<"YES"<<endl;
        int i,j;
        i=n,j=ano;
        vector<int> tmp;
        vector<int> have;
        while(i){
            if(dp[i-1][j]){
                have.PB(i);
                i--;
            }
            else{
                tmp.PB(i);
                (j+=k-(a[i]%k))%=k;
                i--;
            }
        }
        vector<pair<mp,int> > oper;
        if(have.empty()){
            rb(i,2,n){
                oper.PB(make_tuple(MAXK,i,1));
            }
            oper.PB(make_tuple(v/k,1,2));
        }
        else
        if(tmp.empty()){
            rb(i,2,n){
                oper.PB(make_tuple(MAXK,i,1));
            }
            oper.PB(make_tuple((sum-v)/k,1,2));
        }
        else{
            int sum1,sum2;
            sum1=sum2=0;
            rep(i,tmp.size()) sum1+=a[tmp[i]];
            rep(j,have.size()) sum2+=a[have[j]];
            rep(i,tmp.size()) if(i) oper.PB(make_tuple(MAXK,tmp[i],tmp[0]));
            rep(i,have.size()) if(i) oper.PB(make_tuple(MAXK,have[i],have[0]));
            if(sum2>v){
                oper.PB(make_tuple((sum2-v)/k,have[0],tmp[0]));
            }
            else{
                oper.PB(make_tuple((v-sum2)/k,tmp[0],have[0]));
            }
        }
        rep(i,oper.size()){
            if((oper[i].FIR.FIR)==0){
                swap(oper.back(),oper[i]);
                oper.POB();
                i--;
            }
        }
        rep(i,oper.size()) cout<<oper[i].FIR.FIR<<" "<<oper[i].FIR.SEC<<" "<<oper[i].SEC<<endl;
    }
    else{
        cout<<"NO"<<endl;
        return ;
    }
}
int main(){
    int t;
    t=1;
    while(t--) solve(); 
    return 0;
}