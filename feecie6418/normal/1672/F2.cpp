#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,a[200005],b[200005],p[200005],vst[200005],m,ind[200005];
vector<int> pos[200005],lp[200005],g[200005];
void Add(int x,int y){
	ind[y]++,g[x].push_back(y);
}
void Clear(){
	for(int i=1;i<=n;i++){
		a[i]=b[i]=p[i]=vst[i]=ind[i]=0;
		pos[i].clear();
		lp[i].clear();
		g[i].clear();
	}
	n=m=0;
}
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]].push_back(i);
	int M=0,MP=0;
	for(int i=1;i<=n;i++){
		if(pos[i].size()>MP)M=i,MP=pos[i].size();
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		p[pos[b[i]].back()]=i;
		pos[b[i]].pop_back();
	}
	for(int i=1;i<=n;i++){
		if(vst[i])continue;
		int j=i;
		vector<int> o;
		vst[i]=1,o.push_back(i);
		while(!vst[p[j]])j=p[j],o.push_back(j),vst[j]=1;
		bool ok=0;
		for(int j:o)if(a[j]==M)ok=1;
		if(!ok)return puts("WA"),Clear();
		int S=0;
		for(int k=0;k<o.size();k++)if(a[o[k]]==M)S=k;
		for(int k=0;k<o.size();){
			int l=k;
			while(l+1<o.size()&&a[o[(l+1+S)%o.size()]]!=M)l++;
			m++;
			for(int p=k;p<=l;p++)lp[m].push_back(a[o[(p+S)%o.size()]]);
			k=l+1;
		}
	}
	assert(m==MP);
	for(int i=1;i<=m;i++){
		assert(lp[i][0]==M);
		for(int j=1;j<lp[i].size();j++){
			Add(lp[i][j-1],lp[i][j]);
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++)if(!ind[i])q.push(i);
	int sum=0;
	while(!q.empty()){
		int x=q.front();
		q.pop(),++sum;
		for(int y:g[x]){
			if(!(--ind[y]))q.push(y);
		}
	}
	if(sum!=n)puts("WA");
	else puts("AC");
	Clear();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}