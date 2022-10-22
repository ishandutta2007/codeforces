#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100000;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;

//header

int a[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        rep(i,1,n) scanf("%d",&a[i]);
        vi odd,even;
        rep(i,1,n) if(i&1) odd.pb(a[i]); else even.pb(a[i]);
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        sort(a+1,a+n+1);
        int ans=1;
        rep(i,1,(int)odd.size()) ans &= odd[i-1]==a[i*2-1];
        rep(i,1,(int)even.size()) ans &= even[i-1]==a[i*2];
        puts(ans?"YES":"NO");
    }
    return 0;
}