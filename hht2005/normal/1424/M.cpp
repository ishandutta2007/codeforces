#include<bits/stdc++.h>
using namespace std;
int S[30][30],p[1010],pos[1010],deg[30],q[30],f[30];
char las[110],s[1000010][110];
int cmp(int x,int y) {
	return p[x]<p[y];
}
int main() {
	int n,k,fi=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d",p+i);
		pos[i]=i;
		for(int j=(i-1)*k+1;j<=i*k;j++) {
			scanf("%s",s[j]+1);
			int len=strlen(s[j]+1);
			for(int k=1;k<=len;k++)
				f[s[j][k]-'a']=1;
		}
	}
	sort(pos+1,pos+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=(pos[i]-1)*k+1;j<=pos[i]*k;j++) {
			if(fi) {
				int L=min(strlen(las+1),strlen(s[j]+1)),fl=1;
				for(int k=1;k<=L;k++)
					if(las[k]!=s[j][k]) {
						fl=0;
						S[las[k]-'a'][s[j][k]-'a']=1;
						break;
					}
				if(fl&&strlen(las+1)>strlen(s[j]+1)) {
					puts("IMPOSSIBLE");
					return 0;
				}
			}
			memcpy(las,s[j],sizeof(las));
			fi=1;
		}
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			if(S[i][j])deg[j]++;
	int h=1,e=0;
	for(int i=0;i<26;i++)
		if(!deg[i])q[++e]=i;
	while(h<=e) {
		int x=q[h++];
		for(int i=0;i<26;i++)
			if(S[x][i]) {
				S[x][i]=0;
				if(!--deg[i])q[++e]=i;
			}
	}
	if(e<26)puts("IMPOSSIBLE");
	else {
		for(int i=1;i<=26;i++)
			if(f[q[i]])putchar(q[i]+'a');
		puts("");
	}
	return 0;
}