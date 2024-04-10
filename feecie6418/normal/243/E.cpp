#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef pair<int,int> pr;
basic_string<int> g[5005];
int tot,n,col[5005],tp[5005],rt,pl[5005];//0p 1q
char a[505][505];
void End(){
	puts("NO"),exit(0);
}
void dfs(int x){
	if(x<=n)return ;
	col[x]=0;
	for(int y:g[x])dfs(y),col[x]|=col[y];
}
void dfs2(int x,int lim){
	if(col[x]<=2)return ;
	basic_string<int> t[4];
	for(int y:g[x])t[col[y]]+=y;
	if(((bool)lim)+t[3].size()>2)End();
	if(t[2].size()+t[3].size()==1&&!lim){
		if(t[2].size())return dfs2(t[2][0],0);
		return dfs2(t[3][0],0);
	}
	if(!tp[x]){
		int z=-1;
		if(t[2].size()>1)z=++tot,tp[z]=0,g[z]=t[2];
		else if(t[2].size())z=t[2][0];
		basic_string<int> S;
		if(t[3].size())dfs2(t[3][0],2),S+=g[t[3][0]];
		if(~z)S+=z;
		if(t[3].size()>1)dfs2(t[3][1],1),S+=g[t[3][1]];
		if(t[1].size()){
			if(lim){
				tp[x]=1;
				if(t[1].size()>1)z=++tot,tp[z]=0,g[z]=t[1];
				else z=t[1][0];
				g[x]=z+S;
				if(lim==1)reverse(g[x].begin(),g[x].end());
			}
			else {
				if(S.size()>1)z=++tot,tp[z]=1,g[z]=S;
				else z=S[0];
				g[x]=t[1]+z;
			}
		}
		else {
			tp[x]=1,g[x]=S;
			if(lim==1)reverse(g[x].begin(),g[x].end());
		}
	}
	else {
		basic_string<int> S;
		if(col[g[x][0]]==2||col[g[x].back()]==1)reverse(g[x].begin(),g[x].end());
		int cur=0;
		for(int y:g[x]){
			if(col[y]==1)cur+=(cur==1),S+=y;
			else if(col[y]==2){
				if(cur==2)End();
				cur+=!cur,S+=y;
			}
			else {
				if(cur==2)End();
				cur++,dfs2(y,3-cur),S+=g[y];
			}
		}
		if(lim&&cur==2)End();
		if(lim==1)reverse(S.begin(),S.end());
		g[x]=S;
	}
}
void dfs3(int x){
	if(x<=n)pl[++pl[0]]=x;
	for(int y:g[x])dfs3(y);
}
int main(){
	cin>>n,tot=rt=n+1,tp[tot]=0;
	for(int i=1;i<=n;i++)g[n+1]+=i;
	for(int i=1;i<=n;i++){
		cin>>a[i]+1;
		for(int j=1;j<=n;j++)col[j]=a[i][j]+1-'0';
		dfs(rt),dfs2(rt,0);
	}
	dfs3(rt),puts("YES");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout<<a[i][pl[j]];
		puts("");
	}
}