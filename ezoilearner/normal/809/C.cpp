#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> pr;
const int Mod=1000000007;
int f[40][2][2][2],g[40][2][2][2];
bool vis[40][2][2][2];
int num1[40],num2[40],num3[40],cnt1,cnt2,cnt3;
int two[40];
pr dfs(int at,bool lim1,bool lim2,bool lim3){
	if(at==1)return make_pair(1,0);
	if(vis[at][lim1][lim2][lim3])return make_pair(f[at][lim1][lim2][lim3],g[at][lim1][lim2][lim3]);
	pr Ans;
	Ans.first=0;Ans.second=0;
	int up1=(lim1?num1[at-1]:1),up2=(lim2?num2[at-1]:1),up3=(lim3?num3[at-1]:1);
	for(int i=0;i<=up1;++i)
		for(int j=0;j<=up2;++j)
			if((i^j)<=up3){
				pr to=dfs(at-1,lim1&(i==up1),lim2&(j==up2),lim3&((i^j)==up3));
				Ans.first=(Ans.first+to.first)%Mod;
				Ans.second=(1ll*to.first*(i^j)*two[at-2]+Ans.second+to.second)%Mod;
			}
    vis[at][lim1][lim2][lim3]=true;
    f[at][lim1][lim2][lim3]=Ans.first;
    g[at][lim1][lim2][lim3]=Ans.second;
    return Ans;
}
inline int calc(int x,int y,int k){
	if(x<0||y<0||k<0)return 0;
	memset(vis,false,sizeof(vis));
	memset(num1,0,sizeof(num1));
	memset(num2,0,sizeof(num2));
	memset(num3,0,sizeof(num3));
	cnt1=0;cnt2=0;cnt3=0;
	while(x){
		num1[++cnt1]=(x&1);
		x>>=1;
	}
	while(y){
		num2[++cnt2]=(y&1);
		y>>=1;
	}
	while(k){
		num3[++cnt3]=(k&1);
		k>>=1;
	}
	pr Ans=dfs(max(max(cnt1,cnt2),cnt3)+1,1,1,1);
	return (Ans.first+Ans.second)%Mod;
}
int main(){
	two[0]=1;
	for(int i=1;i<40;++i)two[i]=(two[i-1]+two[i-1])%Mod;
	int q;
	scanf("%d",&q);
	int x1,x2,y1,y2,k;
	for(register int tt=1;tt<=q;++tt){
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&k);
		x1--;y1--;x2--;y2--;k--;
		int Ans=(calc(x2,y2,k)+calc(x1-1,y1-1,k))%Mod;
		Ans=(Ans-calc(x2,y1-1,k)+Mod)%Mod;
		Ans=(Ans-calc(x1-1,y2,k)+Mod)%Mod;
		printf("%d\n",Ans);
	}
	return 0;
}