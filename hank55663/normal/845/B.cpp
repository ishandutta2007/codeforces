#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
using namespace std;
int main(){
	char c[10];
	scanf("%s",c);
	int sum1=0,sum2=0;
	for(int i=0;i<3;i++){
		sum1+=c[i];
	} 
	for(int i=3;i<6;i++){
		sum2+=c[i];
	}
	if(sum1==sum2){
		printf("0\n");
	}
	else{
		if(sum1>sum2){
			for(int i=0;i<3;i++)
			swap(c[i],c[i+3]);
			swap(sum1,sum2); 
		}
		sort(c,c+3);
		sort(c+3,c+6);
		reverse(c+3,c+6);
		int ans=0;
		int sum=0;
		for(int i=0,j=3;i<3&&j<6;){
			if(c[j]-'0'>'9'-c[i]){
				sum+=c[j]-'0',j++;
			}
			else
			sum+='9'-c[i],i++;
			ans++;
			if(sum+sum1>=sum2)
			break;
		}/* 
		sum=0;
		for(int i=3;i<6;i++){
			sum+=c[i]-'0';
			if(sum2-sum<=sum1){
				ans=min(ans,i+1);
				break;
			}
		}*/
		printf("%d\n",ans);
	}
}
/*
14%20,15#17
20,14-18
1#5,11,4%10,14-18,20,21
11,21,20,14-18,4%10,1#5

*/