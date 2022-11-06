#include<cstdio>
#include<map>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 1001
using namespace std;
int n,ans,a[N],b[N];map<int,int>mp;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)if(a[i]==0)ans++;
	rep(i,1,n)mp[a[i]]++;
	rep(i,1,n)rep(j,1,n)if(i!=j&&(a[i]!=0||a[j]!=0)){
		b[1]=a[i];b[2]=a[j];
		mp[b[1]]--;mp[b[2]]--;
		rep(k,3,n+1){
			b[k]=b[k-2]+b[k-1];
			if(!mp[b[k]]){
				if(k-1>ans)ans=k-1;
				rep(s,1,k-1)mp[b[s]]++;
				break;
			}
			mp[b[k]]--;
		}
	}
	printf("%d\n",ans);
}