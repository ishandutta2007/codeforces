#include<stdio.h>
#include<map>
#include<set>
#include<queue>
#include<vector> 
#include<string>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
#define seg pair<pii,pii>
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define rank Rank
using namespace std;
typedef long long LL;
int main()
{
	int n;
	LL k;
	scanf("%d %I64d",&n,&k);
	LL a[105];
	set<LL> s;
	for(int i=0;i<n;i++){
		scanf("%I64d",&a[i]);
		for(int j=1;j<33000;j++){
			if(a[i]%j==0){
				s.insert(a[i]/j);
			}
			else{
				s.insert(a[i]/j+1);
			}
		}
	}
	for(int i=1;i<33000;i++)
	s.insert(i);
	LL ans=1;
	for(set<LL>::iterator it=s.begin();it!=s.end();it++){
		LL sum=0,sumk=0;
		for(int i=0;i<n;i++){
			if(a[i]%(*it)==0){
				sum+=a[i]/(*it);
			}
			else{
				sum+=a[i]/(*it)+1;
				sumk+=(*it)-a[i]%(*it);
			}
		}
		if(sumk<=k){
			ans=max(ans,*it+(k-sumk)/sum);
		}
	}
	printf("%I64d\n",ans);
}
/* 4 9 6 3 7 8 8 2 9 1
/* 0 7 1 7 7*/