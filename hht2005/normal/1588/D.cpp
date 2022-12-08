#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int f[52][1<<10],lC[52][1<<10],lS[52][1<<10],L[11][60][2],Len[11],n;
char s[11][200];
int get(char x) {
	if('a'<=x&&x<='z')return x-'a';
	else return x-'A'+26;
}
struct node {
	int ch,S;
	node(){}
	node(int X,int Y) {
		ch=X,S=Y;
	}
	int operator<(const node &a)const {
		for(int i=0;i<n;i++)
			if(L[i+1][ch][S>>i&1]!=L[i+1][a.ch][a.S>>i&1])
				return L[i+1][ch][S>>i&1]<L[i+1][a.ch][a.S>>i&1];
		return 0;
	}
}p[(1<<10)*102];
char calc(int x) {
	if(x<26)return x+'a';
	else return x-26+'A';
}
void print(int C,int S) {
	if(C<0||S<0)return;
	print(lC[C][S],lS[C][S]);
	putchar(calc(C));
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		memset(f,0xc0,sizeof(f));
		memset(lC,-1,sizeof(lC));
		memset(lS,-1,sizeof(lS));
		memset(L,0,sizeof(L));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%s",s[i]+1);
			Len[i]=strlen(s[i]+1);
			for(int j=1;j<=Len[i];j++) {
				int c=get(s[i][j]);
				L[i][c][1]=j;
				if(!L[i][c][0])L[i][c][0]=j;
			}
			for(int j=0;j<52;j++) {
				if(!L[i][j][0])L[i][j][0]=Len[i]+1;
				if(!L[i][j][1])L[i][j][1]=Len[i]+1;
			}
		}
		int tot=0;
		for(int i=0;i<52;i++)
			for(int j=0;j<1<<n;j++)
				p[++tot]=node(i,j);
		sort(p+1,p+tot+1);
		int ans=0,C=-1,SS=-1;
		for(int i=1;i<=tot;i++) {
			int ch=p[i].ch,S=p[i].S,FL=1;
			for(int j=0;j<n;j++)
				if(L[j+1][ch][S>>j&1]>Len[j+1])FL=0;
			if(!FL)continue;
			if(f[ch][S]<0)f[ch][S]=1;
			if(ans<f[ch][S])ans=f[C=ch][SS=S];
			for(int j=0;j<52;j++) {
				int SS=0,FL=1;
				for(int k=0;k<n&&FL;k++)
					if(L[k+1][j][0]<=L[k+1][ch][S>>k&1]) {
						if(L[k+1][j][1]<=L[k+1][ch][S>>k&1])FL=0;
						else SS^=1<<k;
					}
				if(!FL)continue;
				if(f[j][SS]<f[ch][S]+1) {
					f[j][SS]=f[ch][S]+1;
					lC[j][SS]=ch;
					lS[j][SS]=S;
				}
			}
		}
		printf("%d\n",ans);
		print(C,SS);
		puts("");
	}
	return 0;
}