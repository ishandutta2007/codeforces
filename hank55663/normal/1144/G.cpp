#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
int l[200005],lr[200005];
int r[200005],rl[2000005];
int main(){
	int n;
	scanf("%d",&n);
	int a[200005];
	for(int i =1;i<=n;i++){
		scanf("%d",&a[i]);
	}

	fill(l,l+n+1,1e9);
	fill(lr,lr+n+1,-1);
	l[0]=-1;
	lr[0]=1e9;
	vector<int> stk;
	stk.pb(1e9+1);
	for(int i = 1;i<=n;i++){
		if(stk.back()>a[i]&&l[i-1]<a[i]){
			l[i]=l[i-1];
			lr[i]=max(stk.back()-1,l[i]);
			stk.pb(a[i]);
		}
		else{
			l[i]=l[i-1];
			int ok=1;
			//if(stk.back()<=a[i]){
				if(stk.back()>l[i]){
					l[i]=stk.back();
					stk.pop_back();
				}
				else if(l[i]<a[i]){
					l[i]=a[i];
				}
				else{
					ok=0;
					//break;
				}
			//}
			if(stk.back()<=a[i]){
				ok=0;
			}
			lr[i]=max(stk.back()-1,l[i]);
			stk.pb(a[i]);
			if(!ok||stk.back()<=l[i]){
				l[i]=1e9;
				lr[i]=0;
				break;
			}
		}
	}
	fill(r,r+n+1,1e9);
	fill(rl,rl+n+1,-1);
	r[n+1]=-1;
	rl[n+1]=1e9;
	stk.clear();
	stk.pb(1e9+1);
	for(int i = n;i>=1;i--){
		if(stk.back()>a[i]&&r[i+1]<a[i]){
			r[i]=r[i+1];
			rl[i]=max(stk.back()-1,r[i]);
			stk.pb(a[i]);
		}
		else{
			r[i]=r[i+1];
			int ok=1;
			//if(stk.back()<=a[i]){
				if(stk.back()>r[i]){
					r[i]=stk.back();
					stk.pop_back();
				}
				else if(a[i]>r[i]){
					r[i]=a[i];
				}
				else{
					ok=0;
					//break;
				}
			//}
			if(stk.back()<=a[i]){
				ok=0;
			}
			rl[i]=max(stk.back()-1,r[i]);
			stk.pb(a[i]);
			if(!ok||stk.back()<=r[i]){
				r[i]=1e9;
				rl[i]=0;
				break;
			}
		}
	}
	int ans[200005];
	for(int i =0;i<=n;i++){
	//	printf("%d %d %d %d\n",l[i],lr[i],r[i+1],rl[i+1]);
		if(l[i]<=r[i+1]&&r[i+1]<=lr[i]&&r[i+1]<=rl[i+1]&&l[i]<=lr[i]){
			printf("YES\n");
			for(int j  =1;j<=i;j++){
				if(a[j]<=r[i+1])
					ans[j]=0;
				else 
					ans[j]=1;
			}
			for(int j=i+1;j<=n;j++){
				if(a[j]<=r[i+1])
					ans[j]=1;
				else
					ans[j]=0;
			}
			for(int j =1;j<=n;j++)
			printf("%d ",ans[j]);
			printf("\n");
			return 0;
		}
		if(r[i+1]<=l[i]&&l[i]<=rl[i+1]&&l[i]<=lr[i]&&r[i+1]<=rl[i+1]){
			printf("YES\n");
			for(int j  =1;j<=i;j++){
				if(a[j]<=l[i])
					ans[j]=0;
				else 
					ans[j]=1;
			}
			for(int j=i+1;j<=n;j++){
				if(a[j]<=l[i])
					ans[j]=1;
				else
					ans[j]=0;
			}
			for(int j =1;j<=n;j++)
			printf("%d ",ans[j]);
			printf("\n");
			return 0;
		}
	}
	printf("NO\n");
}