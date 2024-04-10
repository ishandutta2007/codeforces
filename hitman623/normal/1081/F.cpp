#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,a[303],flipped[303];
int query(int l,int r){
	cout<<"? "<<l<<" "<<r<<endl;
	cin>>l;
	return l;
}
void flip(int l,int r){
	rep(i,l,r+1) flipped[i]^=1;
}
void sol(int l,int r,int segk,bool f){
	if(l>r) return;
	int lc=0,rc=0;
	rep(i,1,l) lc+=a[i]^flipped[i];
	rep(i,r+1,n+1) rc+=a[i]^flipped[i];
	if(l==r) a[l]=flipped[l]^segk;
	else if(f){
		while(1){
			int q=query(l,r-1);
			if(lc+n-r-rc+r-l+1-segk==q){
				segk=r-l+1-segk;
				rc=n-r-rc;
				flip(l,n);
			}
			else{
				int g=(q+1+lc+segk-r-rc)/2;
				a[r]=flipped[r]^g;
				lc=l-1-lc;
				segk=r-l-segk+2*g;
				flip(1,r-1);
				sol(l,r,segk,!f);
				return;
			}
		}
	}
	else{
		while(1){
			int q=query(l+1,r);
			if(l-1-lc+rc+r-l+1-segk==q){
				segk=r-l+1-segk;
				lc=l-1-lc;
				flip(1,r);
			}
			else{
				int g=(q+rc+l+segk-n-lc)/2;
				a[l]=flipped[l]^g;
				rc=n-r-rc;
				segk=r-l-segk+g;
				flip(l+1,n);
				sol(l+1,r-1,segk-(a[r]^flipped[r]),!f);
				return;
			}
		}
	}
}
void disp(){
	cout<<"! ";
	rep(i,1,n+1) cout<<a[i];
	cout<<endl;
}
void solve(){
	cin>>n>>k;
	sol(1,n,k,1);
	disp();
}

signed main(){
	int t=1;
    // cin>>t;
	while(t--){
		solve();
	}
	return 0;
}