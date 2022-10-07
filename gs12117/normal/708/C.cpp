#include<stdio.h>
#include<vector>
int n;
int edge[400100][2];
std::vector<int> el[400100];
int chk[400100];
int ans[400100];
int stk[400100];
int sn[400100];
int sp;
int cent;
int mx,smx,mxl;
void fdfs(int loc){
	int i;
	stk[0]=loc;
	sp=1;
	while(sp>=0){
		sp--;
		loc=stk[sp];
		if(chk[loc]==0){
			chk[loc]=1;
			sp++;
			for(i=0;i<el[loc].size();i++){
				if(chk[el[loc][i]]!=0)continue;
				stk[sp]=el[loc][i];
				sp++;
			}
		}
		else if(chk[loc]==1){
			chk[loc]=2;
			sn[loc]=1;
			for(i=0;i<el[loc].size();i++){
				if(chk[el[loc][i]]!=2)continue;
				sn[loc]+=sn[el[loc][i]];
			}
		}
	}
}
void sdfs(int loc,int x){
	int i;
	stk[0]=loc;
	sp=1;
	while(sp>=0){
		sp--;
		loc=stk[sp];
		if(chk[loc]==0){
			chk[loc]=1;
			sp++;
			for(i=0;i<el[loc].size();i++){
				if(chk[el[loc][i]]!=0)continue;
				stk[sp]=el[loc][i];
				sp++;
			}
		}
		else if(chk[loc]==1){
			chk[loc]=2;
			if((x+sn[loc])*2>=n)ans[loc]=1;
			else ans[loc]=0;
		}
	}
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n-1;i++){
		scanf("%d%d",&edge[i][0],&edge[i][1]);
		el[edge[i][0]].push_back(edge[i][1]);
		el[edge[i][1]].push_back(edge[i][0]);
	}
	fdfs(1);
	cent=1;
	for(i=1;i<=n;i++){
		if(sn[i]*2>=n&&sn[cent]>sn[i]){
			cent=i;
		}
	}
	if(sn[cent]*2==n){
		for(i=1;i<=n;i++){
			ans[i]=1;
		}
	}
	else{
		for(i=1;i<=n;i++){
			chk[i]=0;
		}
		fdfs(cent);
		for(i=1;i<=n;i++){
			chk[i]=0;
		}
		chk[cent]=3;
		mx=0;
		smx=0;
		mxl=-1;
		for(i=0;i<el[cent].size();i++){
			if(sn[el[cent][i]]>mx){
				smx=mx;
				mxl=i;
				mx=sn[el[cent][i]];
			}
			else if(sn[el[cent][i]]>smx){
				smx=sn[el[cent][i]];
			}
		}
		for(i=0;i<el[cent].size();i++){
			if(i==mxl)sdfs(el[cent][i],smx);
			else sdfs(el[cent][i],mx);
		}
		ans[cent]=1;
	}
	for(i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}