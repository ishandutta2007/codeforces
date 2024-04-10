#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const char S[4]={'A','N','O','T'};
int p[4],t[4],id[maxn],T[4][maxn],c[maxn],n;
char s[maxn],A[maxn],B[maxn];
void add(int x,int v) {
	for(int i=x;i<=n;i+=i&-i)c[i]+=v;
}
int qry(int x) {
	int ans=0;
	for(int i=x;i;i-=i&-i)ans+=c[i];
	return ans;
}
int main() {
	int TT;
	scanf("%d",&TT);
	while(TT--) {
		memset(t,0,sizeof(t));
		s[1]='A';
		scanf("%s",s+1);
		n=strlen(s+1);
		A[n+1]=B[n+1]=0;
		long long ans=0;
		for(int i=1;i<=n;i++) {
			if(s[i]=='A')T[0][++t[0]]=i;
			if(s[i]=='N')T[1][++t[1]]=i;
			if(s[i]=='O')T[2][++t[2]]=i;
			if(s[i]=='T')T[3][++t[3]]=i;
		}
		for(int i=0;i<4;i++)p[i]=i;
		do {
			int cnt=0;
			for(int i=0;i<4;i++)
				for(int j=1;j<=t[p[i]];j++)
					A[++cnt]=S[p[i]],id[cnt]=T[p[i]][j];
			long long sum=0;
			for(int i=n;i>=1;i--) {
				sum+=qry(id[i]);
				add(id[i],1);
			}
			if(sum>=ans) {
				ans=sum;
				for(int i=1;i<=n;i++)B[i]=A[i];
			}
			for(int i=1;i<=n;i++)c[i]=0;
		}while(next_permutation(p,p+4));
		printf("%s\n",B+1);
	}
	return 0;
}