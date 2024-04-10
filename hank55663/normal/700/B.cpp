#include<bits/stdc++.h>
using namespace std;
bool uni[200005];
int wei[200005];
vector<int> v[200005]; 
int N,k;
int dfs(int n,int f){
	int sum=0;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(*it!=f){
			int a=dfs(*it,n);
			sum+=a;
		}
	}
	wei[n]=sum;
	sum+=uni[n];
	if(sum>k/2)
	sum=k-sum,k=sum*2;
	return sum;
}
int main(void)
{
   scanf("%d %d",&N,&k);
   k*=2;
   for(int i=1;i<=N;i++)
   uni[i]=false;
   for(int i=0;i<k;i++)
   {
   	int a;
   	scanf("%d",&a);
   	uni[a]=true;
   }
   memset(wei,0,sizeof(wei));
   for(int i=1;i<N;i++){
   	int a,b;
   	scanf("%d %d",&a,&b);
   	v[a].push_back(b);
   	v[b].push_back(a);
   }
   dfs(1,0);
   long long int ans=0;
   for(int i=1;i<=N;i++)
   ans+=wei[i];
   printf("%I64d\n",ans);
}