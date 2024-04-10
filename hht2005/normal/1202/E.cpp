#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
char S[N],T[N];
struct node {
	int tr[N][26],en[N],fail[N],q[N],las[N],f[N],tot;
	void ins() {
		int p=0,n=strlen(S+1);
		for(int i=1;i<=n;i++) {
			int c=S[i]-'a';
			if(!tr[p][c])tr[p][c]=++tot;
			p=tr[p][c];
		}
		en[p]++;
	}
	void build() {
		int l=1,r=0;
		for(int i=0;i<26;i++)
			if(tr[0][i])q[++r]=tr[0][i];
		while(l<=r) {
			int x=q[l++];
			if(!fail[x])fail[x]=0;
			for(int i=0;i<26;i++)
				if(tr[x][i])fail[q[++r]=tr[x][i]]=tr[fail[x]][i];
				else tr[x][i]=tr[fail[x]][i];
		}
		for(int i=1;i<=r;i++)
			en[q[i]]+=en[fail[q[i]]];
		int p=0,n=strlen(T+1);
		for(int i=1;i<=n;i++) {
			p=tr[p][T[i]-'a'];
			f[i]=en[p];
		}
	}
}Ze,Ni;
signed main() {
	scanf("%s",T+1);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%s",S+1);
		Ze.ins();
		reverse(S+1,S+strlen(S+1)+1);
		Ni.ins();
	}
	Ze.build();
	reverse(T+1,T+strlen(T+1)+1);
	Ni.build();
	long long ans=0;
	n=strlen(T+1);
	for(int i=1;i<n;i++)
		ans=ans+1ll*Ze.f[i]*Ni.f[n-i];
	printf("%lld\n",ans);
	return 0;
}