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

const int maxn = 500000;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;

//header

int a[maxn+5],b[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        rep(i,1,n) scanf("%d",&a[i]);
        rep(i,1,n) scanf("%d",&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1,greater<int>());
        rep(i,n+1,n*4) a[i]=100;
        rep(i,n+1,n*4) b[i]=0;
        int N=n,x=n/4,y=n-x;
        int sa=0,sb=0;
        rep(i,1,n) sa+=a[i];
        rep(i,1,x) sa-=a[i];
        rep(i,1,y) sb+=b[i];
        while(1)
        {
            if(sa>=sb) break;
            N++;
            int nx=N/4,ny=N-nx;
            sa+=a[N];
            while(x<nx) sa-=a[++x];
            while(y<ny) sb+=b[++y];
        }
        assert(N<=n*4);
        printf("%d\n",N-n);
    }
	return 0;
}