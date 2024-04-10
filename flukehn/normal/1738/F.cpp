#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=1011;
int d[N],c[N];
int n;
int f[N];
int fa(int x){
	return f[x]==x?x:f[x]=fa(f[x]);
}
int p[N];
int q[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>d[i];

	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=n;++i) p[i]=i;
	sort(p+1,p+n+1,[](int x,int y){
			return d[x]>d[y];
			});
	for(int i=1;i<=n;++i) q[p[i]]=i;
	for(int i=1;i<=n;++i){
		int x=p[i];
		if(fa(x) !=x)continue;
		for(int j=0;j<d[x];++j) {
			cout<<"? "<<x<<endl;
			int y;
			cin>>y;
			int z=fa(y);
			if(q[z]<i) {
				f[x]=z;
				break;
			}else{
				f[z]=x;
			}
		}
	}
	for(int i=1;i<=n;++i) c[i]=fa(i);


	cout<<"!";
	for(int i=1;i<=n;++i)cout<<" "<<c[i];
	cout<<endl;
}
int main(){
#ifdef flukehn
	//freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0);//cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}