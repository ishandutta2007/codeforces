#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+100;
int a[N],b[N],p1[N],p2[N];

bool cmp(int n1,int n2) {return (n1<n2);}
int mymin(int x,int y) {return (x<y?x:y);}
int mymax(int x,int y) {return (x>y?x:y);}

int main()
{
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	
	int tt=a[1]+b[1],las1=a[1],las2=b[1];
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+m+1,cmp);
	
	int id1,id2;
	for(int i=n;i>=1;i--)
		if(a[i]==las1) {id1=i;break;}
	for(int i=m;i>=1;i--)
		if(b[i]==las2) {id2=i;break;}
	
	int l=0,r=tt-1,ans=tt;ll lim=((ll)n*m+1)/2;
	while(l<=r){
		int mid=(l+r)>>1,id;
		
		id=m;
		for(int i=1;i<=n;i++){
			while(id&&a[i]+b[id]>mid) id--;
			p1[i]=id;
		}
		id=n;
		for(int i=1;i<=m;i++){
			while(id&&a[id]+b[i]>mid) id--;
			p2[i]=id;
		}
		
		id=0;ll Sum=0,Ans=0,Ans2;
		for(int i=1;i<=n;i++) Sum+=(m-p1[i]);
		for(int i=0;i<=n;i++){
			if(i){
				int t=mymin(id,p1[i])-(m-mymax(id,p1[i]));
				Sum+=t;
			}
			while(id<m){
				int t=-n+mymax(i,p2[id+1])+mymin(i,p2[id+1]);
				if(t>0) id++,Sum+=t;
				else break;
			}
			if(Ans<Sum) Ans=Sum;
		}
		
		Ans2=Sum=0;id=0;
		for(int i=1;i<=n;i++) Sum+=(m-p1[i]);Sum--;
		for(int i=0;i<=n;i++){
			if(i){
				int t=mymin(id,p1[i])-(m-mymax(id,p1[i]));
				if(i==id1&&id<id2) t++;
				Sum+=t;
			}
			while(id<m){
				int t=-n+mymax(i,p2[id+1])+mymin(i,p2[id+1]);
				if(id+1==id2&&i<id1) t++;
				if(t>0) id++,Sum+=t;
				else break;
			}
			if(Ans2<Sum) Ans2=Sum;
		}
		
		if(Ans2==Ans) ans=mid,r=mid-1;
		else l=mid+1;
	}
	
	printf("%d\n",ans);
	
	return 0;
}