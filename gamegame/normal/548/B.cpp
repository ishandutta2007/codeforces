#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=1e6+1;
int q;
int n,m;
int a[501][501];

int b[501];
multiset<int>s;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m >> q;
	for(int i=1; i<=n ;i++){
		int x=0,y=0;
		for(int j=1; j<=m ;j++){
			cin >> a[i][j];
			if(a[i][j]==0) y=0;
			else y++;
			x=max(x,y);
		}
		b[i]=x;
		s.insert(b[i]);
	}
//	cin >> q;
	for(int i=1; i<=q ;i++){
		int x,y;cin >> x >> y;
		s.erase(s.find(b[x]));
		a[x][y]^=1;
		int xx=0,yy=0;
		for(int j=1; j<=m ;j++){
			if(a[x][j]==0) yy=0;
			else yy++;
			xx=max(xx,yy);
		}
		b[x]=xx;
		s.insert(b[x]);
		auto it=s.end();
		--it;
		cout << (*it) << '\n';
	}
}