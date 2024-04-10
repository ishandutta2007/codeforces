#include<bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define x first 
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int sum=0;
	int a[100005];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum%k!=0){
		printf("No\n");
	}
	else{
		vector<int> v;
		sum/=k;
		int ss=0;
		int cnt=0;
		for(int i=0;i<n;i++){
			ss+=a[i];
			cnt++;
			//printf("%d %d\n",sum,ss);
			if(ss==sum){
				v.pb(cnt);
				cnt=0;
				ss=0;
			}
			if(ss>sum){
				printf("No\n");
				return 0;
			}
		}
		//v.pb(cnt);
		printf("Yes\n");
		for(auto it:v)
		printf("%d ",it);
		printf("\n");
	}
}