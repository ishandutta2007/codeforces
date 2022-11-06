#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
const ll inf=1e18;
int a[N],b[N];
int main(){int n;
	scanf("%d",&n);
	int ls=0,cnt=0,ans=0;
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(i>1&&a[i]==a[i-1]){
			if(i>2&&a[i-1]==a[i-2])continue;
			if(a[i]==ls){
				rep(j,2,cnt-1)if(b[j]!=ls&&b[j-1]!=b[j+1]){
					++ans;break;
				}
			}else ++ans;
			b[1]=ls=a[i];cnt=1;
		}else{
			++ans;b[++cnt]=a[i];
		}
	}
	printf("%d\n",ans);
}