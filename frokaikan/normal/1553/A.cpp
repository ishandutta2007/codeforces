#include<bits/stdc++.h>
#define rep(i,a,n) for(auto i=(a);i<=(n);i++)
#define per(i,a,n) for(auto i=(n);i>=(a);i--)
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
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int maxn = 200000;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;

//header

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        printf("%d\n",(n+1)/10);
    }
    return 0;
}