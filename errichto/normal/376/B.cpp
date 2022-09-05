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
const int inf=1e9+5,nax=103;

int n,m,t[nax];

int pro()
{
    cin>>n>>m;
    RI(_,m){
        int a,b,c;
        cin>>a>>b>>c;
        t[a]+=c;
        t[b]-=c;
    }
    int r=0;
    RE(i,nax)if(t[i]>0)r+=t[i];
    cout<<r;
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