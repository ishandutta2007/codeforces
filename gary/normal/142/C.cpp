#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>,int> mpair;
map<mpair,int> M;
int n,m,a[15][15]={0};
int tab[4][3][3]={
	{
		{1,1,1},
		{0,1,0},
		{0,1,0}
	},
	{
		{1,0,0},
		{1,1,1},
		{1,0,0}
	},
	{
		{0,1,0},
		{0,1,0},
		{1,1,1}
	},
	{
		{0,0,1},
		{1,1,1},
		{0,0,1}
	}
};
int rec(int x,int y,int mask){
//	cout<<x<<" "<<y<<endl;
	if(y>m) return rec(x+1,1,mask);
	if(x+2>n) return 0;
	mpair tmp=make_pair(make_pair(x,y),mask);
	if(M.find(tmp)!=M.end()) return M[tmp];		
	M[tmp]=rec(x,y+1,mask>>1);
if(y+2<=m){
	for(int i=0;i<4;i++){
		bool OK=1;
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(OK==0||(tab[i][j][k]&&((mask>>(j*m+k))&1)!=0)){
					OK=0;
				}
			}
		}
		if(OK){
			int nmask=mask;
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(tab[i][j][k]){
					nmask=nmask|(1<<(j*m+k));
				}
			}
		}
		M[tmp]=max(M[tmp],rec(x,y+1,nmask>>1)+1);
		}
		
	}
}
	return M[tmp];
}
int Pns[9][9]={0};
void print(int x,int y,int mask,int Ans){
	if(Ans==0) return;
	if(y>m){
	print(x+1,1,mask,Ans);
	return;
	}
	if(x+2>n) return;
	if(Ans==rec(x,y+1,mask>>1))	{
		print(x,y+1,mask>>1,Ans);
		return;
	}
if(y+2<=m){
	for(int i=0;i<4;i++){
		bool OK=1;
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(OK==0||(tab[i][j][k]&&((mask>>(j*m+k))&1)!=0)){
					OK=0;
				}
			}
		}
		if(OK){
			int nmask=mask;
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(tab[i][j][k]){
					nmask=nmask|(1<<(j*m+k));
				}
			}
		}
		if(rec(x,y+1,nmask>>1)+1==Ans){
			for(int j=0;j<3;j++)
			for(int k=0;k<3;k++){
				if(tab[i][j][k]){
					Pns[j+x][y+k]=Ans;
				}
			}
			print(x,y+1,nmask>>1,Ans-1);
			return;
		}
		}
		
	}
}
}
int main(){
	scanf("%d %d",&n,&m);
	int ans=rec(1,1,0);
	printf("%d\n",ans);
	print(1,1,0,ans); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!Pns[i][j]) printf(".");
			else
			printf("%c",char('A'+Pns[i][j]-1));
		}
		printf("\n");
	}
		
	return 0;
}