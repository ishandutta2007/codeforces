#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
int a[N],b[N],l[N],r[N];
int main(){int n,ans=0;
	scanf("%d",&n);stack<int>stk;
	rep(i,1,n){
		scanf("%d",&a[i]);b[a[i]]=i;
		while(!stk.empty()&&a[i]>a[stk.top()]){
			r[stk.top()]=i-1;stk.pop();
		}
		l[i]=stk.empty()?1:stk.top()+1;stk.push(i);
	}
	while(!stk.empty()){
		r[stk.top()]=n;stk.pop();
	}
	rep(i,1,n){
		if(i-l[i]<r[i]-i){
			rep(j,l[i],i-1){
				int x=b[a[i]-a[j]];
				if(x>i&&x<=r[i])++ans;
			}
		}else{
			rep(j,i+1,r[i]){
				int x=b[a[i]-a[j]];
				if(x<i&&x>=l[i])++ans;
			}
		}
	}
	printf("%d\n",ans);
}