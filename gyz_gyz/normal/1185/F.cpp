#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int inf=2e9+10;
int a[N],b[N],id[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n){int k,x=0;
		scanf("%d",&k);
		rep(j,1,k){int y;
			scanf("%d",&y);x|=1<<(y-1);
		}++a[x];
	}
	rep(i,0,8)rep(j,0,511)if(!(j&(1<<i)))a[j|(1<<i)]+=a[j];
	rep(i,0,511)b[i]=inf;
	int c1=inf,id1=0,c2=inf,id2=0;
	rep(i,1,m){int c,k,x=0;
		scanf("%d%d",&c,&k);
		if(c<c1)c2=c1,id2=id1,c1=c,id1=i;
		else if(c<c2)c2=c,id2=i;
		rep(j,1,k){int y;
			scanf("%d",&y);x|=1<<(y-1);
		}
		if(c<b[x])b[x]=c,id[x]=i;
	}
	int p=0,s=c1+c2,s1=id1,s2=id2;
	rep(i,0,511)if(id[i]){
		int C=c1,ID=id1;
		if(id[i]==ID)C=c2,ID=id2;
		if(a[i]>p||(a[i]==p&&b[i]+C<s)){
			p=a[i];s=b[i]+C;s1=id[i],s2=ID;
		}
	}
	rep(i,0,511)if(id[i])rep(j,i+1,511)if(id[j]){
		if(a[i|j]>p||(a[i|j]==p&&b[i]+b[j]<s)){
			p=a[i|j];s=b[i]+b[j];s1=id[i];s2=id[j];
		}
	}
	printf("%d %d\n",s1,s2);
}