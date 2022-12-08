#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int fL[maxn],fR[maxn],k[maxn],aL[maxn],aR[maxn],bL[maxn],bR[maxn],n,m;
void dfs(int x,int y) {
	if(x==n)return;
	if(y==0) {
		for(int i=x+1;i<=fL[x];i++)
			printf("1 ");
		dfs(fL[x],1);
	} else {
		for(int i=x+1;i<=fR[x];i++)
			printf("0 ");
		dfs(fR[x],0);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",k+i);
		scanf("%d%d",aL+i,aR+i);
		scanf("%d%d",bL+i,bR+i);
	}
	int L=-1,R=-1,cL=1,cR=1,AL=0,AR=m,BL=0,BR=m;
	if(aL[n]<=k[n]&&k[n]<=aR[n]) {
		fL[L=n]=-1;
		BL=bL[n];
		BR=bR[n];
	}
	if(bL[n]<=k[n]&&k[n]<=bR[n]) {
		fR[R=n]=-1;
		AL=aL[n];
		AR=aR[n];
	}
	for(int i=n-1;i>=0;i--) {
		AL=max(AL,aL[i]);
		AR=min(AR,aR[i]);
		BL=max(BL,bL[i]);
		BR=min(BR,bR[i]);
		int T1=R!=-1&&cR&&AL<=k[i]&&k[i]<=AR,TL=L;
		int T2=L!=-1&&cL&&BL<=k[i]&&k[i]<=BR,TR=R;
		if(T1) {
			fL[L=i]=TR;
			BL=bL[i];
			BR=bR[i];
			cL=1;
		}
		if(T2) {
			fR[R=i]=TL;
			AL=aL[i];
			AR=aR[i];
			cR=1;
		}
		if(aL[i]>k[i]||aR[i]<k[i])cL=0;
		if(bL[i]>k[i]||bR[i]<k[i])cR=0;
	}
	if(fL[0])puts("Yes"),dfs(0,0);
	else if(fR[0])puts("Yes"),dfs(0,1);
	else puts("No");
	return 0;
}