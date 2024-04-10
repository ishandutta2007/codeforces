//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 300005
#define pi 3.14159265359
using namespace std;
typedef long long LL;
vector<int> v[4];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int w,c;
		scanf("%d %d",&w,&c);
		v[w].pb(c);
	}
	for(int i=1;i<=3;i++)
	sort(v[i].begin(),v[i].end()),reverse(v[i].begin(),v[i].end());
	LL sum1[N];
	MEM(sum1);
	for(int i=1;i<=v[1].size();i++){
		sum1[i]=sum1[i-1]+v[1][i-1];
	} 
	for(int i=v[1].size()+1;i<N;i++)
	sum1[i]=sum1[i-1];
	LL sum2[N];
	MEM(sum2);
	for(int i=1;i<=v[2].size();i++){
		sum2[i]=sum2[i-1]+v[2][i-1];
	} 
	for(int i=v[2].size()+1;i<N;i++)
	sum2[i]=sum2[i-1];
	LL ans=0;
	int sum=0;
	{
		int Max=min((int)v[2].size(),(m-sum)/2),Min=max(0,(int)(sum-v[1].size())/2);
		while(Max>Min+2){
			int mid1=(Max*2+Min)/3,mid2=(Max+Min*2)/3;
			LL ss1=sum2[mid1]+sum1[m-mid1*2],ss2=sum2[mid2]+sum1[m-mid2*2];
			if(ss1>ss2){
				Min=mid2;
			}
			else{
				Max=mid1;
			}
		}
		LL be=0;
		for(int i=Min;i<=Max;i++){
		//	printf("%d %d %d\n",i,sum2[i],sum1[m-i*2]);
			be=max(be,sum2[i]+sum1[m-i*2]);
		}
		ans=max(ans,be);
	}
	//printf("%d\n",ans);
	LL now=0;
	for(vector<int>::iterator it=v[3].begin();it!=v[3].end();it++){
		sum+=3;
		if(sum>m)
		break;
		now+=*it;
		int Max=(m-sum)/2,Min=0;
		while(Max>Min+2){
			int mid1=(Max*2+Min)/3,mid2=(Max+Min*2)/3;
			LL ss1=sum2[mid1]+sum1[m-sum-mid1*2],ss2=sum2[mid2]+sum1[m-sum-mid2*2];
			if(ss1>ss2){
				Min=mid2;
			}
			else{
				Max=mid1;
			}
		}
		LL be=0;
		for(int i=Min;i<=Max;i++){
			be=max(be,sum2[i]+sum1[m-sum-i*2]);
		}
		ans=max(ans,now+be);
	//	printf("%d\n",ans);
	}
	printf("%I64d\n",ans);
}