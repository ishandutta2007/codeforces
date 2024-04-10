#include <bits/stdc++.h>
#define maxn 200005
 
int n,k,vis[maxn]={0},arr[maxn],cnt=0,rig[maxn],lef[maxn],tl=0,stk[maxn];
char s[maxn],col[maxn];
int tol(int x){return x==1?n:x-1;}
int tor(int x){return x==n?1:x+1;}
 
int main(){
	scanf("%d%d",&n,&k);int inti=k;
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		if (!vis[i]){
			if (s[i]==s[i%n+1]){
			vis[i]=++cnt;
			for(int j=tor(i);s[j]==s[i]&&!vis[j];j=(j+1>n?1:j+1)){vis[j]=vis[i];rig[cnt]=j;}
			lef[cnt]=i;arr[cnt]=cnt;col[cnt]=s[i];}
		}
	}int opt=0;
	while (k--){
		opt++;
		if (cnt==0)break;
		tl=0;
		for(int j=1;j<=cnt;++j){
			int i=arr[j];
		//	printf("%d-%d=>",lef[i],rig[i]);
			
			if (!vis[tor(rig[i])]){
				vis[tor(rig[i])]=i;rig[i]=tor(rig[i]);
				while (!vis[tor(rig[i])]&&((s[tor(rig[i])]==col[i])^(opt%2))){vis[tor(rig[i])]=i;rig[i]=tor(rig[i]);}
			}
			if (!vis[tol(lef[i])]){
				vis[tol(lef[i])]=i;lef[i]=tol(lef[i]);
				while (!vis[tol(lef[i])]&&((s[tol(lef[i])]==col[i])^(opt%2))){vis[tol(lef[i])]=i;lef[i]=tol(lef[i]);}
			}if (vis[tor(rig[i])]&&vis[tol(lef[i])])stk[++tl]=j;
		//	printf("%d-%d\n",lef[i],rig[i]);
		}std::sort(stk+1,stk+tl+1);
		for(int i=tl;i>=1;i--){std::swap(arr[stk[i]],arr[cnt]);cnt--;}
	}for(int i=1;i<=n;++i){
		if (vis[i])printf("%c",col[vis[i]]);
		else {
			if (inti%2==0)printf("%c",s[i]);
			else printf("%c",s[i]=='W'?'B':'W');
		}
	}
	return 0;
}