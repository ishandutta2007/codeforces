#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<set>
using namespace std;
#define N 1000010
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,n,m,num,ans1,ans2,cir[N],tot;
string s[N];
string col[N];
vector<int> dis[N],id[N],vis[N];
set<int> mp[N];
void dfs(int x,int y){
	if(id[x][y]){
		return;
	} 
	vis[x][y]=++tot;
	if(s[x][y]=='U'){
		if(vis[x-1][y]&&!id[x-1][y]){
			dis[x][y]=1,id[x][y]=++num;
			cir[num]=vis[x][y]-vis[x-1][y]+1;
			mp[num].clear(); 
		}
		else{
			dfs(x-1,y);
			dis[x][y]=dis[x-1][y]+1;
			id[x][y]=id[x-1][y];
		}
	}
	else if(s[x][y]=='D'){
		if(vis[x+1][y]&&!id[x+1][y]){
			dis[x][y]=1,id[x][y]=++num;
			cir[num]=vis[x][y]-vis[x+1][y]+1;
			mp[num].clear();
		}
		else{
			dfs(x+1,y);
			dis[x][y]=dis[x+1][y]+1;
			id[x][y]=id[x+1][y];
		}
	}
	else if(s[x][y]=='L'){
		if(vis[x][y-1]&&!id[x][y-1]){
			dis[x][y]=1,id[x][y]=++num;
			cir[num]=vis[x][y]-vis[x][y-1]+1;
			mp[num].clear();
		}
		else{
			dfs(x,y-1);
			dis[x][y]=dis[x][y-1]+1;
			id[x][y]=id[x][y-1];
		}
	}
	else{
		if(vis[x][y+1]&&!id[x][y+1]){
			dis[x][y]=1,id[x][y]=++num;
			cir[num]=vis[x][y]-vis[x][y+1]+1;
			mp[num].clear();
		}
		else{
			dfs(x,y+1);
			dis[x][y]=dis[x][y+1]+1;
			id[x][y]=id[x][y+1];
		}
	}
	if(col[x][y]=='0')mp[id[x][y]].insert(dis[x][y]%cir[id[x][y]]);
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read(),num=0,ans1=ans2=tot=0;
		for(int i=0;i<n;++i)cin>>col[i];
		for(int i=0;i<n;++i){
			cin>>s[i];
			dis[i].clear();
			id[i].clear();
			vis[i].clear(); 
			for(int j=0;j<m;++j){
				dis[i].push_back(0);
				id[i].push_back(0);
				vis[i].push_back(0);
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(id[i][j])continue;
				dfs(i,j);
			}
		}
		for(int i=1;i<=num;++i){
			ans2+=mp[i].size();
			ans1+=cir[i];
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}