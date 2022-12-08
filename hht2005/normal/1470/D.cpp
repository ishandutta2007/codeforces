#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
vector<int>S[N];
int Cheer_CNYZ_on_For_IOI[N],q[N],in[N];
int main() {
	int T,n,m,a,b;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) {
			S[i].clear();
			in[i]=0;
			Cheer_CNYZ_on_For_IOI[i]=0;
		}
		for(int i=1;i<=m;i++) {
			scanf("%d%d",&a,&b);
			S[a].push_back(b);
			S[b].push_back(a);
		}
		int h=1,e=1;
		in[q[h]=1]=1;
		while(h<=e) {
			int x=q[h++];
			if(Cheer_CNYZ_on_For_IOI[x])continue;
			for(int y:S[x]) {
				if(Cheer_CNYZ_on_For_IOI[y])continue;
				Cheer_CNYZ_on_For_IOI[y]=1;
				in[y]=0;
				for(int z:S[y]) {
					if(!in[z]&&!Cheer_CNYZ_on_For_IOI[z])
						in[q[++e]=z]=1;
				}
			}
		}
		int FL=0,cnt=0;
		for(int i=1;i<=n;i++) {
			if(!in[i]&&!Cheer_CNYZ_on_For_IOI[i])FL=1;
			cnt+=in[i];
		}
		if(FL)puts("No");
		else {
			puts("Yes");
			printf("%d\n",cnt);
			for(int i=1;i<=n;i++)
				if(in[i])printf("%d ",i);
			puts("");
		}
	}
	return 0;
}