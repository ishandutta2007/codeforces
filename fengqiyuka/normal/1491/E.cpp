#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=2e5+100;
struct edge{
	int x,y,next;
}a[2*N];int len,last[N],f[N];bool bz[2*N];
void ins(int x,int y){
	a[++len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
int d[N],size[N],g[N],fa[N];bool bk[N];
void dfs(int x){
	bk[x]=false;size[x]=1;d[++d[0]]=x;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(bz[k]&&bk[y]){
			fa[y]=x;g[y]=k;
			dfs(y);
			size[x]+=size[y];
		}
	}
}
bool solve(int st,int dep){
	if(dep<=1) return true;
	d[0]=0;dfs(st);
	bool pd=false;
	int Sum1=0,Sum2=0;
	for(int i=1;i<=d[0];i++){
		if(size[d[i]]==f[dep-2]) Sum1++;
		else if(size[d[i]]==f[dep-1]) Sum2++;
	}
	if(Sum1+Sum2==2){
		int x1=-1,x2=-1;
		for(int i=1;i<=d[0];i++){
			if(size[d[i]]==f[dep-2]||size[d[i]]==f[dep-1]){
				if(x1==-1) x1=d[i];
				else x2=d[i];
			}
		}
		bz[g[x1]]=bz[g[x1]^1]=false;
		bz[g[x2]]=bz[g[x2]^1]=false;
		for(int j=1;j<=d[0];j++) bk[d[j]]=true;
		if(size[x1]<size[x2]) swap(x1,x2);
		int t=fa[x1];
		if(Sum1==2){
			if(solve(x1,dep-2)&&solve(x2,dep-2)&&solve(t,dep-3)) return true;
			else return false;
		}
		else{
			if(solve(x1,dep-3)&&solve(x2,dep-2)&&solve(t,dep-2)) return true;
			else return false;
		}
	}
	else if(Sum1==1||Sum2==1){
		for(int i=1;i<=d[0];i++){
			if(d[i]!=st&&(size[d[i]]==f[dep-1]||size[d[i]]==f[dep-2])){
				if(size[d[i]]==f[dep-1]){
					bz[g[d[i]]]=bz[g[d[i]]^1]=false;
					for(int j=1;j<=d[0];j++) bk[d[j]]=true;
					int t1=d[i],t2=fa[d[i]];
					if(solve(t1,dep-1)&&solve(t2,dep-2)) return true;
					else return false;
				}
				else{
					bz[g[d[i]]]=bz[g[d[i]]^1]=false;
					for(int j=1;j<=d[0];j++) bk[d[j]]=true;
					int t1=d[i],t2=fa[d[i]];
					if(solve(t1,dep-2)&&solve(t2,dep-1)) return true;
					else return false;
				}
			}
		}
	}
	return false;
}
int main()
{
	int n;scanf("%d",&n);
	len=1;memset(last,0,sizeof(last));
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ins(x,y);ins(y,x);
	}
	memset(bk,true,sizeof(bk));
	memset(bz,true,sizeof(bz));
	f[0]=f[1]=1;
	for(int i=2;i<=30;i++) f[i]=f[i-1]+f[i-2];
	int id=0;
	for(int i=1;i<=30;i++){
		if(f[i]==n) {id=i;break;}
	}
	if(id==0){
		printf("NO\n");
		return 0;
	}
	if(solve(1,id)) printf("YES\n");
	else printf("NO\n");
	return 0;
}