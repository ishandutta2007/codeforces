#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,a[200005];
const int N=200005;
int t[10][2*N];
void build(){
	rep(j,0,10){
		for(int i=n-1;i>0;--i){
			if(t[j][i<<1]==-1 or t[j][i<<1|1]==-1) t[j][i]=max(t[j][i<<1],t[j][i<<1|1]);
			else if(a[t[j][i<<1]]<a[t[j][i<<1|1]]) t[j][i]=t[j][i<<1];
			else t[j][i]=t[j][i<<1|1];
		}
	}
}
void modify(int p,int val,int f){
	for(t[f][p+=n]=val;p>1;p>>=1){
		if(t[f][p]==-1 or t[f][p^1]==-1) t[f][p>>1]=max(t[f][p],t[f][p^1]);
		else if(a[t[f][p]]<a[t[f][p^1]]) t[f][p>>1]=t[f][p];
		else t[f][p>>1]=t[f][p^1];
	}
}
int query(int l,int r,int f){
	int res=-1;
	for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
		if(l&1){
			if(res==-1 or (t[f][l]!=-1 and a[res]>a[t[f][l]])) res=t[f][l];
			l++;
		}
		if(r&1){
			--r;
			if(res==-1 or (t[f][r]!=-1 and a[res]>a[t[f][r]])) res=t[f][r];
		}
	}
	return res;
}
void solve(){
	cin>>n>>m;
	rep(i,0,n){
		int x,y;
		cin>>x;
		a[i]=x;
		y=x;
		rep(j,0,10){
			if(y%10) t[j][i+n]=i;
			else t[j][i+n]=-1;
			y/=10;
		}
	}
	build();
	while(m--){
		int type;
		cin>>type;
		if(type==1){
			int pos,x;
			cin>>pos>>x;
			int y=x;
			a[pos-1]=x;
			rep(j,0,10){
				if(y%10) modify(pos-1,pos-1,j);
				else modify(pos-1,-1,j);
				y/=10;
			}
		}
		else{
			int l,r;
			cin>>l>>r;
			int ans=2*hell;
			rep(j,0,10){
				int pos1=query(l-1,r-1,j);
				if(pos1==-1) continue;
				modify(pos1,-1,j);
				int pos2=query(l-1,r-1,j);
				modify(pos1,pos1,j);
				if(pos2==-1) continue;
				ans=min(ans,a[pos1]+a[pos2]);
			}
			if(ans==2*hell) cout<<-1<<endl;
			else cout<<ans<<endl;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}