#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<climits>
#include<map>
#include<set>
#include<vector>
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
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';){if(ch=='-')f=-1;ch=getchar();}
    for(;ch>='0'&&ch<='9';){x=x*10ll+ch-'0';ch=getchar();}
    return x*f;
}
ll x1,y1,x2,y2;
int main(){
	x1=read(),y1=read(),x2=read(),y2=read();
	if(x1>x2)swap(x1,x2);if(y1>y2)swap(y1,y2);
	printf("%I64d\n",1ll*(x2-x1+1)*(y2-y1+2)/2-(x2-x1+1)/2);
}