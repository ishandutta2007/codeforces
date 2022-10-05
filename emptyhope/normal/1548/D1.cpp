#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
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
 
#define maxn 200005
#define inf 0x3f3f3f3f

int n,x[maxn],y[maxn];
int cnt[2][2];

bool chk(int x,int y,int xx,int yy){
	if(x==xx&&y==yy)return 0;
	return 1;
}

inline int C(int n,int m){
	int ans=1;
	For(i,1,m)ans*=(n-i+1);
	return ans;
} 

signed main()
{
	n=read();
	For(i,1,n){
		x[i]=read()/2,y[i]=read()/2;
		cnt[x[i]&1][y[i]&1]++;
	}
	int res=0;
	For(i,0,1)For(j,0,1)For(i2,0,1)For(j2,0,1)For(i3,0,1)For(j3,0,1){
		if(chk(i,j,i2,j2)^chk(i2,j2,i3,j3)^chk(i3,j3,i,j)) continue;
		map<pii,int>mp;
		mp[mkp(i,j)]++,mp[mkp(i2,j2)]++,mp[mkp(i3,j3)]++;
		int ans=1;
		for(auto t:mp){
			ans*=C(cnt[t.fi.fi][t.fi.se],t.se);
		}
		res+=ans;
	}cout<<res/6;
	return 0;
}