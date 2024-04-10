#include<bits/stdc++.h>
using namespace std;
int n;
#define cout cerr
#define Maxn 200010
int opt[Maxn];
char ch[5];int x;
vector<int> g[Maxn];

set<int > S;
int ans[Maxn];

void merge(int x,int y){
	if(g[x].size()>g[y].size())swap(g[x],g[y]);
	for(int i=0;i<g[x].size();++i)g[y].push_back(g[x][i]);
}

int main(){
	cin>>n;
	for(int i=1;i<=2*n;++i){
		scanf("%s",ch+1);
		if(ch[1]=='+')opt[i]=-1;
		else{
			scanf("%d",&x);
			opt[i]=x;
		}
	}
	int at=0;
	for(int i=1;i<=2*n;++i)
		if(opt[i]==-1){
			at++;
			int pre=g[0].size();
			g[0].push_back(at);
			if(!pre)S.insert(0);
		}else{
			while(!S.empty()){
				int pos=*(S.begin());
				if(pos>opt[i])break;
				merge(pos,opt[i]);
				S.erase(pos);
			}
			if(!g[opt[i]].size()){
				puts("NO");
				return 0;
			}
			ans[g[opt[i]][g[opt[i]].size()-1]]=opt[i];
			g[opt[i]].pop_back();
			if(g[opt[i]].size()>0)S.insert(opt[i]);
		}
	puts("YES");
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	puts("");
	return 0;
}