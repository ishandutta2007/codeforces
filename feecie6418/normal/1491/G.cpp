#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,vst[200005];
vector<int> c[200005];
vector<pair<int,int> > ans;
void f(int x,int y){
	ans.emplace_back(x,y),swap(a[x],a[y]),a[x]=-a[x],a[y]=-a[y];
}
void Do(int A,int B){
	f(c[A][0],c[B][0]);
	while(a[-a[c[A][0]]]>0)f(c[A][0],-a[c[A][0]]);
	while(a[-a[c[B][0]]]>0)f(c[B][0],-a[c[B][0]]);
	f(c[A][0],c[B][0]);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(vst[i]||a[i]==i)continue;
		int p=i;
		c[++m].push_back(i),vst[i]=1;
		while(a[p]!=i)p=a[p],c[m].push_back(p),vst[p]=1;
	}
	for(int i=1;i+1<=m;i+=2)Do(i,i+1);
	if(m&1){
		if(c[m].size()==2){
			int pos=0;
			for(int i=1;i<=n;i++)if(i!=c[m][0]&&i!=c[m][1])pos=i;
			f(c[m][0],pos),f(c[m][1],pos),f(c[m][0],pos);
		}
		else if(c[m].size()>2){
			f(c[m][0],c[m].back()),f(c[m][0],c[m][1]);
			while(a[-a[c[m][0]]]>0)f(c[m][0],-a[c[m][0]]);
			while(a[-a[c[m].back()]]>0)f(c[m].back(),-a[c[m].back()]);
			f(c[m][0],c[m].back());
		}
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<i.first<<' '<<i.second<<'\n';
}