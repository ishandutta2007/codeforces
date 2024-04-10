#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	char c[105][105];
	memset(c,0,sizeof(c));
	for(int i = 1;i<=n;i++){
		scanf("%s",c[i]+1);
	}
	int ans=0;
	int ansx=1,ansy=1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(c[i][j]=='.'){
				int sum1=0,sum2=0,tot=0;
				for(int k = j;k>0;k--){
					if(c[i][k]=='.')
						sum1++;
					else
						break;
				}
				for(int k = j+1;k<=n;k++){
					if(c[i][k]=='.')
						sum2++;
					else
						break;
				}
				sum1=min(sum1,k);
				sum2=min(sum2,k-1);
				tot+=max(sum1+sum2-k+1,0);
				sum1=sum2=0;
				for(int k = i;k>0;k--){
					if(c[k][j]=='.')
						sum1++;
					else
						break;
				}
				for(int k = i+1;k<=n;k++){
					if(c[k][j]=='.')
						sum2++;
					else
						break;
				}
				sum1=min(sum1,k);
				sum2=min(sum2,k-1);
				tot+=max(sum1+sum2-k+1,0);
				if(tot>ans){
					ans=tot;
					ansx=i;
					ansy=j;
				}
			//	printf("%d ",tot);
			}
		//	else
			//	printf("0 ");
		}
	//	printf("\n");
	}
	printf("%d %d\n",ansx,ansy);
}