#include <bits/stdc++.h>
int nxt[100002],rd[100002],vis[100002];
using namespace std;
vector<int>head,tail;
int dfs(int x){
	vis[x]=1;
	if (!vis[nxt[x]]) return vis[x]=dfs(nxt[x]);
	else return vis[x]=x;
}
inline int read(){
    int t=0;char v=getchar();
    while(v<'0')v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return t;
}
int main(){
	int n=read();
	for(int i=1; i<=n; ++i)++rd[nxt[i]=read()];
	int k=0;
	for(int i=1; i<=n; ++i)
		if(!rd[i]){
			++k;
			head.push_back(i);
			tail.push_back(dfs(i));
		}
int kk=k;
	for (int i=1; i<=n; i++)
		if (!vis[i])
		{
			k++;
			head.push_back(i);
			tail.push_back(dfs(i));
		}
	if (k==1&&!kk) k=0;
	printf("%d\n",k);
	for(int i=0;i<k;++i) printf("%d %d\n",tail[i],head[(i+1)%k]);
}