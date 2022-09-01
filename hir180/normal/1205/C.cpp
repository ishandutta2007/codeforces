#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
 
int n;
int num[55][55];

int main(){
	cin >> n;
	num[1][1] = 1;
	repn(i,n) repn(j,n){
		if(i+j==2) continue;
		if(i+j==2*n) continue;
		if((i+j)%2 == 1) continue;
		int x = i, y = j;
		if(x > 2) x -= 2; else if(y > 2) y -= 2; else {x--; y--;}
		cout << "? " << x << " " << y << " " << i << " " << j << endl;
		int a; cin >> a; if(a == 1) num[i][j] = num[x][y]; else num[i][j] = 1-num[x][y];
        //cout << i << " " << j << " " << num[i][j] << endl;
	}
	cout << "? " << 1 << " " << 2 << " " << 3 << " " << 2 << endl;
	int a; cin >> a; num[3][2] = 1-a;
	cout << "? " << 2 << " " << 1 << " " << 3 << " " << 2 << endl;
	cin >> a; num[2][1] = num[3][2]^(1-a);
	repn(i,n) repn(j,n){
		if(i+j==3) continue;
		if(i == 3 && j == 2) continue;
		if((i+j)%2 == 0) continue;
		int x = i, y = j;
		if(x > 2) x -= 2; else if(y > 2) y -= 2; else {x--; y--;}
		cout << "? " << x << " " << y << " " << i << " " << j << endl;
		int a; cin >> a; if(a == 1) num[i][j] = num[x][y]; else num[i][j] = 1-num[x][y];
		//cout << i << " " << j << " " << num[i][j] << endl;
	}
	if(num[2][1] != num[1][2]){
		cout << "? " << 1 << " " << 1 << " " << 3 << " " << 2 << endl;
		int a; cin >> a;
		if(num[3][2] != a){
			repn(i,n) repn(j,n) if((i+j)%2 == 1) num[i][j]^=1;
		}
		{
			cout << "!" << endl;
			repn(i,n){repn(j,n)cout<<num[i][j];cout<<endl;}
			return 0;
		}
	}
	repn(i,n) repn(j,n){
		if(i+j <= 3) continue;
		if(i==1 || j==n) continue;
		if(num[i][j] != num[i-1][j+1]){
			if(i == 2){
				cout << "? " << i-1 << " " << j-1 << " " << i << " " << j+1 << endl;
				int a; cin >> a;
				if( (num[i-1][j-1]^num[i][j+1]) != (1-a) ){
					repn(i,n) repn(j,n) if((i+j)%2 == 1) num[i][j]^=1;
				}
				cout << "!" << endl;
				repn(i,n){repn(j,n)cout<<num[i][j];cout<<endl;}
				return 0;
			}
			else{
				cout << "? " << i-2 << " " << j << " " << i << " " << j+1 << endl;
				int a; cin >> a;
				if( (num[i-2][j]^num[i][j+1]) != (1-a) ){
					repn(i,n) repn(j,n) if((i+j)%2 == 1) num[i][j]^=1;
				}
				cout << "!" << endl;
				repn(i,n){repn(j,n)cout<<num[i][j];cout<<endl;}
				return 0;
			}
		}
	}
	int val[505]={};
	vector<P>p[205];
	repn(i,n) repn(j,n){
		val[i+j] = num[i][j];
		p[i+j].pb(P(i,j));
	}
	for(int i=2;i<=2*n;i++) for(int j=i+1;j<=2*n;j++){
		if(j%2 == i%2 || j-i == 1) continue;
		bool used[2]={};
		for(int x=i;x<=j;x++){
			if(x >= i+j-x) break;
			used[val[x]^val[i+j-x]] = 1;
		}
		if(used[0] && used[1]) continue;
		P pp,pp2;
		rep(x,p[i].size()) rep(y,p[j].size()) if(p[i][x].fi <= p[j][y].fi && p[i][x].sc <= p[j][y].sc){
		    pp = p[i][x];
		    pp2 = p[j][y];
		}
		cout << "? " << pp.fi << " " << pp.sc << " " << pp2.fi << " " << pp2.sc << endl;
		int a; cin >> a;
		if( (val[i]^val[j]) != (1-a) ){
			repn(i,n) repn(j,n) if((i+j)%2 == 1) num[i][j]^=1;
		}
		cout << "!" << endl;
		repn(i,n){repn(j,n)cout<<num[i][j];cout<<endl;}
		return 0;
	}
}