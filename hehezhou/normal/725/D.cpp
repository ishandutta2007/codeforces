#include<bits/stdc++.h>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> >q;
int nowans,n,nowt,ans;
struct team{
	long long w,t;
	bool operator<(const team& b)const{
		return t>b.t;
	}
}a[300010];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&a[i].t,&a[i].w);
		if(i&&a[i].t>a[i].w)n--,i--;
	}
	sort(a+1,a+n);
	for(nowt=1,nowans=1,ans=n;;){
		while(nowt<=n&&a[nowt].t>a[0].t)q.push(a[nowt].w-a[nowt].t+1),nowt++,nowans++;
		if(q.empty())return puts("1"),0;
		ans=min(nowans,ans);
		if(q.top()<=a[0].t)a[0].t-=q.top(),q.pop(),nowans--;
		else break;
	}
	return printf("%d\n",ans),0;
}