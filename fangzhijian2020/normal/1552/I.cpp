#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int Mxdt=100000,mod=998244353;
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
int Mod(int x){return x<mod?x:x-mod;}
int n,m,tot,root,q,opt[1000005],col[1000005],ans=1;
basic_string<int>v[1000005];
void dfs(int x){
	if(x>n)col[x]=0;
	for(int y:v[x]){
		dfs(y);col[x]|=col[y];
	}
}
void solve(int x,int lim){
	int p1,p2;
	if(col[x]==3){
		basic_string<int>t[4],S,q;int P=0,Q=0;
		for(int y:v[x])t[col[y]]+=y;
		if(t[3].size()+(bool)lim>2){puts("0");exit(0);}
		if(t[3].size()+t[1].size()==1&&!lim){
			if(t[3].size())solve(t[3][0],0);return;
		}
		if(opt[x]==1){
			if(t[1].size()>1)opt[P=++tot]=1,v[P]=t[1];
			else if(t[1].size())P=t[1][0];
			if(t[3].size()){solve(t[3][0],1);S+=v[t[3][0]];}
			if(P)S+=P;
			if(t[3].size()>1){solve(t[3][1],2);S+=v[t[3][1]];}
			if(t[2].size()){
				if(lim){
					if(t[2].size()>1)opt[Q=++tot]=1,v[Q]=t[2];
					else Q=t[2][0];S=Q+S;opt[x]=2;v[x]=S;
					if(lim==2)reverse(v[x].begin(),v[x].end());
				}
				else{
					if(S.size()>1)opt[Q=++tot]=2,v[Q]=S;
					else Q=S[0];v[x]=t[2]+Q;
				}
			}
			else{
				opt[x]=2;if(lim==2)reverse(S.begin(),S.end());v[x]=S;
			}
		}
		else{
			int opt=0;
			if(col[v[x][0]]==1||col[v[x].back()]==2)reverse(v[x].begin(),v[x].end());
			for(int y:v[x]){
				if(col[y]==1){
					if(opt<=1){S+=y;opt=1;}
					else{puts("0");exit(0);}
				}
				else if(col[y]==2){if(opt)opt=2;S+=y;}
				else if(col[y]==3){
					if(opt<=1){solve(y,opt+1);S+=v[y];++opt;}
					else{puts("0");exit(0);}
				}
			}
			if(lim&&opt==2){puts("0");exit(0);}
			if(lim==2)reverse(S.begin(),S.end());
			v[x]=S;
		}
	}
}
int fac[5005],t[5005],tots;
void DFS(int x){
	if(x<=n){t[++tots]=x;return;}
	if(opt[x]==1)ans=1ll*ans*fac[v[x].size()]%mod;
	else if(opt[x]==2)ans=Mod(ans<<1);
	for(int y:v[x])DFS(y);
}
int main(){
	n=tot=read();m=read();root=++tot;opt[tot]=1;
	for(int i=1;i<=n;++i)v[root]+=i;
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=1;i<=m;++i){
		q=read();
		for(int j=1;j<=n;++j)col[j]=2;
		for(int j=1;j<=q;++j)col[read()]=1;
		if(q==1)continue;dfs(root);solve(root,0);
	}
	DFS(root);cout<<ans<<"\n";
//	for(int i=1;i<=n;++i)cout<<t[i]<<" ";
	return 0;
}