#include<iostream>
#include<set>
#include<queue>
using namespace std;
int a[200002];
int l[200001],r[200001],sz[200001];
int rl[200001],rr[200001];
priority_queue<pair<int,pair<int,int> > >pq;
int findl(int x){
	if(l[x]!=x) l[x]=findl(l[x]);
	return l[x];
}
int findr(int x){
	if(r[x]!=x) r[x]=findr(r[x]);
	return r[x];
}
void join(int x,int y){
	if(findl(x)==findl(y)) return;
	sz[findl(x)]+=sz[findl(y)];
	l[findl(y)]=findl(x);
	r[findr(x)]=findr(y);
	
}
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n;
	int ll=1;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		l[i]=r[i]=i;
		sz[i]=1;
	}
	for(int i=2; i<=n ;i++){
		if(a[i]!=a[ll]){
			pq.push(make_pair(i-ll,make_pair(-ll,i-1)));
			ll=i;
		}
		else join(ll,i);
		rl[i]=i-1;
		rr[i-1]=i;
	}
	rl[1]=rr[n]=-1;
	pq.push(make_pair(n+1-ll,make_pair(-ll,n)));
	int ans=0;
	while(!pq.empty()){
		int cur=-pq.top().second.first,s=pq.top().first,t=pq.top().second.second;
		pq.pop();
		if(findl(cur)!=cur || findr(cur)!=t) continue;
		ans++;
		if(rr[t]!=-1) rl[rr[t]]=rl[cur];
		if(rl[cur]!=-1) rr[rl[cur]]=rr[t];
		if(rl[cur]!=-1 && rr[t]!=-1 && a[rl[cur]]==a[rr[t]]){
			join(rl[cur],rr[t]);
			int nl=findl(rl[cur]),nr=findr(rr[t]);
			pq.push(make_pair(sz[nl],make_pair(-nl,nr)));
		}
	}
	cout << ans << endl;
}