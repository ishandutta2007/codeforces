#include<bits/stdc++.h>
#define re register
using namespace std;
int n,T,v[26],fst[26],nxt[100002][26],a[100002],b[100002],m,cnt,pos,ans;
char s[100002],t[100002];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",t+1,s+1);
		n=strlen(s+1);
		m=strlen(t+1);
		memset(fst,0,sizeof(fst));
		for(re int i=1;i<=n;++i)a[i]=s[i]-'a';
		for(re int i=1;i<=m;++i)b[i]=t[i]-'a';
		for(re int i=m;i>=1;--i){
			if(i!=m)
			for(re int j=0;j<=25;++j)nxt[i][j]=nxt[i+1][j];
			else for(re int j=0;j<=25;++j)nxt[i][j]=0;
			if(i!=m)
			nxt[i][b[i+1]]=i+1;
			fst[b[i]]=i;
		}
		pos=fst[a[1]];
		ans=1;
		if(!pos){
			puts("-1");
			continue;
		}
		bool ia=1;
		for(re int i=2;i<=n;++i){
			if(nxt[pos][a[i]]){
				pos=nxt[pos][a[i]];
			}
			else {++ans,pos=fst[a[i]];
			if(!pos){
				ia=0;
				puts("-1");
				break;
			}
			}
		}
		if(ia)
		printf("%d\n",ans);
	}
}