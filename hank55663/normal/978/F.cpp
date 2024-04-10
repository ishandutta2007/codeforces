#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int temp[200005];
	vector<int> v;
	for(int i =1;i<=n;i++){
		scanf("%d",&temp[i]);
		v.pb(temp[i]);
	}
	sort(v.begin(),v.end());
	int ans[200005];
	for(int i =1;i<=n;i++){
		ans[i]=lower_bound(v.begin(),v.end(),temp[i])-v.begin();
	}
	while(k--){
		int x,y;
		scanf("%d %d",&x,&y);
		if(temp[x]>temp[y]){
			ans[x]--;
		}
		if(temp[x]<temp[y]){
			ans[y]--;
		}
	}
	for(int i = 1;i<=n;i++)
	printf("%d ",ans[i]);
}