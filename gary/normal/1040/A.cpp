#include<bits/stdc++.h>
using namespace std;
int huan1,huan0;//10
int n,num[25],tot2=0,weizhi2[25];int minans=2500,tempans=0;
bool panduan(){
	int head=1,tail=n;
	while(head<tail){
		if(num[head]!=num[tail]) return false;
		head++;
		tail--;
	}
	return true;
}
void dfs(int now){
	if(now==tot2+1){
//		for(int i=1;i<=n;i++) cout<<num[i];
//		cout<<endl;
		if(panduan()) minans=min(minans,tempans);
		return;
	}
	num[weizhi2[now]]=1;//1 
	tempans+=huan1;
	dfs(now+1);
	tempans-=huan1;
	num[weizhi2[now]]=0;
	tempans+=huan0;
	dfs(now+1); 
	tempans-=huan0;
}
int main(){
	scanf("%d %d %d",&n,&huan0,&huan1);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		if(num[i]==2){
			tot2++;
		weizhi2[tot2]=i;
		}
	}
	dfs(1);
	if(minans!=2500) cout<<minans;
	else cout<<-1; 
	return 0;
}