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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int pos[200005],n;
int main(){
    cin>>n;rep(i,n) { int x; cin>>x; pos[x-1] = i;}
    int mn = INF,mx = -INF;
    int fail = 0;
    for(int i=n-1;i>=0;i--){
        mn = min(mn,pos[i]);
        mx = max(mx,pos[i]);
        if(mx-mn != n-1-i) fail = 1;
    }
    cout << (fail?"NO":"YES") << endl;
}