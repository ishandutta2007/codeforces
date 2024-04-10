#include<bits/stdc++.h>
#define ll long long
#define N 110
#define INF 1e9
using namespace std;
int m,n,x,p,q,y,s,t,b[N],num=1,di[N],la[N],li[N*N],go[N],ans,g[N],vi[N];
struct Info{int nu,ne,qu,co;}a[N*10];
void jb(int x,int y,int lu,int co){
	a[++num]=(Info){y,b[x],lu,co};b[x]=num;
	a[++num]=(Info){x,b[y],0,-co};b[y]=num;
}
bool bfs(){
	for (int i=1;i<=t;i++)di[i]=INF,vi[i]=1;
	int l=1,r=1;li[l]=s;di[s]=0;go[s]=INF;vi[s]=0;
	while (l<=r){
		for (int y=b[li[l]];y;y=a[y].ne){
			if (di[a[y].nu]>di[li[l]]+a[y].co&&a[y].qu){
				di[a[y].nu]=di[li[l]]+a[y].co;la[a[y].nu]=y;go[a[y].nu]=min(go[li[l]],a[y].qu);
				if (vi[a[y].nu]){vi[a[y].nu]=0;li[++r]=a[y].nu;}
			}
		}
		vi[li[l]]=1;
		l++;
	}
	if (di[t]==INF) return 0;
	ans+=di[t]*go[t];
	for (int i=t;i!=s;i=a[la[i]^1].nu){
		a[la[i]].qu-=go[t];a[la[i]^1].qu+=go[t];
	}
	return 1;
}
int main(){
	cin>>n>>m;
	s=n+1,t=n+2;
	for (int i=1;i<=m;i++){
		cin>>x>>y>>q>>p;
		if (p>q){
			ans+=p-q;
			jb(x,y,INF,2);jb(y,x,p-q,0);jb(y,x,q,1);
		}else{
			jb(x,y,q-p,1);jb(x,y,INF,2);jb(y,x,p,1);
		}
		g[x]-=p;g[y]+=p;
	}
	jb(n,1,INF,0);
	for (int i=1;i<=n;i++){
		if (g[i]>0) jb(s,i,g[i],0);else jb(i,t,-g[i],0);
	}
	while (bfs());
	cout<<ans<<endl;
	return 0;
}