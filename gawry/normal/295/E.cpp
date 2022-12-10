#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
using namespace std;
const int POWER=1<<18;
const int MAX=410000;
int n,m,x[MAX],t[MAX],a[MAX],b[MAX],cur[MAX];
vector<int> s;
long long cnt[2*POWER],sum[2*POWER],res[2*POWER];
void update(int x,int v){
	int pos=lower_bound(s.begin(),s.end(),x)-s.begin();
	assert(s[pos]==x);
	x=pos;
//cout<<x<<" <- "<<v<<endl;
	x+=POWER;
	cnt[x]=v;
	sum[x]=v?s[x-POWER]:0;
	res[x]=0;
	while(x/=2){
		sum[x]=sum[2*x]+sum[2*x+1];
		cnt[x]=cnt[2*x]+cnt[2*x+1];
		res[x]=res[2*x]+res[2*x+1]-sum[2*x]*cnt[2*x+1]+cnt[2*x]*sum[2*x+1];
	}
}
long long get_sum(int x0,int x1){
	x0=lower_bound(s.begin(),s.end(),x0)-s.begin();
	x1=upper_bound(s.begin(),s.end(),x1)-s.begin()-1;
//cout<<x0<<" , "<<x1<<endl;
	if(x1<=x0)return 0;
	x0+=POWER;
	x1+=POWER;
	long long ans=0,left_cnt=cnt[x0],left_sum=sum[x0],right_cnt=cnt[x1],right_sum=sum[x1];
//ans=0;
//for(int i=x0;i<x1;i++)for(int j=i+1;j<=x1;j++)if(cnt[i]&&cnt[j])ans+=sum[j]-sum[i];
//return ans;
//for(int i=x0;i<=x1;i++)printf("%d",cnt[i]);puts("");
	while(x0+1<x1){
		if(x0%2==0){
			ans-=left_sum*cnt[x0+1];
			ans+=left_cnt*sum[x0+1];
			ans+=res[x0+1];
			left_sum+=sum[x0+1];
			left_cnt+=cnt[x0+1];
		}
		if(x1%2){
			ans+=right_sum*cnt[x1-1];
			ans-=right_cnt*sum[x1-1];
			ans+=res[x1-1];
			right_sum+=sum[x1-1];
			right_cnt+=cnt[x1-1];
		}
		x0/=2;
		x1/=2;
	}
	ans-=left_sum*right_cnt;
	ans+=left_cnt*right_sum;
	return ans;
}
main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&x[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d %d %d",&t[i],&a[i],&b[i]);
	for(int i=1;i<=n;i++)cur[i]=x[i];
	for(int i=1;i<=n;i++)s.push_back(cur[i]);
	for(int i=1;i<=m;i++)if(t[i]==1){
		cur[a[i]]+=b[i];
		s.push_back(cur[a[i]]);
	}
	sort(s.begin(),s.end());
	s.erase(unique(s.begin(),s.end()),s.end());
	//for(int i=0;i<s.size();i++)cout<<s[i]<<",";cout<<endl;
	for(int i=1;i<=n;i++)cur[i]=x[i];
	for(int i=1;i<=n;i++)update(cur[i],1);
	for(int i=1;i<=m;i++)if(t[i]==1){
		update(cur[a[i]],0);
		cur[a[i]]+=b[i];
		update(cur[a[i]],1);
	}else{
		printf("%I64d\n",get_sum(a[i],b[i]));
	}
}