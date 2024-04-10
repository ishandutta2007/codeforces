/*
{By GWj
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
#define int LL
/*}
*/
int a[3];
signed main(){
	rep(i,3)
		R(a[i]);
	cout<<"First\n";ff;
	int maxx=-INF,minn=INF;
	rep(i,3)
	{
		check_max(maxx,a[i]);
		check_min(minn,a[i]); 
	}
	cout<<maxx-minn<<endl;ff;
	int k;
	R(k);
	a[k-1]+=maxx-minn;
	if(a[k-1]==maxx) return 0;
	int b,m,s;
	vector<int> v;
	rep(i,3)
		v.PB(a[i]);
	sort(ALL(v));
	b=v[2];
	m=v[1];
	s=v[0];
	int y,x;
	y=m-s;
	x=b-m;
	cout<<y+2*x<<endl;ff;
	R(k);
	if(a[k-1]==m){
		cout<<y+x<<endl;ff;
	}
	else{
		cout<<x<<endl;ff;
	}
	return 0;
}