#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<climits>
#include<map>
#include<set>
#include<vector>
#include<cmath>
#include<list>
#include<queue>
#include<string>
using namespace std;
#define x first
#define y second
#define MP make_pair
#define pb push_back
#define mid ((l+r)>>1)
#define ls k<<1,l,mid
#define rs k<<1|1,mid+1,r
#define LS k<<1
#define RS k<<1|1
#define ll long long
#define lb long double
#define db double
#define PII pair<int,int>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forn(i,a,b) for(int i=a;i>=b;i--)
inline int read(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';){if(ch=='-')f=-1;ch=getchar();}
    for(;ch>='0'&&ch<='9';){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define N 1000010
int n,k;
int v[N],c[N];
int r[N];
int main(){
	n=read(),k=read();For(i,1,n)v[i]=read();
	For(i,1,n)c[i]=read();
	Forn(i,n,1)r[i]=min(max(100*v[i],r[i+1]),c[i]);
	sort(r+1,r+n+1);
	db ans=0.0,tmp=1.0;
	tmp*=1.0*k;tmp/=1.0*n;
	For(i,1,k){
		ans+=tmp*r[i];
		if(n-i==0)break;
		tmp*=1.0*(n-k-i+1);tmp/=1.0*(n-i);
	}printf("%.12lf\n",ans);
}