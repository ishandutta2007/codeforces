#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int y[60][60];
int t[60][60];
int main(){
	long long a;
	scanf("%I64d",&a);
	for(int i=0;i<23;i++){
		t[i*2+2][i*2]=t[i*2+2][i*2+1]=1;
		y[i*2+1][i*2+2]=1;
		int f=a%6;
	//	printf("%d",f);
		y[i*2][i*2+2+f]=1;
	//	if(i==22)break;
		for(int j=0;j<7;j++){
			if(i*2+3+j<49)t[i*2+1][i*2+3+j]=1;
		}
		if(i==22){
			if(f==4){
				y[i*2][i*2+2+2]=1;
				t[i*2+1][48]=0;
			}else if(f==5){
				t[i*2+1][48]=0;
			}
		}
		y[i*2+1][i*2+10]=1;
		y[i*2+2][i*2+10]=1;
		a/=6;
	}
	//printf("%d\n",(int)a);
	if(!a)y[46][46]=1;
	//printf("\n");
	printf("47 50\n");
	vector<pair<pair<int,int>,pair<int,int> > >ans;
	for(int i=0;i<60;i++)for(int j=0;j<60;j++){
		if(i+1<47&&j<50&&t[i][j])ans.push_back(make_pair(make_pair(i+1,j+1),make_pair(i+2,j+1)));
		if(i<47&&j+1<50&&y[i][j])ans.push_back(make_pair(make_pair(i+1,j+1),make_pair(i+1,j+2)));
		
	}
	printf("%d\n",(int)(ans.size()));
	for(int i=0;i<ans.size();i++){
		printf("%d %d %d %d\n",ans[i].first.first,ans[i].first.second,ans[i].second.first,ans[i].second.second);
	}
}