#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define read2(a,b) read(a),read(b)
using namespace std;
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9') {x=x*10+c-'0';c=getchar();}
}
const int N=1010;
int n,deg[N];
int main()
{
    read(n);
    forinc(i,1,n-1)
    {
        int u,v;
        read2(u,v);
        deg[u]++;deg[v]++;
    }
    int res=0;
    forinc(i,1,n) if(deg[i]==1) res++;
    cout<<res;
}