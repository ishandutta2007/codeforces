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
int a[100000+1];
int each[65];
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
	LL n;
	int m;
	cin>>n>>m;	
	rb(i,1,m){
		cin>>a[i];
		a[i]=log2(double(a[i]));
//		cout<<a[i]<<endl;
	}
	rep(i,62)
		each[i]=0;	
	rb(i,1,m)
		each[a[i]]++;
	int res=0;
	rep(i,62){
		if((n&(1ll<<i))){
			int ok=0;
			if(!each[i]){
				rep(j,62){
					if(j>=i){
						if(each[j]){
							ok=1;
							int now=j;
							while(now){
								if(now==i) break;
								each[now]--;
								each[now-1]+=2;
								res++;
								now--;
							}
							each[now]--;
							break;
						}
					}
				}if(!ok){
				res=-INF;
			}
			}
			else{
				each[i]--;
			}
		}
		each[i+1]+=each[i]/2;
	}
	res=max(res,-1);cout<<res<<endl;
	}
	return 0;
}