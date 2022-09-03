#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int a[1000005];
int b[1000005];
bool cal(int n){
	int Min=0,Max=b[0];
	while(Min<=Max){
		int mid=(Max+Min)/2;
		int now=b[0]-mid;
		int ok=1;
		for(int i = 1;i<n;i++){
			int need=max(a[i]-now,0);
			if(need>b[i]){
				ok=0;
				break;
			}
			else{
				now=b[i]-need;
			}
		}
		if(!ok){
			Max=mid-1;
		}
		else if(now+mid>=a[0]){
			return true;
		}
		else{
			Min=mid+1;
		}
	}
	return false;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);

		for(int i = 0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i = 0;i<n;i++){
			scanf("%d",&b[i]);
		}
		if(cal(n)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}