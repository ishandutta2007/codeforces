#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<int,pii>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int n,L[62],R[62];
void solve(){
    cin>>n;
    rep(i,0,n){
        int l,r,ans=0,cntr=0,cntans=0,tempr;
        cin>>l>>r;
        tempr=r;
        for(int j=61;j>=0;j--){
            L[j]=l%2;
            R[j]=r%2;
            l/=2;
            r/=2;
            cntr+=R[j];
        }
        rep(j,0,62){
            if(L[j]!=R[j]){
                ans=ans+(1LL<<(61-j))-1;
                cntans+=61-j;
                break;
            }
            else if(R[j]) ans+=(1LL<<(61-j)),cntans++;
        }
        if(cntans<cntr){
            cout<<tempr<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}