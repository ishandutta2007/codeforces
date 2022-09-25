#include<bits/stdc++.h>
using namespace std;
#define N 300010
typedef long long ll;
int n,a[N],m,p[N],rk[N];
vector<int> c[N];
deque<int> V;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return a[i]>a[j];});
	for(int i=1;i<=n;++i){
		rk[p[i]]=i;
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=a[1];++i){
		V.push_back(++m);
		c[1].push_back(m);
	}
	a[n+1]=-23333;
	for(int i=2;i<=n;++i){
		int j=1,jb=-1;
		for(;V.size()>=3&&j<a[i]&&(int)V.size()+a[i]-j-1>=a[i+1];++j){
			c[i].push_back(jb=V.back());
			V.pop_back();
		}
		if(~jb)V.push_back(jb);
		for(;j<a[i];++j){
			V.push_back(++m);
			c[i].push_back(m);
		}
		c[i].push_back(V[0]);
		V.push_back(V[0]);
		V.pop_front();
	}
	cout<<m<<'\n';
	for(int i=1;i<=n;++i){
		for(int j=0;j<a[rk[i]];++j){
			cout<<c[rk[i]][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}