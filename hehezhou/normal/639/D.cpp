#include<bits/stdc++.h>
using namespace std;
struct data{
	public:
	long long k,t;
	bool operator<(const data b)const{
		return k<b.k;
	}
}a[5][200010];
long long b,c;
long long n,k;
long long ans=0x7fffffffffffffff;
class Cmp{
	public:
	bool operator() (data ad,data bd){
		return (bd.k-ad.k)/5*b+ad.t<bd.t;
	}
};
int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&k,&b,&c);
	b=min(b,5*c);
	for(int i=1;i<=n;i++){
		long long now;
		scanf("%I64d",&now);
		for(int j=0;j<5;j++)a[((now+j)%5+5)%5][i].k=now+j,a[((now+j)%5+5)%5][i].t=c*j;
	}
	for(int i=0;i<5;i++)sort(a[i]+1,a[i]+1+n);
	for(int m=0;m<5;m++){
		priority_queue<data,vector<data>,Cmp>pq;
		long long sum1=0,sum2=0;
		for(int i=1;i<=k;i++)pq.push(a[m][i]),sum1+=a[m][i].k,sum2+=a[m][i].t;
		ans=min(ans,sum2+(a[m][k].k*k-sum1)/5*b);
		for(int i=k+1;i<=n;i++){
			sum1-=pq.top().k,sum2-=pq.top().t;
			pq.pop();
			pq.push(a[m][i]),sum1+=a[m][i].k,sum2+=a[m][i].t;
			ans=min(ans,sum2+(a[m][i].k*k-sum1)/5*b);
		}
	}
	return printf("%I64d",ans),0;
}