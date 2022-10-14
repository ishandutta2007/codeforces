/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
int query(int x,int l,int r){
	if(l>r) return 0;
	cout<<"? "<<1<<' '<<r-l+1<<endl;
	cout<<x<<endl;
	rb(i,l,r){
		cout<<i<<' ';
	}
	cout<<endl;
	int X;
	ff;
	cin>>X;
	return X;
}
void solve(){
	scanf("%d",&n);
	vector<int> rest;
	rb(i,1,n){
		int cnt=query(i,i+1,n);
		if(cnt!=0){
			rb(j,i+1,n){
				int nex=query(i,j+1,n);
				if(cnt==nex){
					rest.PB(j);
				}
				cnt=nex;
			}
			{
				int l=1,r=i;
				while(l<r){
					int mid=(l+r)>>1;
					if(mid!=i&&query(i,1,mid)){
						r=mid;
					}
					else{
						l=mid+1;
					}
				}
				if(l<i){
					sort(ALL(rest));
					rest.erase(lower_bound(ALL(rest),l));
				}
			}
			break;
		}
		rest.PB(i);
	}
	cout<<"! "<<rest.size()<<' ';
	for(auto it:rest){
		cout<<it<<" ";
	}
	cout<<endl;ff;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();	
	return 0;
}