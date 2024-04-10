#include<bits/stdc++.h>
using namespace std;
#define N 1010
#define y1 ysgh1
#define y2 ysgh2
typedef long long ll;
int n,a[N],b[N],pa[N],pb[N];
vector<tuple<int,int,int,int> > ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],pa[a[i]]=i;
	for(int i=1;i<=n;++i)cin>>b[i],pb[b[i]]=i;
	for(int i=1;i<=n;++i){
		int x=pa[i],y=pb[i];
		if(x==i&&y==i)continue;
		ans.emplace_back(i,y,x,i);
		a[x]=a[i],b[y]=b[i];
		pa[a[i]]=x,pb[b[i]]=y;	
	}
	cout<<ans.size()<<'\n';
	for(auto [x1,y1,x2,y2]:ans){
		cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
	}
	return 0;
}