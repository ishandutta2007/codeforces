#include<bits/stdc++.h>
using namespace std;
const int N=210000,inf=~0u>>1;
struct line{
	int l,r,w;
	bool operator<(const line&t)const{
		return r!=t.r?r<t.r:l<t.l;
	}
}e[N];
int n,x;
vector<pair<int,int>> c[N];
int main(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&e[i].l,&e[i].r,&e[i].w);
	sort(e+1,e+n+1);
	int ans=inf;
	vector<pair<int,int>>::iterator vi;
	for(int i=1;i<=n;i++){
		int t=e[i].r-e[i].l+1;
		if(t>=x||e[i].w>=ans)continue;
		if(c[x-t].begin()==c[x-t].end())goto E;
		vi=upper_bound(c[x-t].begin(),c[x-t].end(),make_pair(e[i].l-1,inf));
		if(vi!=c[x-t].begin()){
			vi--;
			ans=min(ans,vi->second+e[i].w);
		}else if(vi->first<e[i].l)ans=min(ans,vi->second+e[i].w);
		E:
		if(c[t].begin()==c[t].end()||c[t][c[t].size()-1].second>e[i].w)c[t].push_back(make_pair(e[i].r,e[i].w));
	}
	if(ans!=inf)cout<<ans<<endl;
	else cout<<"-1"<<endl;
}