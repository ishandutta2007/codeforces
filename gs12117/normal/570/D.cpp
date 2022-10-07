#include<stdio.h>
#include<algorithm>
int n,m;
int par[500100];
int chk[500100];
int stk[500100][2];
int sp;
int sn[500100];
int s[500100];
char c[500100];
int tt;
int pre[500100];
int dep[500100];
int tord[500100];
int post[500100];
int qry[500100][2];
int ans[500100];
int dp[500100];
struct qnod{
	int time,orig;
	bool operator<(const qnod&r)const{
		return time<r.time;
	}
};
qnod q[1001000];
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=2;i<=n;i++){
		scanf("%d",&par[i]);
		sn[par[i]+2]++;
	}
	scanf("%s",c+1);
	for(i=0;i<n+3;i++){
		sn[i+1]+=sn[i];
	}
	for(i=2;i<=n;i++){
		s[sn[par[i]+1]]=i;
		sn[par[i]+1]++;
	}
	int loc=1;
	while(1){
fst:
		pre[loc]=tt;
		tord[tt]=loc;
		tt++;
		chk[loc]=1;
		dep[loc]=sp+1;
		for(i=sn[loc];i<sn[loc+1];i++){
			stk[sp][0]=loc;
			stk[sp][1]=i;
			sp++;
			loc=s[i];
			goto fst;//recursive dfs
bck:
			loc=stk[sp][0];
			i=stk[sp][1];
		}
		post[loc]=tt;
		if(sp==0)break;
		sp--;
		goto bck;
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&qry[i][0],&qry[i][1]);
		q[2*i].orig=i;
		q[2*i].time=pre[qry[i][0]];
		q[2*i+1].orig=i;
		q[2*i+1].time=post[qry[i][0]];
	}
	std::sort(q,q+(2*m));
	j=0;
	for(i=0;i<=n;i++){
		while(j<2*m&&q[j].time==i){
			ans[q[j].orig]^=dp[qry[q[j].orig][1]];
			j++;
		}
		if(i==n)break;
		dp[dep[tord[i]]]^=1<<(c[tord[i]]-'a');
	}
	for(i=0;i<m;i++){
		if(ans[i]==0){
			puts("Yes");
		}
		else if(ans[i]==(ans[i]&(-ans[i]))){
			puts("Yes");
		}
		else{
			puts("No");
		}
	}
	return 0;
}