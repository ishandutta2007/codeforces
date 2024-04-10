#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define mod (1<<30)
int a,b,c;
bool u[2005];
vector<int>prime;
map<P1,ll>M[505];
ll rec(int A,int B,int C,int p){
    if(A>B) swap(A,B); if(A>C) swap(A,C); if(B>C) swap(B,C);
    if(p>=prime.size()) return 1ll;
    if(M[p].find(mp(A,mp(B,C)))!=M[p].end()) return M[p][mp(A,mp(B,C))];
    
    int q = prime[p];
    ll ans=0;
    for(int i=0,x=A;x>0;i++,x/=q){
        for(int j=0,y=B;y>0;j++,y/=q){
            for(int k=0,z=C;z>0;k++,z/=q){
                ans+=1LL*(i+j+k+1)*rec(x,y,z,p+1);
            }
        }
    }
    return M[p][mp(A,mp(B,C))]=ans%mod;
}
int main(){
    cin>>a>>b>>c;
    for(int i=2;i<=2000;i++){
        if(u[i])continue; prime.push_back(i);
        for(int j=2;i*j<=2000;j++) u[i*j] = 1;
    }reverse(prime.begin(),prime.end());
    cout<<rec(a,b,c,0)%mod<<endl;
}