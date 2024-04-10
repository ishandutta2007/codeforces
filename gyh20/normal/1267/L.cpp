#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#define in inline
#define re register
using namespace std;
in int read() {
	re int t=0;
	re char v=getchar();	
	while(v<'0'||v>'9'){
	v=getchar();
	}	
	while(v>='0'&&v<='9'){		
	t=(t<<3)+(t<<1)+(v^48);		
	v=getchar();	}
	return t;
}
char ans[1002][1002],s[1000002];
int n,l,k,cnt[2006],fst[2006],tot;
inline void work(re int x,re int a){
	if(x>l)return;
	memset(fst,0,sizeof(fst));
	for(re int i=a;i<=k;++i){
		ans[i][x]=s[tot++];
		if(!fst[s[tot-1]])fst[s[tot-1]]=i;
	}
	work(x+1,fst[ans[k][x]]);
}
int main(){
	scanf("%d %d %d",&n,&l,&k);	scanf("%s",s);
	sort(s,s+n*l);
	work(1,1);
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<=l;++j){
			if(ans[i][j])putchar(ans[i][j]);
			else putchar(s[tot++]);
		}
		putchar('\n');
	}
}