#include<bits/stdc++.h>
using namespace std;
const int N=400000;
typedef pair<int,int> pr;
typedef unsigned long long ull;
typedef pair<ull,int> p2;
mt19937_64 rng(23333);
int n,m,px[N+5],py[N+5],mch[N+5],va[N+5],vb[N+5],vst[N+5];
ull fa[N+5],fb[N+5],ord[N+5],ev[N+5];
vector<int> a[N+5];
vector<int> b[N+5];
vector<pr> ea[N+5],eb[N+5];
void dfs(int x,int y){
	//cout<<x<<' '<<y<<'\n';
	mch[x]=y,va[x]=vb[y]=1;
	if(ea[x].size()!=eb[y].size())puts("-1"),exit(0);
	for(int i=0;i<ea[x].size();i++){
		int p=ea[x][i].second;
		int q=eb[y][i].second;
		//cout<<"to "<<p<<' '<<q<<'\n'; 
		if(va[p]!=vb[q]||ea[x][i].first!=eb[y][i].first)puts("-1"),exit(0);
		if(va[p]){
			if(mch[p]!=q)puts("-1"),exit(0);
			continue;
		}
		dfs(p,q);
	}
}
vector<pr> ans;
int main(){
	bool REV=0;
	scanf("%d%d",&n,&m);
	if(n>m)swap(n,m),REV=1;
	for(int i=0;i<n;i++)a[i].resize(m);
	for(int i=0;i<n;i++)b[i].resize(m);
	if(!REV){
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&b[i][j]);
	}
	else {
		for(int i=0;i<m;i++)for(int j=0;j<n;j++)scanf("%d",&a[j][i]);
		for(int i=0;i<m;i++)for(int j=0;j<n;j++)scanf("%d",&b[j][i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]){
				ea[i].push_back(pr(a[i][j],j+n));
				ea[j+n].push_back(pr(a[i][j],i));
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(b[i][j]){
				eb[i].push_back(pr(b[i][j],j+n));
				eb[j+n].push_back(pr(b[i][j],i));
			}
		}
	}
	for(int i=0;i<n+m;i++){
		fa[i]=fb[i]=1,ord[i]=rng();
		sort(ea[i].begin(),ea[i].end());
		sort(eb[i].begin(),eb[i].end());
	}
	for(int i=1;i<=200000;i++)ev[i]=rng();
	for(int k=1;k<=50;k++){
		for(int i=0;i<n+m;i++){
			for(int j=0;j<ea[i].size();j++){
				auto e=ea[i][j];
				fa[i]^=fa[e.second]+ev[e.first]+ord[j];
			}
			for(int j=0;j<eb[i].size();j++){
				auto e=eb[i][j];
				fb[i]^=fb[e.second]+ev[e.first]+ord[j];
			}
		}
	}
	vector<p2> v1,v2;
	for(int i=0;i<n+m;i++)v1.push_back(pr(fa[i],i));//,printf("fa:%d %llu\n",i,fa[i]);
	for(int i=0;i<n+m;i++)v2.push_back(pr(fb[i],i));//,printf("fb:%d %llu\n",i,fb[i]);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(int i=0;i<n+m;i++)if(v1[i].first!=v2[i].first)puts("-1"),exit(0);
	for(int i=0,j=0;i<n+m;i++,j++){
		while(i<n+m&&va[v1[i].second])i++;
		while(j<n+m&&vb[v2[j].second])j++;
		if((i==n+m)!=(j==n+m))puts("-1"),exit(0);
		if(i==n+m||j==n+m)break;
		//cerr<<"V:"<<v1[i].second<<' '<<v2[j].second<<'\n';
		if(v1[i].first!=v2[j].first)puts("-1"),exit(0);
		dfs(v1[i].second,v2[j].second);
	}
	//for(int i=0;i<n+m;i++)cout<<"MCH:"<<i<<' '<<mch[i]<<'\n';
	//exit(0);
	for(int i=0;i<n+m;i++){
		if(vst[i])continue;
		vector<int> vec;
		vst[i]=1,vec.push_back(i);
		int j=i;
		while(mch[j]!=i)j=mch[j],vec.push_back(j),vst[j]=1;
		for(int k=(int)vec.size()-2;k>=0;k--)ans.push_back(pr(vec[k],vec[k+1]));
	}
	cout<<ans.size()<<'\n';
	for(pr i:ans){
		int op=(i.first>=n),x=i.first-n*(i.first>=n),y=i.second-n*(i.second>=n);
		op^=REV,cout<<op+1<<' '<<x+1<<' '<<y+1<<'\n';
	}
}