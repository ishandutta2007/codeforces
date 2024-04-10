#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2010,mod=998244353;
char s[N][N],s2[N][N];
int mi(int x,int t){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}
int ni(int x) {return mi(x,mod-2);}

vector<int> B[2*N];bool bk[2*N];
int Cnt,sta[2*N],tot,a[2*N];
void dfs(int x){
	bk[x]=false;sta[++tot]=x;
	for(auto y:B[x]){
		Cnt++;
		if(bk[y]){
			dfs(y);
		}
	}
}

int main()
{
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	
	if(n%2==0&&m%2==0){
		int Sum=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(s[i][j]=='?') Sum++;
		printf("%d\n",mi(2,Sum));
		return 0;
	}
	if(n%2==0||m%2==0){
		if(n%2==1){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					s2[j][i]=s[i][j];
			swap(n,m);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					s[i][j]=s2[i][j];
		}
		int las=-1;bool pd=true;
		int Sum1=0,Sum3=0;
		for(int i=1;i<=n;i++){
			int Sum=0;
			for(int j=1;j<=m;j++){
				if(s[i][j]=='?') Sum++;
			}
			Sum1+=Sum;
			if(Sum>0) Sum3++;
			if(Sum==0){
				int Sum2=0;
				for(int j=1;j<=m;j++){
					Sum2^=(s[i][j]-'0');
				}
				if(las==-1) las=Sum2;
				else if(las!=Sum2) {pd=false;break;}
			}
		}
		if(!pd) printf("0\n");
		else{
			if(las==-1) printf("%d\n",mi(2,Sum1-Sum3+1));
			else printf("%d\n",mi(2,Sum1-Sum3));
		}
		return 0;
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(s[i][j]!='?'){
				a[i]=(a[i]^(s[i][j]-'0'));
				a[n+j]=(a[n+j]^(s[i][j]-'0'));
			}
			else B[i].push_back(n+j),B[n+j].push_back(i);
		}
	
	memset(bk,true,sizeof(bk));
	bool pd=true;
	int Sum1=0,Sum3=0,las=-1;
	for(int i=1;i<=n+m;i++){
		if(bk[i]){
			Cnt=tot=0;
			dfs(i);
			int Sum=0;
			for(int j=1;j<=tot;j++){
				Sum=(Sum^a[sta[j]]);
			}
			if(tot%2==1){
				if(las==-1) las=Sum;
				else if(las!=Sum) {pd=false;break;}
			}
			else if(Sum) {pd=false;break;}
			Sum1=Sum1+Cnt/2;
			if(Cnt) Sum3=Sum3+tot-1;
		}
	}
	
	if(!pd) printf("0\n");
	else{
		if(las==-1) printf("%d\n",mi(2,Sum1-Sum3+1));
		else printf("%d\n",mi(2,Sum1-Sum3));
	}
	
	return 0;
}