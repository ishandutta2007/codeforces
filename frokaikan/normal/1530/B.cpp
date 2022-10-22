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

const int maxn = 30;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;

//header

int a[maxn+5][maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n,m; scanf("%d%d",&n,&m);
        rep(i,1,n) rep(j,1,m) a[i][j]=0;
        a[1][1]=a[1][m]=a[n][1]=a[n][m]=1;
        rep(i,3,m-2) if(i&1) a[1][i]=a[n][i]=1;
        rep(i,3,n-2) if(i&1) a[i][1]=a[i][m]=1;
        rep(i,1,n) rep(j,1,m) printf("%d%s",a[i][j],j==m?"\n":"");
        puts("");
    }
	return 0;
}