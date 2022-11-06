#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
int m,n,ne[N][28],dp[252][252][252],si[N],a[252][4],x;
string s;
char ch1,ch2;
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n>>m;cin>>s;
	for (int i=0;i<26;i++)ne[n][i]=ne[n+1][i]=n+1;
	for (int i=n-1;i>=0;i--){
		for (int j=0;j<26;j++) ne[i][j]=ne[i+1][j];
		ne[i][s[i]-'a']=i+1;
	}
	for (int i=0;i<=250;i++)
		for (int j=0;j<=250;j++)
			for (int k=0;k<=250;k++) dp[i][j][k]=n+1;
	dp[0][0][0]=0;
	while (m--){
		cin>>ch1>>x;
		if (ch1=='+'){
			cin>>ch2;
			if (x==1){
				si[1]++;a[si[1]][1]=ch2-'a';
				for (int i=si[1]-1;i<si[1];i++)
					for (int j=0;j<=si[2];j++)
						for (int k=0;k<=si[3];k++)dp[i+1][j][k]=min(dp[i+1][j][k],ne[dp[i][j][k]][a[i+1][1]]);
				for (int i=si[1];i<=si[1];i++){
					for (int j=0;j<=si[2];j++){
						for (int k=0;k<=si[3];k++){
							if (j!=si[2])dp[i][j+1][k]=min(dp[i][j+1][k],ne[dp[i][j][k]][a[j+1][2]]);
							if (k!=si[3])dp[i][j][k+1]=min(dp[i][j][k+1],ne[dp[i][j][k]][a[k+1][3]]);
						}
					}
				}
			}
			if (x==2){
				si[2]++;a[si[2]][2]=ch2-'a';
				for (int i=0;i<=si[1];i++)
					for (int j=si[2]-1;j<si[2];j++)
						for (int k=0;k<=si[3];k++)dp[i][j+1][k]=min(dp[i][j+1][k],ne[dp[i][j][k]][a[j+1][2]]);
				for (int i=0;i<=si[1];i++){
					for (int j=si[2];j<=si[2];j++){
						for (int k=0;k<=si[3];k++){
							if (i!=si[1])dp[i+1][j][k]=min(dp[i+1][j][k],ne[dp[i][j][k]][a[i+1][1]]);
							if (k!=si[3])dp[i][j][k+1]=min(dp[i][j][k+1],ne[dp[i][j][k]][a[k+1][3]]);
						}
					}
				}
			}
			if (x==3){
				si[3]++;a[si[3]][3]=ch2-'a';
				for (int i=0;i<=si[1];i++)
					for (int j=0;j<=si[2];j++)
						for (int k=si[3]-1;k<si[3];k++)dp[i][j][k+1]=min(dp[i][j][k+1],ne[dp[i][j][k]][a[k+1][3]]);
				for (int i=0;i<=si[1];i++){
					for (int j=0;j<=si[2];j++){
						for (int k=si[3];k<=si[3];k++){
							if (i!=si[1])dp[i+1][j][k]=min(dp[i+1][j][k],ne[dp[i][j][k]][a[i+1][1]]);
							if (j!=si[2])dp[i][j+1][k]=min(dp[i][j+1][k],ne[dp[i][j][k]][a[j+1][2]]);
						}
					}
				}
			}
		}else{
			int l1=0,r1=si[1],l2=0,r2=si[2],l3=0,r3=si[3];
			if (x==1){l1=si[1];si[1]--;}
			if (x==2){l2=si[2];si[2]--;}
			if (x==3){l3=si[3];si[3]--;}
			for (int i=l1;i<=r1;i++)
				for (int j=l2;j<=r2;j++)
					for (int k=l3;k<=r3;k++)dp[i][j][k]=n+1;
		}
		if (dp[si[1]][si[2]][si[3]]==n+1) puts("NO");else puts("YES");
//		for (int i=0;i<=si[1];i++){
//			for (int j=0;j<=si[2];j++){
//				for (int k=0;k<=si[3];k++) cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
//			}
//		}
	}
	return 0;
}