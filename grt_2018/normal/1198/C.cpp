#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
#define PB push_back
#define ST first
#define ND second

const int nax = 300*1000+10;
int T,n,m;
vi matching;
bool taken[nax];

int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		for(int i=1; i<=3*n;i++) taken[i] = 0;
		matching.clear();
		for(int a,b,i=0; i<m;i++) {
			scanf("%d%d",&a,&b);
			if(!taken[a]&&!taken[b]) {
				taken[a] = taken[b] = 1;
				matching.PB(i+1);
			}
		}
		if((int)matching.size()>=n) {
			printf("Matching\n");
			for(int i=0; i<n;i++) printf("%d ",matching[i]);
		} else {
			int s = 0;
			printf("IndSet\n");
			for(int i=1; i<=3*n;i++) {
				if(!taken[i]) {
					printf("%d ",i);
					s++;
				}
				if(s==n) break;
			}
		}
		printf("\n");
	}
}