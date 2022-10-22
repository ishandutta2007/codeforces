/*
AuThOr Gwj
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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int dp[505][505],chafen[505][505];	
int n,k;
LL a[505],b[505];
LL s1,s2;

int main(){
	fastio;
	dp[0][0]=1;
	cin>>n>>k;
	rb(i,1,n)
		cin>>a[i]>>b[i],s1+=a[i],s2+=b[i];
	rb(i,1,n){
		rl(j,n-1,0){
			rep(l,k){
				chafen[j+1][l]=0;
			}
			rb(l,0,k-1){
				if(l)
				chafen[j][l]+=chafen[j][l-1];
				dp[j][l]|=chafen[j][l];
				if(a[i]+b[i]>=k&&dp[j][l]){
					int L,R;
					L=max(1,k-(int)b[i]);
					R=min((int)a[i],k-1);
//					cout<<i<<" "<<L<<" "<<R<<" "<<l<<endl; 
					if(L<=R){
//						cout<<"!"<<endl;
						int St=l+L;
						St%=k;
						chafen[j+1][St]++;
						int Ed=l+R;
						Ed%=k;
//						cout<<St<<" "<<Ed<<endl;
						if(Ed>=St){
							chafen[j+1][Ed+1]--;
						}
						else{
							chafen[j+1][0]++;
							chafen[j+1][Ed+1]--;
						}
					}
				} 
			}
		}
	}
	rb(i,1,n)
	rep(l,k){
		if(l)
		chafen[i][l]+=chafen[i][l-1];
		dp[i][l]|=chafen[i][l];
	}
	LL res=0;
	rep(i,n+1){
		rep(j,k){
			if(!dp[i][j]) continue;
//			cout<<i
			LL l1,l2;
			l1=s1,l2=s2;
			l1-=j;
			l2-=(k-j)%k;
			LL cur=bool(j)+(l1/k)+(l2/k);
//			cout<<i<<" "<<j<<" "<<cur<<endl;	
			res=max(res,cur);
		}
	}
	
	cout<<res<<endl;
	return 0;
}