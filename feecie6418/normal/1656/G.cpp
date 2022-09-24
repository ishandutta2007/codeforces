#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,a[200005],fa[200005],p[200005],pos[200005];
int rep[200005],q[200005],tp[200005];
vector<int> u[200005];
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void Merge(int x,int y){
	x=gf(x),y=gf(y);
	if(x!=y)fa[x]=y;
}
void Clear(){
	for(int i=1;i<=n;i++)rep[i]=0,u[i].clear();
}
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		u[a[i]].push_back(i);
	}
	int codd=0;
	for(int i=1;i<=n;i++)if(u[i].size()&1)codd++;
	if(codd>1)return puts("NO"),Clear();
	for(int i=1;i<=n;i++)if(u[i].size()==1&&u[i][0]*2-1==n)return puts("NO"),Clear();
	for(int i=1;i<=n;i++)fa[i]=i;
	int pl=1,pr=n;
	for(int i=1;i<=n;i++){
		if(u[i].size()%2==0){
			for(int j=0;j<u[i].size();j+=2){
				p[pl++]=u[i][j];
				p[pr--]=u[i][j+1];
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(u[i].size()%2==1){
			for(int j=0;j<u[i].size();j++){
				p[pl++]=u[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i,pos[p[i]]=i;
	for(int i=1;i<=n;i++)Merge(i,p[i]);
	for(int i=1;i<=n;i++){
		if(u[i].size()==0)continue;
		int lst=gf(pos[u[i][0]]),any=u[i][0];
		for(int j=1;j<u[i].size();j++){
			if(gf(pos[u[i][j]])!=lst){
				Merge(lst,pos[u[i][j]]);
				swap(p[pos[any]],p[pos[u[i][j]]]);
				swap(pos[any],pos[u[i][j]]);
				lst=gf(lst);
			}
		}
	}
	for(int i=1;i<=n;i++)tp[i]=p[i];
	for(int i=1;i<=n/2;i++)rep[gf(i)]=i;
	q[0]=0;
	for(int i=1;i<=n;i++)if(rep[i])q[++q[0]]=rep[i];
	for(int i=1;i<q[0];i++)p[q[i]]=tp[n-q[i+1]+1],p[n-q[i]+1]=tp[q[i+1]];
	p[q[q[0]]]=tp[q[1]],p[n-q[q[0]]+1]=tp[n-q[1]+1];
	puts("YES");
	for(int i=1;i<=n;i++)cout<<p[i]<<' ';
	puts("");
	Clear();
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}