/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL sum[200000+20];
LL res=1000000000000000;
int n;
int a[200000+20];
int main(){
	fastio;
	cin>>n;
	int k;
	cin>>k;
	rb(i,1,n)
		cin>>a[i];
	sort(a+1,a+1+n);
//	rb(i,1,n)
//	cout<<a[i]<<" ";
	rb(i,1,n)
		sum[i]=sum[i-1]+a[i];
//	rb(i,1,n)
//		cout<<sum[i]<<" ";cout<<endl; 
	if(k==1){
		cout<<0<<endl;
		return 0;
	}
	else{
		int las=-1,cnt=0;
		rb(i,1,n){
			if(a[i]==a[i-1]){
				cnt++;
				if(cnt>=k){
					cout<<0<<endl;
					return 0;
				}
			}
			else{
				cnt=1;
			}
		}
		
		rb(i,1,n){
			int l=1;
			if(a[i]!=a[i-1]){
				l=i;
				while(a[l+1]==a[i]){
					l++;
				}
				if((n-i+1)>=k){
				if(a[l+1]==a[n]&&a[l+1]==a[i]+1){
					res=min(res,(LL)k-(l-i+1));
				}
				res=min(res,sum[n]-sum[l]-(LL)(a[i]+1)*(n-l)+(LL)k-(l-i+1));
				}
				if(l>=k){
				if(a[i-1]==a[1]&&a[i-1]==a[i]-1){
					res=min(res,(LL)k-(l-i+1));
				}
				res=min(res,(LL)(i-1)*(a[i]-1)-sum[i-1]+(LL)k-(l-i+1));
				}
				res=min(res,sum[n]-sum[l]-(LL)(a[i]+1)*(n-l)+(LL)(i-1)*(a[i]-1)-sum[i-1]+(LL)k-(l-i+1));
				if(i!=1&&l!=n){
					LL tmp=0;
					int need=k-(l-i+1);
					if(a[l+1]==a[n]&&a[i-1]==a[1]&&a[l+1]==a[i]+1&&a[i-1]==a[i]-1){
						tmp+=need;
						res=min(res,tmp);
					}
				}
			}
			else{
				continue;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}
/*
10 10
921851939 921851369 921852128 921851994 921851660 921851641 921852265 921851938 921851895 921851686	

*/