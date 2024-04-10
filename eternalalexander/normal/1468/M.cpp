#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,block=400,mod=998244353;
typedef long long ll;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
int n,m;
vector<int> a[N],G[N];
int b[N],vis[N],len[N];
int main(){
	int t=read();
	while(t--){
		n=read();m=0;
		for(int i=1;i<=n;i++){
			int k=read();len[i]=k;a[i].resize(k+1);
			for(int j=1;j<=k;j++) scanf("%d",&a[i][j]),b[++m]=a[i][j];
		}
		sort(b+1,b+m+1);
		m=unique(b+1,b+m+1)-b-1;
		for(int i=1;i<=m;i++) G[i].clear(),vis[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<a[i].size();j++){
				a[i][j]=lower_bound(b+1,b+m+1,a[i][j])-b;
				if(len[i]<=block) G[a[i][j]].push_back(i);
			}
		for(int i=1;i<=n;i++){
			if(len[i]>block){
				for(int j=1;j<=len[i];j++) vis[a[i][j]]=i;
				for(int j=1;j<=n;j++)
					if(j!=i){
						int cnt=0;
						for(int k=1;k<=len[j];k++) {
							if(vis[a[j][k]]) {
								cnt++;
							}
							if(cnt>=2){
								printf("%d %d\n",i,j);
								goto end;
							}
						}
					}
				for(int j=1;j<=len[i];j++) vis[a[i][j]]=0;
			}
		}
		for(int i=1;i<=m;i++){
			if(!G[i].size()) continue;
			for(int j:G[i]){
				for(int k=1;k<a[j].size();k++) {
					if(a[j][k]==i) continue;
					if(vis[a[j][k]]) {
						printf("%d %d\n",vis[a[j][k]],j);
						goto end;
					}
					vis[a[j][k]]=j;
				} 
			}
			for(int j:G[i])
				for(int k=1;k<a[j].size();k++)
					vis[a[j][k]]=0;
		}
		puts("-1");
		end:;
	}
	return 0;
}