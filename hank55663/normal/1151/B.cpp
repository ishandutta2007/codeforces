#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
typedef complex<double> C;
int main()
{
	int n,mm;
	scanf("%d %d",&n,&mm);
	map<int,int> m[505];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<mm;j++){
			int x;
			scanf("%d",&x);
			m[i][x]=j;
		}
	}
	vector<pii> ans;
	int sum=0;
	for(int i = 0;i<n;i++){
		ans.pb(*m[i].begin());
		sum^=ans.back().x;
	}
	if(sum==0){
		int ok=0;
		for(int i = 0;i<n;i++){
			if(m[i].size()!=1){
				ans[i]=*m[i].rbegin();
				ok=1;
				break;
			}
		}
		if(!ok){
			printf("NIE\n");
			return 0;
		}
	}
	printf("TAK\n");
	for(auto it:ans)
	printf("%d ",it.y+1);
	printf("\n");
}