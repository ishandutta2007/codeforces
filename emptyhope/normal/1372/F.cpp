#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 200005
int n,a[maxn];
inline pii ask(int l,int r){
	cout<<"? "<<l<<" "<<r<<endl;
	int x,y; cin>>x>>y; return mkp(x,y);
}
void solve(int l,int r){
	if(l>r)return;
	pii ans=ask(l,r);
	int tl=r-ans.se+1,tr=l+ans.se-1;
	if(tl<=tr){
		For(i,tl,tr) a[i]=ans.fi;
		solve(l,tl-1),solve(tr+1,r);
	}else{
		int mid=l+r>>1;
		solve(l,mid),solve(mid+1,r);
	}
}
signed main()
{
	cin>>n;
	solve(1,n);
	cout<<"! ";
	For(i,1,n)cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}