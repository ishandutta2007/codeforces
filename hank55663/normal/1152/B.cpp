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
#define sqr(x) ((x)*(x))
int main(){
	int x;
	scanf("%d",&x);
	int ans=0;
	vector<int> v;
	while(__builtin_popcount(x+1)!=1){
		for(int j=0;j<22;j++){
			if((1<<j)&x){
				v.pb(j);
				x^=(1<<j)-1;
				ans++;
				break;
			}
		}
		//printf("%d\n",x);
		if(__builtin_popcount(x+1)==1){
			break;
		}
		x++;
		ans++;
	//	printf("%d\n",x);
		//getchar();
	}
	printf("%d\n",ans);
	for(auto it:v)
	printf("%d ",it);
}