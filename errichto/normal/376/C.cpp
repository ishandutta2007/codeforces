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
const int inf=1e9+5,nax=1e6+5;

//

int pro()
{
    vi res;
    char sl[nax];
    cin>>sl;
    int n=strlen(sl);
    int t[10];
    RE(i,10)t[i]=0;
    t[1]=t[6]=t[8]=t[9]=-1;
    int s=0,p=1;
    RE(i,n){
        int a=sl[i]-'0';
        t[a]++;
        if(t[a]){
            res.pb(a);
            s+=a*p;
            p=(p*10)%7;
        }
    }
    RE(i,10)t[i]=0;
    t[1]=t[6]=t[8]=t[9]=-1;
    RE(k,10000){
        RE(i,10)t[i]=0;
        t[1]=t[6]=t[8]=t[9]=-1;
        int a=k,ile=0,li=s,pot=p;
        RE(_,4){
            int cy=a%10;
            li+=pot*cy;
            pot*=10;
            res.pb(cy);
            if(t[cy]){
                ile++;
                t[cy]=0;
            }
            a/=10;
        }
        if(ile==4 && li%7==0){
            reverse(all(res));
            RE(i,res.size())cout<<res[i];
            return 0;
        }
        RE(_,4)res.pop_back();
    }
    
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