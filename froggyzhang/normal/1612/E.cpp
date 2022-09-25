#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N],b[N],m;
int ans[N],an;
double mx;
void Solve(int t){
	static pair<double,int> p[N];
	for(int i=1;i<=m;++i)p[i]=make_pair(0.0,i);
	for(int i=1;i<=n;++i){
		p[a[i]].first+=t<=b[i]?1:1.0*b[i]/t;
	}
	nth_element(p+1,p+t,p+m+1,greater<pair<double,int> >());
	double jb=0;
	for(int i=1;i<=t;++i){
		jb+=p[i].first;
	}
	if(jb>mx){
		mx=jb;
		an=t;
		for(int i=1;i<=t;++i){
			ans[i]=p[i].second;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		m=max(m,a[i]);
	}
	mx=-1;
	for(int t=1;t<=min(m,30);++t){
		Solve(t);	
	}
	static pair<int,int> p[N];
	for(int i=1;i<=n;++i){
		p[a[i]].first+=b[i];
	}
	sort(p+1,p+m+1,greater<pair<int,int> >());
	int now=0;
	for(int i=1;i<=30;++i)now+=p[i].first;
	int qwq=-1;
	for(int i=31;i<=m;++i){
		now+=p[i].second;
		if(1.0*now/i>mx){
			mx=1.0*now/i;
			qwq=i;
		}
	}
	if(~qwq){
		an=qwq;
		for(int i=1;i<=qwq;++i){
			ans[i]=p[i].second;
		}
	}
	cout<<an<<'\n';
	for(int i=1;i<=an;++i){
		cout<<ans[i]<<' ';
	}
	return 0;
}