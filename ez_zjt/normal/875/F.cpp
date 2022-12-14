#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200010
using namespace std;

int n,m;
int f[MAXN],tag[MAXN];
pair<int,pair<int,int> > a[MAXN];

int getf(int x){
	if(f[x]==x) return x;
	return f[x]=getf(f[x]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].second.first,&a[i].second.second,&a[i].first);
	sort(a+1,a+m+1);
	for(int i=1;i<=n;i++) f[i]=i;
	int ans=0;
	for(int i=m;i>=1;i--){
		int x=a[i].second.first,y=a[i].second.second;
		if(getf(x)!=getf(y)){
			if(tag[f[x]] && tag[f[y]]) continue;
			bool temp=tag[f[x]] || tag[f[y]];
			f[f[x]]=f[y];
			tag[getf(x)]=temp;
			ans+=a[i].first;
		}else if(!tag[f[x]]){
			tag[f[x]]=1;
			ans+=a[i].first;
		}
	}
	printf("%d\n",ans);
}