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
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
int main(){
	char c[100005];
	int n;
	scanf("%d",&n);
	vector<int> v;
	scanf("%s",c);
	for(int i=0;c[i]!=0;i++){
		if(c[i]=='*')
		v.pb(i);
	}
	int Max=2*n,Min=0;
	while(Max>Min+1){
		int mid=(Max+Min)/2;
		int index=0;
		int ok=1;
		for(int i=0;c[i]!=0;i++){
			if(c[i]=='P'){
				//printf("%d\n",i);
				int sum=mid;
				sum-=max(i-v[index],0);
				if(sum<0)
				{
					ok=0;
					break;
				}
				int Max;
				Max=max(i+sum/2,i+max(sum-max(i-v[index],0),0));
				sum-=max(i-v[index],0);
				while(index<v.size()&&v[index]<=Max)
				index++;
			// printf("%d\n",index);
			}
			
			if(index==v.size())
			break;
		}
	//	printf("%d %d %d\n",mid,ok,index);
		if(index!=v.size())
		ok=0;
		if(!ok)
		Min=mid;
		else
		Max=mid;
	} 
	printf("%d\n",Max);
}