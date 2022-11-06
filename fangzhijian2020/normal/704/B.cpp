#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,s,e,now,x[5005],a[5005],b[5005],c[5005],d[5005];
long long pre[5005][2],suf[5005][2],f[2][5005];
long long val(int x,int a,int b){
	return pre[x][a]+suf[x][b];
}
void Add(long long&x,long long y){x=min(x,y);}
int main(){
	n=read();s=read();e=read();
	for(int i=1;i<=n;++i)x[i]=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	for(int i=1;i<=n;++i)c[i]=read();
	for(int i=1;i<=n;++i)d[i]=read();
	for(int i=1;i<=n;++i){
		pre[i][0]=-x[i]+b[i];pre[i][1]=x[i]+a[i];
		suf[i][0]=-x[i]+d[i];suf[i][1]=x[i]+c[i];
	}
	memset(f,0x3f,sizeof(f));f[now=0][0]=0;
	for(int i=1;i<=n;++i){
		now^=1;memset(f[now],0x3f,sizeof(f[now]));
		if(i!=s&&i!=e){
			for(int j=(i>s)+(i>e);j<i;++j){
				Add(f[now][j+1],f[now^1][j]+val(i,0,0));
				if(j>1)Add(f[now][j-1],f[now^1][j]+val(i,1,1));
				if(j>(i>e))Add(f[now][j],f[now^1][j]+val(i,1,0));
				if(j>(i>s))Add(f[now][j],f[now^1][j]+val(i,0,1));
			}
		}
		else{
			if(i==s){
				for(int j=(i>s)+(i>e);j<i;++j){
					Add(f[now][j+1],f[now^1][j]+suf[i][0]);
					if(j>=(i>e))Add(f[now][j],f[now^1][j]+suf[i][1]);
				}
			}
			else if(i==e){
				for(int j=(i>s)+(i>e);j<i;++j){
					Add(f[now][j+1],f[now^1][j]+pre[i][0]);
					if(j>=(i>s))Add(f[now][j],f[now^1][j]+pre[i][1]);
				}
			}
		}
	}
	cout<<f[now][1];
	return 0;
}