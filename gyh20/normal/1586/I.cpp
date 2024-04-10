#include<bits/stdc++.h>
#define re register
using namespace std;
int n,bl[2002][2002],ans[2002][2002],T[2002];
char s[2002][2002]; 
int main(){
	scanf("%d",&n),memset(T,-1,sizeof(T));
	if(n&1)return puts("NONE"),0;
	for(re int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(re int i=1;i<=n;i+=2){
		re int px=i+1,py=1,cur=0;
		while(px<=n)ans[px][py]=cur,bl[px][py]=i,++px,++py,cur^=1;
		--px,cur^=1;
		while(py<=n)ans[px][py]=cur,bl[px][py]=i,--px,++py,cur^=1;
		--py,cur^=1;
		while(px)ans[px][py]=cur,bl[px][py]=i,--px,--py,cur^=1;
		++px,cur^=1;
		while(py)ans[px][py]=cur,bl[px][py]=i,++px,--py,cur^=1;
	}
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j)
			if(s[i][j]!='.'){
				re int x=bl[i][j];
				if(T[x]==-1||T[x]==((s[i][j]=='S')^ans[i][j]))T[x]=((s[i][j]=='S')^ans[i][j]);
				else return puts("NONE"),0;
			}
	for(re int i=1;i<=n;i+=2)if(T[i]==-1)return puts("MULTIPLE"),0;
	puts("UNIQUE");
	for(re int i=1;i<=n;++i,puts(""))
		for(re int j=1;j<=n;++j)
			putchar((ans[i][j]^T[bl[i][j]])?'S':'G');
}