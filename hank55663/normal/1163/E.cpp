#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
using namespace std;	
int s[200005];
int vis[500005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&s[i]);
	}
	vector<int> v;
	int Max=20;
	while(true){
		
		for(int i = 0;i<n;i++){
			if(s[i]>=(1<<(Max+1)))
				continue;
			int temp=s[i];
			for(auto &it:v){
				s[i]=min(s[i],it^s[i]);
				if(s[i]>it)
				swap(s[i],it);
			}
			if(s[i]!=0)
			v.pb(s[i]);
			s[i]=temp;
		}
		//printf("%d %d\n",v.size(),Max);
		if(v.size()!=Max+1){
			v.clear();
			Max--;
		}
		else{
			break;
		}
		if(Max==-1){
			printf("0\n0\n");
			return 0;
		}
	}
	printf("%d\n",Max+1);
	vector<int> ans;
	vis[0]=1;
	ans.pb(0);
	for(int i = 0;i<=Max;i++){
		for(int j = 0;j<n;j++){
			if(s[j]<(1<<(Max+1))){
				if(vis[ans.back()^s[j]]==0){
					for(int k = ans.size()-1;k>=0;k--){
						ans.pb(ans[k]^s[j]);
						vis[ans[k]^s[j]]=1;
					}
					break;
				}
			}
		}
	}
	for(auto it:ans)
	printf("%d ",it);
	return 0;
}
/*




*/