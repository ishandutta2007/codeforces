#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define pb push_back

const int st=5005;
vector<int> w[st];
int n,z,t[st];
int ile;
vector<vector<int> > prze;
int start[st];
vector<int> pom;
int tab[st];

int main()
{
	scanf("%d%d",&n,&z);
	while(z--){
		int rodz;
		scanf("%d",&rodz);
		if(rodz==1){
			int l,r,d;
			scanf("%d%d%d",&l,&r,&d);
			for(int i=l;i<=r;++i)
				t[i]+=d;
		}
		else{
			int l,r,m;
			scanf("%d%d%d",&l,&r,&m);
			for(int i=l;i<=r;++i)w[i].pb(m-t[i]);
			for(int i=l;i<=r;++i)pom.pb(m-t[i]);
			start[ile++]=l;
			prze.pb(pom);
			pom.clear();
		}
	}
	for(int i=1;i<=n;++i){
		int e=1e9;
		for(int j=0;j<w[i].size();++j)e=min(e,w[i][j]);
		tab[i]=e;
	}
	for(int i=0;i<ile;++i){
		bool q=0;
		for(int j=0;j<prze[i].size();++j)
			if(tab[start[i]+j]==prze[i][j])q=1;
		if(!q){
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;++i)printf("%d ",tab[i]);
	return 0;
}