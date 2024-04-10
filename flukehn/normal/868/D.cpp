#include<bits/stdc++.h>
using namespace std;
const int MAXN=210,MAXM=30;
typedef long long ll;
int n,m;
int fst=16;
char s[MAXN];
char sl[MAXN][MAXM],sr[MAXN][MAXM];
int fuckl[MAXN],fuckr[MAXN];
bool sftre[MAXN][17][66536];
int K[MAXN];
int rem[MAXN][17];
ll T;
int main(){
	int i,j,k,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",s+1);
		int l=strlen(s+1);
		for(j=1;j<=fst&&j<=l;j++){
			sl[i][++fuckl[i]]=s[j];
		}
		for(j=max(1,l-fst+1);j<=l;j++){
			sr[i][++fuckr[i]]=s[j];
		}
		for(k=1;k<=fst;k++){
			rem[i][k]=1<<k;
		}
		for(k=1;k<=fst&&k<=l;k++){
			int acac=0;
			for(j=1;j<k;j++){
				acac<<=1;
				acac|=s[j]-'0';
			}
			for(;j<=l;j++){
				acac<<=1;
				acac|=s[j]-'0';
				acac&=(1<<k)-1;
				if(!sftre[i][k][acac]){
					rem[i][k]--;
				}
				sftre[i][k][acac]=1;
			}
		}
	}
	scanf("%d",&m);
	while(m--){
		n++;
		scanf("%d%d",&x,&y);
		for(i=1;i<=fuckl[x];i++){
			s[i]=sl[x][i];
		}
		for(i=1;i<=fuckl[y];i++){
			s[fuckl[x]+i]=sl[y][i];
		}
		for(i=1;i<=fuckl[x]+fuckl[y]&&i<=fst;i++){
			sl[n][++fuckl[n]]=s[i];
		}
		int t=0;
		for(i=fuckr[y];i;i--){
			s[++t]=sr[y][i];
		}
		for(i=fuckr[x];i;i--){
			s[++t]=sr[x][i];
		}
		for(i=1;i<=fuckr[x]+fuckr[y]&&i<=fst;i++){
			sr[n][++fuckr[n]]=s[i];
		}
		for(i=1;i<=fuckr[n]/2;i++){
			swap(sr[n][i],sr[n][fuckr[n]-i+1]);
		}
		for(i=1;i<=fuckr[x];i++){
			s[i]=sr[x][i];
		}
		for(i=1;i<=fuckl[y];i++){
			s[fuckr[x]+i]=sl[y][i];
		}
		for(k=1;k<=fst;k++){
			rem[n][k]=1<<k;
			for(j=0;j<(1<<k);j++){
				T++;
				sftre[n][k][j]=sftre[x][k][j]|sftre[y][k][j];
				if(sftre[n][k][j]){
					rem[n][k]--;
				}
			}
			if(k<=fuckr[x]+fuckl[y]){
				int acac=0;
				for(j=1;j<k;j++){
					acac<<=1;
					acac|=s[j]-'0';
				}
				for(;j<=fuckr[x]+fuckl[y];j++){
					T++;
					acac<<=1;
					acac|=s[j]-'0';
					acac&=(1<<k)-1;
					if(!sftre[n][k][acac]){
						rem[n][k]--;
					}
					sftre[n][k][acac]=1;
				}
			}
		}
		int tret=0;
		for(i=1;i<=fst;i++){
			if(!rem[n][i]){
				tret=i;
			}
		}
		printf("%d\n",tret);
	}
	return 0;
}