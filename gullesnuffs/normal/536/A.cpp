#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int A,B,n;
long long getTime(long long l, long long r, long long m){
	long long val1=(r-l+1)*(A+B*(l-1));
	val1 += B*((r-l+1)*(r-l))/2;
	long long d=m;
	long long ans=(val1+d-1)/d;
	if(A+(r-1)*B > ans)
		ans=A+(r-1)*B;
	/*if(r-l < 10){
		for(int i=l; i <= r; ++i){
			printf("%d ", A+(i-1)*B);
		}
		printf("\nTime(%I64d,%I64d,%I64d)=%I64d, val=%I64d\n\n",l,r,m,ans, val1);
	}*/
	return ans;
}

int main(){
	scanf("%d%d%d", &A,&B,&n);
	rep(i,0,n){
		int l,t,m;
		scanf("%d%d%d", &l, &t, &m);
		long long lo=l-1,hi=l+1000000;
		while(hi-lo > 1){
			long long mid=(hi+lo)/2;
			if(getTime(l,mid,m) > t)
				hi=mid;
			else
				lo=mid;
		}
		if(lo >= l)
			printf("%I64d\n", lo);
		else
			puts("-1");
		/*long long sum=0;
		long long ans=-1;
		for(long long j=l; ; ++j){
			sum += A+(j-1)*B;
			long long M;
			if(m < j-l+1)
				M=m;
			else
				M=j-l+1;
			if(M*t < sum || A+(j-1)*B > t){
				if(j == l){
					ans=-1;
				}
				else
					ans=j-1;
				break;
			}
		}
		printf("%I64d\n", ans);*/
	}
}