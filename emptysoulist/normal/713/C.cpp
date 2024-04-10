#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
#define int long long
const int N=5e5+1;
const int inf=1e9;
int n,a[N],d[N],z[N];
void solve(int l,int r,int L,int R){
	if(l>r)return;
	if(L==R){rep(i,l,r)d[i]=L;return;}
	int mid=(L+R)>>1,C=0,p=r+1,D=0;
	rep(i,l,r)z[i]=abs(mid+1-a[i])-abs(mid-a[i]);
	for(int i=r;i>=l;--i){
		D+=z[i];
		if(D<C)C=D,p=i;
	}
	solve(l,p-1,L,mid),solve(p,r,mid+1,R); 
}
signed main() {
	n=gi();rep(i,1,n)a[i]=gi()-i;
	solve(1,n,-inf,inf);
	int ans=0;
	rep(i,1,n)ans+=abs(a[i]-d[i]);
	cout<<ans<<endl;
	return 0 ;
}