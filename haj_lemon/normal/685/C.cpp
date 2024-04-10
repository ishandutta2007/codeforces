#include<bits/stdc++.h>
#define ll long long
#define N 100010
#define INF 3000000000000000000ll
using namespace std;
int t,n;
struct Info{ll x,y,z;}a[N],ans;
ll b[5][3],c[5][3];
Info ch1(int x){
	for (int i=0;i<=3;i++)c[i][0]=b[i][0],c[i][1]=b[i][1];
	for (int i=0;i<=3;i++){
		if (((c[i][0]%2)+2)%2!=x)c[i][0]++;
		if (((c[i][1]%2)+2)%2!=x)c[i][1]--;
		if (c[i][0]>c[i][1])return (Info){INF+1,0ll,0ll};
	}
	if (c[1][0]+c[2][0]+c[3][0]>c[0][1]||c[1][1]+c[2][1]+c[3][1]<c[0][0]) return (Info){INF+1,0ll,0ll};
	Info y=(Info){c[1][0],c[2][0],c[3][0]};
	if (y.x+y.y+y.z<c[0][0])y.x+=min(c[1][1]-c[1][0],c[0][0]-(y.x+y.y+y.z));
	if (y.x+y.y+y.z<c[0][0])y.y+=min(c[2][1]-c[2][0],c[0][0]-(y.x+y.y+y.z));
	if (y.x+y.y+y.z<c[0][0])y.z+=min(c[3][1]-c[3][0],c[0][0]-(y.x+y.y+y.z));
	ll g=y.x+y.y+y.z;
	y.x=(g-y.x)/2;y.y=(g-y.y)/2;y.z=(g-y.z)/2;
	return y;
}
Info ch(ll x){
	for (int i=0;i<=3;i++)b[i][0]=-INF,b[i][1]=INF;
	for (int i=1;i<=n;i++){
		b[0][0]=max(b[0][0],a[i].x+a[i].y+a[i].z-x);b[0][1]=min(b[0][1],a[i].x+a[i].y+a[i].z+x);
		b[1][0]=max(b[1][0],-a[i].x+a[i].y+a[i].z-x);b[1][1]=min(b[1][1],-a[i].x+a[i].y+a[i].z+x);
		b[2][0]=max(b[2][0],a[i].x-a[i].y+a[i].z-x);b[2][1]=min(b[2][1],a[i].x-a[i].y+a[i].z+x);
		b[3][0]=max(b[3][0],a[i].x+a[i].y-a[i].z-x);b[3][1]=min(b[3][1],a[i].x+a[i].y-a[i].z+x);
	}
	if (ch1(0).x<=INF)return ch1(0);
	if (ch1(1).x<=INF)return ch1(1);
	return (Info){INF+1,0ll,0ll};
}
int main(){
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
		ll l=0,r=INF,mid;
		while (l<r){
			mid=(l+r)/2;ans=ch(mid);
			if (ans.x>INF) l=mid+1;else r=mid;
		}
		ans=ch(l);
		cout<<ans.x<<' '<<ans.y<<' '<<ans.z<<endl;
	}
	return 0;
}