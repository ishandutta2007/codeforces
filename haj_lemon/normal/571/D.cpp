#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mr make_pair
#define N 500010
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
struct Onfo{int ki,x,y;}q[N];
struct Info{int we,nu,fu;};
vector<int> s[N],p[N];
vector<Info> qu[N];
int m,n,tr[N];
ll an[N],no[N],ad[N];
ll que(int x){return no[x]+ad[tr[x]];}
int main(){
//	freopen("d.in","r",stdin);
	read(n);read(m);
	for (int i=1;i<=m;i++){
		char ch=getchar();
		while (ch!='U'&&ch!='M'&&ch!='A'&&ch!='Z'&&ch!='Q') ch=getchar();
		if (ch=='U')q[i].ki=1;
		if (ch=='M')q[i].ki=2;
		if (ch=='A')q[i].ki=3;
		if (ch=='Z')q[i].ki=4;
		if (ch=='Q')q[i].ki=5;
		read(q[i].x);
		if (q[i].ki<=2) read(q[i].y);
	}
	for (int i=1;i<=n;i++){s[i].clear();s[i].pb(i);tr[i]=i;no[i]=-1;ad[i]=0;}
	for (int i=1;i<=m;i++){
		if (q[i].ki==2){
			int nx=tr[q[i].x],ny=tr[q[i].y];
			if (s[nx].size()>s[ny].size())swap(nx,ny);
			for (auto j:s[nx])if (no[j]==-1)no[j]=ad[nx];
			for (auto j:s[nx]){p[ny].pb(j);tr[j]=ny;s[ny].pb(j);}
		}
		if (q[i].ki==4){
			int nx=tr[q[i].x];
			ad[nx]=i;
			for (auto j:p[nx])no[j]=-1;p[nx].clear();
		}
		if (q[i].ki==5){
			int nx=q[i].x,la=no[nx];
			if (la==-1)la=ad[tr[nx]];
			qu[la].pb((Info){i,nx,-1});
			qu[i].pb((Info){i,nx,1});
		}
	}
	for (int i=1;i<=n;i++){s[i].clear();s[i].pb(i);tr[i]=i;no[i]=0;ad[i]=0;}
	for (int i=1;i<=m;i++){
		if (q[i].ki==1){
			int nx=tr[q[i].x],ny=tr[q[i].y];
			if (s[nx].size()>s[ny].size())swap(nx,ny);
			for (auto j:s[nx]){no[j]+=ad[nx]-ad[ny];tr[j]=ny;s[ny].pb(j);}
		}
		if (q[i].ki==3)ad[tr[q[i].x]]+=s[tr[q[i].x]].size();
		for (auto j:qu[i])an[j.we]+=que(j.nu)*j.fu;
	}
	for (int i=1;i<=m;i++)if (q[i].ki==5) printf("%lld\n",an[i]);
	return 0;
}