#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
const string a[]={"H","HE","LI","BE","B","C","N","O","F","NE","NA","MG","AL","SI","P","S","CL","AR","K","CA","SC","TI","V","CR","MN","FE","CO","NI","CU","ZN","GA","GE","AS","SE","BR","KR","RB","SR","Y","ZR","NB","MO","TC","RU","RH","PD","AG","CD","IN","SN","SB","TE","I","XE","CS","BA","LA","CE","PR","ND","PM","SM","EU","GD","TB","DY","HO","ER","TM","YB","LU","HF","TA","W","RE","OS","IR","PT","AU","HG","TL","PB","BI","PO","AT","RN","FR","RA","AC","TH","PA","U","NP","PU","AM","CM","BK","CF","ES","FM","MD","NO","LR","RF","DB","SG","BH","HS","MT","DS","RG","CN","NH","FL","MC","LV","TS","OG"};char s[N];
void dfs(int x){
	if(!s[x]){
		printf("YES\n");exit(0);
	}
	int i=0;
	do{
		int l=a[i].length();
		if(l==1&&s[x]==a[i][0])dfs(x+1);
		if(l==2&&s[x]==a[i][0]&&s[x+1]==a[i][1])dfs(x+2);
		if(l==3&&s[x]==a[i][0]&&s[x+1]==a[i][1]&&s[x+2]==a[i][2])dfs(x+3);
	}while(a[i++]!="OG");
}
int main(){
	scanf("%s",s);
	dfs(0);printf("NO\n");
}