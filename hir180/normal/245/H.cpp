#include <cstdio>
#include <cstring>
using namespace std;
int dp[5001][5001]={};
bool same[5001][5001]={},kaibun[5001][5001]={};
bool allsame=true;
int now=0;
bool a=false;
char str[5001];
int main(){
	scanf("%s",str);
	int length=strlen(str);
	for(int i=0;i<length-1;i++){
		if(str[i]==str[i+1]){
			if(allsame){
			for(int j=now;j<=i+1;j++){
				kaibun[j][i+1]=true;
			}
			}else{
				allsame=true;
				now=i;
			}
		}else{
			allsame=false;
		}
	}
	for(int i=0;i<length;i++){
		for(int j=i;j<length;j++){
			if(!kaibun[i][j-1]){
				if((j-i)%2==0){
					for(int k=i;k<(j+i)/2;k++){
						if(str[k]!=str[i+j-k]){
							a=true;
							break;
						}
					}
					if(!a){
						kaibun[i][j]=true;
						kaibun[j][i]=true;
					}
					a=false;
				}else{
					for(int k=i;k<=(j+i)/2;k++){
						if(str[k]!=str[i+j-k]){
							a=true;
							break;
						}
					}
					if(!a){
						kaibun[i][j]=true;
						kaibun[j][i]=true;
					}
					a=false;
				}
			}
		}
	}
	for(int i=0;i<length;i++){
		dp[i][i]=1;
	}
	for(int i=0;i<length-1;i++){
		if(str[i]==str[i+1]){
			dp[i][i+1]=3;
		}else{
			dp[i][i+1]=2;
		}
	}
	for(int i=2;i<length;i++){
		for(int j=0;j<length-i;j++){
			if(kaibun[j][j+i]){
				dp[j][j+i]=dp[j+1][j+i]+dp[j][j+i-1]-dp[j+1][j+i-1]+1;
			}else{
				dp[j][j+i]=dp[j+1][j+i]+dp[j][j+i-1]-dp[j+1][j+i-1];
			}
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",dp[a-1][b-1]);
	}
	return 0;
}