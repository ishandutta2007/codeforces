#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const char ch[4]={'A','T','C','G'};
vector<char>S[N];
char s[N];
int H[N][4][2],L[N][4][2];
int get(char c) {
	if(c=='A')return 0;
	if(c=='T')return 1;
	if(c=='C')return 2;
	if(c=='G')return 3;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%s",s+1);
		S[i].push_back(0);
		for(int j=1;j<=m;j++)
			S[i].push_back(s[j]);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			H[i][get(S[i][j])][j&1]++;
			L[j][get(S[i][j])][i&1]++;
		}
	int Max=0,I=-1,J=-1,op=0;
	for(int i=0;i<4;i++)
		for(int j=i+1;j<4;j++) {
			int sum=0,k=-1,l=-1;
			for(int a=0;a<4;a++)
				if(a!=i&&a!=j) {
					if(k==-1)k=a;
					else l=a;
				}
			for(int a=1;a<=n;a++) {
				if(a&1)sum+=max(H[a][i][0]+H[a][j][1],H[a][i][1]+H[a][j][0]);
				else sum+=max(H[a][k][0]+H[a][l][1],H[a][k][1]+H[a][l][0]);
			}
			if(sum>=Max) {
				Max=sum;
				I=i,J=j;
			}
		}
	for(int i=0;i<4;i++)
		for(int j=i+1;j<4;j++) {
			int sum=0,k=-1,l=-1;
			for(int a=0;a<4;a++)
				if(a!=i&&a!=j) {
					if(k==-1)k=a;
					else l=a;
				}
			for(int a=1;a<=m;a++) {
				if(a&1)sum+=max(L[a][i][0]+L[a][j][1],L[a][i][1]+L[a][j][0]);
				else sum+=max(L[a][k][0]+L[a][l][1],L[a][k][1]+L[a][l][0]);
			}
			if(sum>=Max) {
				Max=sum;
				I=i,J=j;
				op=1;
			}
		}
	if(op==0) {
		int K=-1,L=-1;
		for(int a=0;a<4;a++)
			if(a!=I&&a!=J) {
				if(K==-1)K=a;
				else L=a;
			}
		for(int a=1;a<=n;a++) {
			if(a&1) {
				if(H[a][I][0]+H[a][J][1]<H[a][I][1]+H[a][J][0]) {
					for(int i=1;i<=m;i++)
						if(i&1)S[a][i]=ch[I];
						else S[a][i]=ch[J];
				} else {
					for(int i=1;i<=m;i++)
						if(i&1)S[a][i]=ch[J];
						else S[a][i]=ch[I];
				}
			} else {
				if(H[a][K][0]+H[a][L][1]<H[a][K][1]+H[a][L][0]) {
					for(int i=1;i<=m;i++)
						if(i&1)S[a][i]=ch[K];
						else S[a][i]=ch[L];
				} else {
					for(int i=1;i<=m;i++)
						if(i&1)S[a][i]=ch[L];
						else S[a][i]=ch[K];
				}
			}
		}
	} else {
		int K=-1,l=-1;
		for(int a=0;a<4;a++)
			if(a!=I&&a!=J) {
				if(K==-1)K=a;
				else l=a;
			}
		for(int a=1;a<=m;a++) {
			if(a&1) {
				if(L[a][I][0]+L[a][J][1]<L[a][I][1]+L[a][J][0]) {
					for(int i=1;i<=n;i++)
						if(i&1)S[i][a]=ch[I];
						else S[i][a]=ch[J];
				} else {
					for(int i=1;i<=n;i++)
						if(i&1)S[i][a]=ch[J];
						else S[i][a]=ch[I];
				}
			} else {
				if(L[a][K][0]+L[a][l][1]<L[a][K][1]+L[a][l][0]) {
					for(int i=1;i<=n;i++)
						if(i&1)S[i][a]=ch[K];
						else S[i][a]=ch[l];
				} else {
					for(int i=1;i<=n;i++)
						if(i&1)S[i][a]=ch[l];
						else S[i][a]=ch[K];
				}
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++)
			putchar(S[i][j]);
		puts("");
	}
	return 0;
}