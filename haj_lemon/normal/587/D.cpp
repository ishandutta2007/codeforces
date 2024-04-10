#include<bits/stdc++.h>
#define ll long long
#define INF 1e9
#define N 50010
#define M 1000010
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
int m,n,df[M],lo[M],st[M],nst,bi[M],nu,num,ns;
bool v1[M],v2[M];
vector<int> s[N],t[N],a[M];
struct edg{int x,y,c,t,we;}e[N];
bool c1(const edg &a,const edg &b){return a.c<b.c;}
void jb(int x,int y){a[x].push_back(y);a[y^1].push_back(x^1);}
void tarjan(int x){
	st[++nst]=x;lo[x]=df[x]=++num;v1[x]=v2[x]=0;
	for (unsigned i=0;i<a[x].size();i++){
		if (v1[a[x][i]]){tarjan(a[x][i]);lo[x]=min(lo[x],lo[a[x][i]]);}
		else if (!v2[a[x][i]])lo[x]=min(lo[x],df[a[x][i]]);
	}
	if (lo[x]==df[x]){
		nu++;
		while (st[nst]!=x){bi[st[nst]]=nu;v2[st[nst]]=1;nst--;}
		bi[st[nst]]=nu;v2[st[nst]]=1;nst--;
	}
}
bool pa(int x){
	for (int i=1;i<=m;i++)if (e[i].t>x)a[i*2+1].push_back(i*2);
	for (int i=2;i<ns;i++) v1[i]=v2[i]=1;num=nu=0;
	for (int i=2;i<ns;i++)if (v1[i]) tarjan(i);
	for (int i=1;i<=m;i++)if (e[i].t>x)a[i*2+1].pop_back();
	for (int i=2;i<ns;i+=2)if (bi[i+1]==bi[i]) return 0;
	return 1;
}
int main(){
	read(n);read(m);
	for (int i=1;i<=m;i++){read(e[i].x);read(e[i].y);read(e[i].c);read(e[i].t);e[i].we=i;}
	sort(e+1,e+m+1,c1);
	for (int l=1,r=0;l<=m;l=r+1){
		while (e[r+1].c==e[l].c&&r+1<=m)r++;
		for (int i=l;i<=r;i++){
			s[e[i].x].push_back(i);s[e[i].y].push_back(i);
			t[e[i].x].push_back(i*2);t[e[i].y].push_back(i*2);
			if (t[e[i].x].size()>=3){puts("No");return 0;}
			if (t[e[i].y].size()>=3){puts("No");return 0;}
			if (t[e[i].x].size()==2)jb(t[e[i].x][0],t[e[i].x][1]+1);
			if (t[e[i].y].size()==2)jb(t[e[i].y][0],t[e[i].y][1]+1);
		}
		for (int i=l;i<=r;i++){t[e[i].x].pop_back();t[e[i].y].pop_back();}
	}
	ns=2*m+2;
	for (int i=1;i<=n;i++){
		for (unsigned j=0;j<s[i].size();j++){
			if (j!=0){jb(ns,ns-4);jb(s[i][j]*2+1,ns-4);}
			if (j!=s[i].size()-1){jb(ns+2,ns+6);jb(s[i][j]*2+1,ns+6);}
			jb(ns,s[i][j]*2);jb(ns+2,s[i][j]*2);
			ns+=4;
		}
	}
	if (pa(INF)){
		int l=0,r=INF,mid;
		while (l<r){
			mid=(l+r)/2;
			if (pa(mid)) r=mid;else l=mid+1;
		}
		pa(l);
		puts("Yes");
		vector<int> an;an.clear();
		cout<<l<<' ';
		for (int i=1;i<=m;i++)if (bi[i*2+1]<bi[i*2])an.push_back(e[i].we);
		cout<<an.size()<<endl;
		for (unsigned i=0;i<an.size();i++) cout<<an[i]<<' ';cout<<endl;
	}else{
		puts("No");
	}
	return 0; 
}