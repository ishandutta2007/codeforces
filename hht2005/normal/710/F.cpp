#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
string str;
struct node {
	string s[N];
	int tr[N][26],en[N],rt[N],fail[N],q[N],las[N],cnt,tot;
	int New() {
		tot++;
		memset(tr[tot],0,sizeof(tr[tot]));
		fail[tot]=en[tot]=0;
		return tot;
	}
	void ins() {
		s[++cnt]=str;
		int x=cnt-(cnt&-cnt);
		tot=las[x];
		rt[cnt]=New();
		for(int i=x+1;i<=cnt;i++) {
			int p=rt[cnt];
			for(char j:s[i]) {
				int c=j-'a';
				if(!tr[p][c])tr[p][c]=New();
				p=tr[p][c];
			}
			en[p]++;
		}
		int l=1,r=0;
		for(int i=0;i<26;i++)
			if(tr[rt[cnt]][i])
				fail[q[++r]=tr[rt[cnt]][i]]=rt[cnt];
		while(l<=r) {
			int x=q[l++];
			if(!fail[x])fail[x]=rt[cnt];
			for(int i=0;i<26;i++)
				if(tr[x][i])fail[q[++r]=tr[x][i]]=tr[fail[x]][i];
				else tr[x][i]=tr[fail[x]][i];
		}
		for(int i=1;i<=r;i++)
			en[q[i]]+=en[fail[q[i]]];
		las[cnt]=tot;
	}
	long long qry() {
		long long ans=0;
		for(int i=cnt;i;i-=i&-i) {
			int p=rt[i];
			for(char j:str) {
				p=tr[p][j-'a'];
				if(p==0)p=rt[i];
				ans+=en[p];
			}
		}
		return ans;
	}
}add,del;
signed main() {
	int n,op;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		cin>>op>>str;
		if(op==1)add.ins();
		if(op==2)del.ins();
		if(op==3)printf("%lld\n",add.qry()-del.qry()),fflush(stdout);
	}
	return 0;
}