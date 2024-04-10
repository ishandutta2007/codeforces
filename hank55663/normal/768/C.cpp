#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stack> 
#include<set>
#include<map>
#include<iostream>
#include <iomanip>
#include<assert.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define pi 3.14159265359
typedef long long LL;
using namespace std;
const int mod = 1e9+7;
int main(){
	int n,k,x;
	scanf("%d %d %d",&n,&k,&x);
	int count[1025];
	memset(count,0,sizeof(count));
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		count[a]++;
	}
	int num=0;
	int count2[1025];
	for(int i=0;i<k;i++){
		num=0;
	//	printf("%d\n",i);
		memset(count2,0,sizeof(count2));
		for(int j=0;j<1024;j++){
		//	printf("%d %d\n",j,j^x);
			count2[j^x]+=count[j]/2;
			count2[j]+=count[j]/2;
			if(count[j]%2!=0){
				if(num%2==0)
				count2[j^x]++;
				else
				count2[j]++;
				num++;
			}
		}
		for(int j=0;j<1024;j++){
			count[j]=count2[j];
		}
	}
	for(int i=1023;i>=0;i--)
	{
		if(count[i]!=0){
			printf("%d ",i);
			break;
		}
	}
	for(int i=0;i<1024;i++){
		if(count[i]!=0){
			printf("%d\n",i);
			break;
		}
	}
}