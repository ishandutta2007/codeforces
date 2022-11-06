#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
char s[N];
int n,K,f[N];

int ch[N][26],rt=1,cu;	
int C(int x){
	return 3-x;
}
void dfs(int x){
	int i,p=0,r=1,y;
	for(i=0;i<26;++i){
		if(y=ch[x][i]){
			r=0;
			dfs(y);
			p|=C(f[y]);
		}
	}
	f[x]=p|r;
}
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	int t,i,p,c;
	//cin>>t;
	t=1;
	while(t--){
		cin>>n>>K;
		cu=1;
		memset(ch,0,sizeof ch);
		//memset(f,0,sizeof f);
		while(n--){
			scanf("%s",s);
			p=rt;
			for(i=0;c=s[i]-'a',s[i];++i){
				if(!ch[p][c])
					ch[p][c]=++cu;
				p=ch[p][c];
			}
		}
		dfs(rt);
		//cerr<<f[1]<<endl;
		puts((f[1]==3||(f[1]==2&&K%2))?"First":"Second");
	}
}