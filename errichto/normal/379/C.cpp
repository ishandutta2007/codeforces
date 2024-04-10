#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pld pair<ld,ld>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define FORE(i,w) for(__typeof(w.begin())i=w.begin();i!=w.end();++i)
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define all(w) w.begin(),w.end()
#define deb(x) cerr<<#x<<" = "<<x<<"\n"
#define dee(w) {cerr<<#w<<" = ";FORE(i,w)cerr<<*i<<", ";cerr<<"\n";}
const int inf=1e9+5;
const int nax=1000123;

pii t[nax];
int res[nax];

int pro()
{
    int n;
    cin>>n;
    RE(i,n){
        cin>>t[i].x;
        t[i].y=i;
    }
    sort(t,t+n);
    int akt=0;
    RE(i,n){
        res[t[i].y]=max(akt+1,t[i].x);
        akt=max(akt+1,t[i].x);
    }
    RE(i,n)cout<<res[i]<<" ";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int z=1;
    //cin>>z;
    RI(_,z)pro();
    return 0;
}