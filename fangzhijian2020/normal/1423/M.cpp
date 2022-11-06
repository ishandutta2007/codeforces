#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
const int Mxdt=100000,INF=1e9+1;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,m,S,V,id,pos[1000005],Max;
unordered_map<int,int>a[1000005];
int A(int i,int j){
	if(a[j].find(i)!=a[j].end())return a[j][i];
	cout<<"? "<<j<<' '<<i<<endl;
	cin>>a[j][i];return a[j][i];
}
vector<int>x,y;
int tot;struct node{int l,r,id;}t[1000005];
int newnode(int v){
	t[++tot]=(node){0,0,v};return tot;
}
void link(int x,int y){t[x].r=y;t[y].l=x;}
void del(int p){
	t[t[p].l].r=t[p].r;t[t[p].r].l=t[p].l;
}
void reduce(vector<int>&x,vector<int>&y){
	tot=1;int p=newnode(x[0]),now=p;link(1,p);
	for(int i=1;i<x.size();++i)link(now,newnode(x[i])),now=t[now].r;
	int n=x.size(),m=y.size(),q=0;
	while(n>m){
		if(p==1)p=t[p].r,++q;
		if(A(t[p].id,y[q])<=A(t[t[p].r].id,y[q])){
			if(q<m-1)p=t[p].r,++q;
			else del(t[p].r),--n;
		}
		else{
			del(p);--n;p=t[p].l;--q;
		}
	}
	p=t[1].r;x.clear();
	while(p){
		x.push_back(t[p].id);p=t[p].r;
	}
}
void smawk(vector<int>&x,vector<int>&y){
	reduce(x,y);
	if(x.size()==1){pos[y[0]]=x[0];return;}
	vector<int>X,Y;X=x;
	for(int i=0;i<y.size();i+=2)Y.push_back(y[i]);
	smawk(X,Y);
	for(int i=1,j=0;i<y.size();i+=2,--j){
		int l=pos[y[i-1]],r=i+1<y.size()?pos[y[i+1]]:*(x.rbegin());
		if(j<0)j=0;
		while(x[j]<l)++j;long long Min=INF;
		while(x[j]<=r&&j<x.size()){
			if(A(x[j],y[i])<Min){
				Min=A(x[j],y[i]);pos[y[i]]=x[j];
			}
			++j;
		}
	}
}
int main(){
	m=read();n=read();
	for(int i=1;i<=n;++i)x.push_back(i);
	for(int i=1;i<=m;++i)y.push_back(i);
	smawk(x,y);int ans=INF;
	for(int i=1;i<=m;++i)ans=min(ans,A(pos[i],i));
	cout<<"! "<<ans<<endl;
	return 0;
}