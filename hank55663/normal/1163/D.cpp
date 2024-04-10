#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
using namespace std;
int dp[1005][55][55];
int fs[55];
int ft[55];
void KMP(char *c,int *f){
	f[0]=-1;
	int j=-1;
	for(int i = 1;c[i]!=0;i++){
		while(j!=-1&&c[i]!=c[j+1])j=f[j];
		if(c[i]==c[j+1])j++;
		f[i]=j;
	}
}
int main(){
	char c[1005];
	scanf("%s",c);
	char s[55];
	scanf("%s",s);
	char t[55];
	scanf("%s",t);
	KMP(s,fs);
	KMP(t,ft);
	for(int i = 0;i<1005;i++){
		for(int j = 0;j<55;j++)
			for(int k=0;k<55;k++)
				dp[i][j][k]=-1e9;
	}
	dp[0][0][0]=0;
	for(int i = 0;c[i]!=0;i++){
		for(int j = 0;s[j]!=0;j++)
			for(int k = 0;t[k]!=0;k++){
				if(c[i]=='*'){
					for(char cc='a';cc<='z';cc++){
						c[i]=cc;
						int tempj=j-1;
						while(tempj!=-1&&c[i]!=s[tempj+1]){
							tempj=fs[tempj];
						}
						if(c[i]==s[tempj+1]){
							tempj++;
						}
						int tempk=k-1;
						while(tempk!=-1&&c[i]!=t[tempk+1]){
							tempk=ft[tempk];
						}
						if(c[i]==t[tempk+1]){
							tempk++;
						}
						int add=0;
						if(s[tempj+1]==0){
							add++;
							tempj=fs[tempj];
						}
						if(t[tempk+1]==0){
							add--;
							tempk=ft[tempk];
						}
						dp[i+1][tempj+1][tempk+1]=max(dp[i+1][tempj+1][tempk+1],dp[i][j][k]+add);
						c[i]='*';
					}
				}
				else{
					int tempj=j-1;
					while(tempj!=-1&&c[i]!=s[tempj+1]){
						tempj=fs[tempj];
					}
					if(c[i]==s[tempj+1]){
						tempj++;
					}
					int tempk=k-1;
					while(tempk!=-1&&c[i]!=t[tempk+1]){
						tempk=ft[tempk];
					}
					if(c[i]==t[tempk+1]){
						tempk++;
					}
					int add=0;
					if(s[tempj+1]==0){
						add++;
						tempj=fs[tempj];
					}
					if(t[tempk+1]==0){
						add--;
						tempk=ft[tempk];
					}
					dp[i+1][tempj+1][tempk+1]=max(dp[i+1][tempj+1][tempk+1],dp[i][j][k]+add);
				}
			}
	}
	int ans=-1e9;
	int len=strlen(c);
	for(int i = 0;s[i]!=0;i++)
		for(int j =0;t[j]!=0;j++){
			ans=max(ans,dp[len][i][j]);
		}
	printf("%d\n",ans);
	return 0;
}
/*




*/