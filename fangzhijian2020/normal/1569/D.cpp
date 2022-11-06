#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int Mxdt=100000,N=200000;
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
int T,n,m,k,x[300005],y[300005],h[300006];long long ans;
struct node{
	int x,y;
}t[300005];
vector<node>v[2];
int check1(int X){
	int t=lower_bound(x+1,x+n+1,X)-x;
	if(x[t]==X){
		return t;
	}
	return 0;
//	return (x[t]==X);
}
int check2(int Y){
	int t=lower_bound(y+1,y+m+1,Y)-y;
	if(y[t]==Y)return t;
	return 0;
}
bool cmp1(const node&a,const node&b){
	return a.y<b.y;
}
bool cmp2(const node&a,const node&b){
	return a.x<b.x;
}
int main(){
	T=read()+1;
	while(--T){
		n=read();m=read();k=read();
		ans=0;v[0].clear();v[1].clear();
		for(int i=1;i<=n;++i)x[i]=read();
		for(int i=1;i<=m;++i)y[i]=read();
		for(int i=1;i<=k;++i){
			t[i].x=read();t[i].y=read();
			int t1=check1(t[i].x);
			int t2=check2(t[i].y);
			if(!t1||!t2){
				if(t1)t[i].x=t1,v[0].push_back(t[i]);
				else t[i].y=t2,v[1].push_back(t[i]);
			}
		}
		if(v[0].size()){
			sort(v[0].begin(),v[0].end(),cmp1);
			for(int i=0;i<v[0].size();++i)h[v[0][i].x]=0;
			for(int i=0,j=0;i<v[0].size();++i){
				int Y=v[0][i].y;
				int tp=upper_bound(y+1,y+m+1,Y)-y-1;
				h[v[0][i].x]++;
				while(v[0][j].y<y[tp])--h[v[0][j++].x];
				ans+=i-j+1-h[v[0][i].x];
			}
		}
		if(v[1].size()){
			sort(v[1].begin(),v[1].end(),cmp2);
			for(int i=0;i<v[1].size();++i)h[v[1][i].y]=0;
			for(int i=0,j=0;i<v[1].size();++i){
				int X=v[1][i].x;
				int tp=upper_bound(x+1,x+n+1,X)-x-1;
				h[v[1][i].y]++;
				while(v[1][j].x<x[tp])--h[v[1][j++].y];
				ans+=i-j+1-h[v[1][i].y];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}