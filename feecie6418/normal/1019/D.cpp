#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll S;
int n,m,p[2005],id[2005];
struct point{ll x,y;int i,j;}a[2005],b[2000005],c[2005];
ll Cross(point x,point y){return x.x*y.y-x.y*y.x;}
point operator -(point x,point y){return {x.x-y.x,x.y-y.y};}
bool operator <(const point &x,const point &y){return Cross(x,y)>0;}
int main(){
	cin>>n>>S,S*=2;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y,a[i].i=i,c[i]=a[i];
	sort(a+1,a+n+1,[](point x,point y){return x.x!=y.x?x.x<y.x:x.y<y.y;});
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)b[++m]=a[j]-a[i],b[m].i=a[i].i,b[m].j=a[j].i;
	sort(b+1,b+m+1);
	sort(a+1,a+n+1,[](point x,point y){return x.x!=y.x?x.x<y.x:x.y>y.y;});
	for(int i=1;i<=n;i++)id[a[i].i]=i,p[i]=a[i].i;
	for(int i=1;i<=m;i++){
		int x=b[i].i,y=b[i].j;
		swap(p[id[x]],p[id[y]]);
		swap(id[x],id[y]);
		int l=max(id[x],id[y])+1,r=n;
		while(l<=r){
			int mid=(l+r)/2,z=p[mid];
			ll ts=Cross(b[i],c[z]-c[x]);
			if(ts==S){
				puts("Yes");
				cout<<c[x].x<<' '<<c[x].y<<'\n';
				cout<<c[y].x<<' '<<c[y].y<<'\n';
				cout<<c[z].x<<' '<<c[z].y<<'\n';
				return 0;
			}
			if(ts>S)r=mid-1;
			else l=mid+1;
		}
	}
	puts("No");
}