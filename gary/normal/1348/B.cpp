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
int main(){
	fastio;
	int t;
	cin>>t;
	int a[101],cnt[101],be[101];
	while(t--){
		int n,k;
		cin>>n>>k;
		memset(cnt,0,sizeof(cnt));
		rb(i,1,n)
			cin>>a[i],cnt[a[i]]++;
		int tp=0;
		rb(i,1,n){
			tp+=bool(cnt[i]);
					
		}
		if(tp>k){
			cout<<-1<<endl;
		}
		else{
			cout<<n*k<<endl;
			sort(a+1,a+1+n);
			int id=1;
			rb(i,1,n){
				if(a[i]==a[i-1]){
					
				}
				else{
					be[id++]=a[i];
				}
			}
			rb(i,id,k){
				rb(j,1,n){
					if(!cnt[j]){
						be[i]=j;
						cnt[j]=1;
						break;
					}
				}
			}
			rb(blo,1,n){
				rb(i,1,k){
					cout<<be[i]<<" ";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}