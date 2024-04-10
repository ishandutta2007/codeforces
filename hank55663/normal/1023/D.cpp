#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
	int l[200005],r[200005];
	int n,q;
	scanf("%d %d",&n,&q);
	fill(l,l+q+1,1e9);
	fill(r,r+q+1,-1);
	int ori[200005];
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		ori[i]=a;
		l[a]=min(l[a],i);
		r[a]=max(r[a],i+1);
	}
//	printf("!\n");
	int a[200005];
	pii p[400005];
	int now=0;
	for(int i=2;i<=q;i++){
		if(l[i]!=1e9)
		p[now++]=mp(l[i],i);
	//	printf("%d\n",now);
	}
	//printf("%d\n",now);
	for(int i=2;i<=q;i++){
		if(r[i]!=-1)
		p[now++]=mp(r[i],-i);
	}
//	printf("%d\n",now);
	sort(p,p+now);
	set<int> s;
	s.insert(1);
	int k=0;
	for(int i=0;i<n;i++){
		while(k!=now&&p[k].x==i){
			if(p[k].y>0)
			s.insert(p[k].y);
			else
			s.erase(-p[k].y);
			k++;
		}
	//	printf("?\n");
		a[i]=*s.rbegin();
	//	printf("%d\n",a[i]);
	}
	for(int i=0;i<n;i++){
		if(ori[i]!=a[i]&&ori[i]!=0){
			printf("NO\n");
			return 0;
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]==0)
		a[i]=a[i-1];
	}
	for(int i=n-2;i>=0;i--){
		if(a[i]==0)
		a[i]=a[i+1];
	}
	int Max=0;
	for(int i=0;i<n;i++){
		if(a[i]==q)
			Max=1;
	}
	if(!Max){
		for(int i=0;i<n;i++){
			if(ori[i]==0){
				a[i]=q;
				printf("YES\n");
				for(int j=0;j<n;j++)
				printf("%d ",a[j]);
				printf("\n");
				return 0;
			}
		}
		printf("NO\n");
	}
	else{
		printf("YES\n");
		for(int j=0;j<n;j++)
		printf("%d ",a[j]);
		printf("\n");
	}

}