#include<bits/stdc++.h>
using namespace std;
const int N=210;
int a[N],ch[N][26],fail[N],w[N],q[N],tot;
char s[N];
struct mat {
	int n,m;
	long long v[N][N];
	mat() {
		n=m=0;
		memset(v,0xc0,sizeof(v));
	}
	mat operator*(const mat &a)const {
		mat b;
		b.n=n,b.m=a.m;
		for(int i=0;i<b.n;i++)
			for(int j=0;j<b.m;j++)
				for(int k=0;k<m;k++)
					b.v[i][j]=max(b.v[i][j],v[i][k]+a.v[k][j]);
		return b;
	}
}tas,ans;
int main() {
	int n;
	long long l;
	scanf("%d%lld",&n,&l);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++) {
		scanf("%s",s+1);
		int len=strlen(s+1),p=0;
		for(int j=1;j<=len;j++) {
			int c=s[j]-'a';
			if(!ch[p][c])ch[p][c]=++tot;
			p=ch[p][c];
		}
		w[p]+=a[i];
	}
	int h=1,e=0;
	for(int i=0;i<26;i++)
		if(ch[0][i])q[++e]=ch[0][i];
	while(h<=e) {
		int x=q[h++];
		w[x]+=w[fail[x]];
		for(int i=0;i<26;i++)
			if(!ch[x][i])ch[x][i]=ch[fail[x]][i];
			else fail[q[++e]=ch[x][i]]=ch[fail[x]][i];
	}
	tas.n=tas.m=tot+1;
	ans.n=1,ans.m=tot+1;
	ans.v[0][0]=0;
	for(int i=0;i<=tot;i++)
		for(int j=0;j<26;j++)
			tas.v[i][ch[i][j]]=w[ch[i][j]];
	while(l) {
		if(l&1)ans=ans*tas;
		tas=tas*tas;
		l>>=1;
	}
	long long Ans=-1e18;
	for(int i=0;i<=tot;i++)
		Ans=max(Ans,ans.v[0][i]);
	printf("%lld\n",Ans);
	return 0;
}