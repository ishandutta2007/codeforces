#include<bits/stdc++.h>
using namespace std;
const int N=300000,V=5000000;
typedef pair<int,int> pr; 
int n,q,p[N+5],a[N+5],L,R,b[N+5],c[N+5][2],bad,mx[N+5],top,st[N+5];
vector<pr> ranges;
void dfs(int x,int lst){
	if(a[x]&&a[x]>lst)bad=1;
	if(c[x][0])dfs(c[x][0],(a[x]?a[x]:lst));
	if(c[x][1])dfs(c[x][1],(a[x]?a[x]:lst));
	mx[x]=max({a[x],mx[c[x][0]],mx[c[x][1]]});
	//cout<<x<<' '<<a[x]<<' '<<lst<<'\n';
	if(!a[x])ranges.push_back({mx[x],lst});
}
void Clear(){
	for(int i=0;i<=n;i++){
		p[i]=a[i]=b[i]=c[i][0]=c[i][1]=mx[i]=st[i]=0;
	}
	ranges.clear();
}
void Solve(){
	scanf("%d%d",&n,&q),bad=top=L=R=0;
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	int K=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),K+=!a[i];
	for(int i=1;i<K;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		while(top&&p[st[top]]<p[i])c[i][0]=st[top],top--;
		c[st[top]][1]=i,st[++top]=i;
	}
	dfs(st[1],V);
	if(bad){
		while(q--)scanf("%*d"),puts("No");
		return Clear();
	}
	sort(ranges.begin(),ranges.end(),greater<pr>());
	set<int> s;
	for(int i=1;i<K;i++)s.insert(b[i]);
	//
	for(pr i:ranges){
		int l=i.first,r=i.second;
		auto it=s.upper_bound(r);
		if(it==s.begin()||(*--it)<l){
			//cout<<"LR:"<<l<<' '<<r<<'\n';
			if(L){
				bad=1;
				break;
			}
			L=l;
		}
		else s.erase(it);
	}
	//cout<<"L:"<<L<<'\n';
	s.clear();
	sort(ranges.begin(),ranges.end(),[](pr x,pr y){return x.second<y.second;});
	for(int i=1;i<K;i++)s.insert(b[i]);
	// 
	for(pr i:ranges){
		int l=i.first,r=i.second;
		auto it=s.lower_bound(l);
		if(it==s.end()||(*it)>r){
			if(R){
				bad=1;
				break;
			}
			R=r;
		}
		else s.erase(it);
	}
	if(bad){
		while(q--)scanf("%*d"),puts("No");
		return Clear();
	}
	while(q--){
		int x;
		scanf("%d",&x);
		if(x>=L&&x<=R)puts("Yes");
		else puts("No"); 
	}
	Clear();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}