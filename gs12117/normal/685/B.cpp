#include<stdio.h>
#include<vector>
int n,m;
int p[300100];
int s[300100];
int h[300100];
int qry[300100];
std::vector<int> el[300100];
int chk[300100];
int stk[300100];
int sp;
int reach[300100];
int ans[300100];
void dfs(int x){
	int loc,i;
	sp=0;
	stk[sp]=x;
	sp++;
	while(sp!=0){
		loc=stk[sp-1];
		if(chk[loc]==0){
			chk[loc]=1;
			h[loc]=h[p[loc]]+1;
			for(i=0;i<el[loc].size();i++){
				stk[sp]=el[loc][i];
				sp++;
			}
		}
		else{
			chk[loc]=2;
			sp--;
			s[loc]=1;
			for(i=0;i<el[loc].size();i++){
				s[loc]+=s[el[loc][i]];
			}
		}
	}
}
void bdfs(int x){
	int loc,i,t;
	sp=0;
	stk[sp]=x;
	sp++;
	while(sp!=0){
		loc=stk[sp-1];
		if(chk[loc]==0){
			chk[loc]=1;
			for(i=0;i<el[loc].size();i++){
				stk[sp]=el[loc][i];
				sp++;
			}
		}
		else{
			chk[loc]=2;
			sp--;
			t=loc;
			for(i=0;i<el[loc].size();i++){
				if(h[t]>h[reach[el[loc][i]]]){
					t=reach[el[loc][i]];
				}
			}
			while(t!=0&&s[t]<=2*s[loc]){
				ans[t]=loc;
				t=p[t];
			}
			reach[loc]=t;
		}
	}
}
int main(){
	int i;
	scanf("%d%d",&n,&m);
	for(i=2;i<=n;i++){
		scanf("%d",&p[i]);
	}
	p[0]=0;
	p[1]=0;
	for(i=2;i<=n;i++){
		el[p[i]].push_back(i);
	}
	h[0]=0;
	dfs(1);
	for(i=0;i<=n;i++){
		chk[i]=0;
	}
	bdfs(1);
	for(i=0;i<m;i++){
		scanf("%d",&qry[i]);
		printf("%d\n",ans[qry[i]]);
	}
	return 0;
}