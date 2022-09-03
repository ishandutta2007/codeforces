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
int mod=998244353;
int main(){
	int n,d;
	scanf("%d %d",&n,&d);
	vector<int> v;
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.pb(x);
	}
	sort(v.begin(),v.end());
	v.pb(1e9);
	int ans=1e9;
	for(int i = 0;i<n;i++){
		for(int j = i;j<=n;j++){
			if(v[j]>v[i]+d){
				ans=min(ans,i+n-j);
				break;
			}
		}
	}
	printf("%d\n",ans);
}