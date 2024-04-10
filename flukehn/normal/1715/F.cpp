#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
int n,m;
using ld=double;
using pa=pair<ld,ld>;
ld qry(vector<pa> pg){
	int k=pg.size();
	cout<<"? "<<k<<"\n";
	for(auto [x,y]:pg){
		cout<<x<<" "<<y<<"\n";
	}
	cout.flush();
	ld S;
	cin>>S;
	return S;
}
int main(){
#ifdef flukehn
	//freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0);//cin.tie(0);
	cout<<fixed<<setprecision(10);
	cin>>n>>m;
	vector<pa> q1,q2;
	ld s1,s2;
	q1.emplace_back(0,0);
	for(int i=1;i<=n;++i) q1.emplace_back(i,m), q1.emplace_back(i,0);
	s1=qry(q1);
	q2.emplace_back(0,0);
	for(int i=1;i<=m;++i) q2.emplace_back(n,i), q2.emplace_back(0,i);
	s2=qry(q2);
	ld y=m-0.5-m*s1;
	ld x=n-0.5-n*s2;
	cout<<"! "<<x<<" "<<y<<"\n";
}