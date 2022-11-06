#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int mod=1e9+7;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int n,d,m;char a[1005],b[1005],c[1005],A[1005];
int tot=1,root=1,ch[50005][10],val[50005],fail[50005];
void insert(int l,int r){
	int now=root;
	for(int i=l;i<=r;++i){
		int x=c[i]-'0';
//		cout<<x<<"::;\n";
		if(!ch[now][x])ch[now][x]=++tot;
		now=ch[now][x];
	}
	val[now]=1;
}
queue<int>q;
void build(){
	q.push(root);
	while(!q.empty()){
		int x=q.front();q.pop();val[x]|=val[fail[x]];
		for(int y=0;y<10;++y){
			if(ch[x][y]){
				if(fail[x])fail[ch[x][y]]=ch[fail[x]][y];
				else fail[ch[x][y]]=root;q.push(ch[x][y]);
			}
			else{
				if(fail[x])ch[x][y]=ch[fail[x]][y];
				else ch[x][y]=root;
			}
		}
	}
	fail[root]=root;
}
int f[55][50005][2];
int dfs(int dep,int now,int flag,int tag){
	int lim=flag?A[dep]-'0':9;
	if(!flag&&f[dep][now][tag]!=-1)return f[dep][now][tag];
	if(dep==m+1)return tag;int sum=0;
	for(int i=dep==1?1:0;i<=lim;++i){
		Add(sum,dfs(dep+1,ch[now][i],flag&(i==lim),tag|val[ch[now][i]]));
	}
	if(!flag)f[dep][now][tag]=sum;return sum;
}
int S(char*c){
	memset(f,-1,sizeof(f));
	for(int i=1;i<=m;++i)A[i]=c[i];
	return dfs(1,1,1,0);
}
int main(){
	scanf("%s",c+1);n=strlen(c+1);scanf("%s%s",a+1,b+1);m=strlen(a+1);
	for(int i=1;i+(m/2)-1<=n;++i)insert(i,i+(m/2)-1);build();
	--a[m];for(int i=m;i;--i)if(a[i]<'0')a[i]+=10,--a[i-1];
	cout<<(S(b)-S(a)+mod)%mod;
	return 0;
}