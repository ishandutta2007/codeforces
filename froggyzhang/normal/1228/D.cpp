#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define N 300010
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
int n,m,cnt,b[N],siz[N];
vector<int> edge[N],tmp[N];
map<vector<int>,int> mp;
bool check(){
	if(b[1]!=n-siz[1]||b[2]!=n-siz[2]||b[3]!=n-siz[3]){
		return false;
	}
	return true;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		edge[u].push_back(v),edge[v].push_back(u);
	} 
	for(int i=1;i<=n;i++){
		sort(edge[i].begin(),edge[i].end());
		tmp[i]=edge[i];
	}
	sort(edge+1,edge+n+1);
	for(int i=1;i<=n;i++){
		if(edge[i]!=edge[i-1]){
			cnt++;
			mp[edge[i]]=cnt;
			siz[cnt]=edge[i].size();
		}
		b[cnt]++;
	}
	if(cnt!=3){
		printf("-1\n");
	}
	else if(!check()){
		printf("-1\n");
	}
	else{
		for(int i=1;i<=n;i++){
			printf("%d ",mp[tmp[i]]);
		}
	}
	return 0;
}
/*
4 5
1 2
2 3
3 4
1 3
2 4
*/