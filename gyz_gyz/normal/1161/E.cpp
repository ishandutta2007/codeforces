#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
int a[N],c[N];char s[N];bool eq[N];
void sol(){int n,tot=1;
	scanf("%d",&n);a[1]=1;
	if(n/2){
		printf("Q %d",n/2);
		rep(i,1,n/2*2)printf(" %d",i);
		printf("\n");fflush(stdout);
		scanf("%s",s+1);
		rep(i,1,n/2)if(s[i]=='0')a[++tot]=i*2;
	}
	if((n-1)/2){
		printf("Q %d",(n-1)/2);
		rep(i,2,(n-1)/2*2+1)printf(" %d",i);
		printf("\n");fflush(stdout);
		scanf("%s",s+1);
		rep(i,1,(n-1)/2)if(s[i]=='0')a[++tot]=i*2+1;
	}
	sort(a+1,a+tot+1);int cnt=0;
	rep(i,3,tot)if((i-1)%4>1)++cnt;
	if(cnt){
		printf("Q %d",cnt);
		rep(i,3,tot)if((i-1)%4>1)printf(" %d %d",a[i-2],a[i]);
		printf("\n");fflush(stdout);
		scanf("%s",s+1);cnt=0;
		rep(i,3,tot)if((i-1)%4>1){
			if(s[++cnt]=='1')eq[i]=1;else eq[i]=0;
		}
	}cnt=0;
	rep(i,5,tot)if((i-1)%4<2)++cnt;
	if(cnt){
		printf("Q %d",cnt);
		rep(i,5,tot)if((i-1)%4<2)printf(" %d %d",a[i-2],a[i]);
		printf("\n");fflush(stdout);
		scanf("%s",s+1);cnt=0;
		rep(i,5,tot)if((i-1)%4<2){
			if(s[++cnt]=='1')eq[i]=1;else eq[i]=0;
		}
	}
	a[tot+1]=n+1;
	vector<int>r[3];
	rep(i,1,tot){
		if(eq[i])c[a[i]]=c[a[i-2]];
		else if(i<3)c[a[i]]=i-1;
		else c[a[i]]=3-c[a[i-2]]-c[a[i-1]];
		r[c[a[i]]].push_back(a[i]);
		rep(j,a[i]+1,a[i+1]-1){
			c[j]=c[a[i]];
			r[c[j]].push_back(j);
		}
	}
	printf("A %d %d %d\n",(int)r[0].size(),(int)r[1].size(),(int)r[2].size());
	rep(i,0,2){
		for(auto&j:r[i])printf("%d ",j);
		printf("\n");
	}fflush(stdout);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}