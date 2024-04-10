#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
const ll inf=1e18;
struct P{
	int x,y,id;
}a[100005];
int n,is[100005],is1[100005];
int main(){
	scanf("%d",&n);
	ll sum=0;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i;
	if(n%2==0){
		sort(a+1,a+n+1,[](P x,P y){return x.x<y.x;});
		int v1=0,v2=0;
		for(int i=1;i<=n/2;i++)is[a[i].id]^=1;
		v1=a[n/2+1].x-a[n/2].x;
		for(int i=1;i<=n;i++)sum+=(i<=n/2?-1:1)*a[i].x;
		sort(a+1,a+n+1,[](P x,P y){return x.y<y.y;});
		for(int i=1;i<=n/2;i++)is[a[i].id]^=1;
		v2=a[n/2+1].y-a[n/2].y;
		for(int i=1;i<=n;i++)sum+=(i<=n/2?-1:1)*a[i].y;
		if(*max_element(is+1,is+n+1)!=0&&*min_element(is+1,is+n+1)!=1)sum-=min(v1,v2);
	}
	else {
		sort(a+1,a+n+1,[](P x,P y){return x.x<y.x;});
		int m1=a[(n+1)/2].id,v1=0,v2=0;
		for(int i=1;i<=n/2;i++)is[a[i].id]^=1,is1[a[i].id]^=1;
		v1=min(a[n/2+1].x-a[n/2].x,a[n/2+2].x-a[n/2+1].x);
		for(int i=1;i<=n;i++)sum+=(i<=n/2?-1:(i>n/2+1?1:0))*a[i].x;
		sort(a+1,a+n+1,[](P x,P y){return x.y<y.y;});
		int m2=a[(n+1)/2].id;
		for(int i=1;i<=n/2;i++)is[a[i].id]^=1;
		for(int i=n/2+2;i<=n;i++)is1[a[i].id]^=1;
		v2=min(a[n/2+1].y-a[n/2].y,a[n/2+2].y-a[n/2+1].y);
		for(int i=1;i<=n;i++)sum+=(i<=n/2?-1:(i>n/2+1?1:0))*a[i].y;
		if(m1==m2&&*max_element(is+1,is+n+1)!=0&&*max_element(is1+1,is1+n+1)!=0)sum-=min(v1,v2);
	}
	cout<<2*sum;
}