#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007LL
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int n,m,cur=1,v[1001][1001],val[1000006],cnt;
string s[1001];
void dfs(int x,int y){
    if(x<0 || y<0 || x>=n || y>=m || s[x][y]=='*' || v[x][y]) return ;
    v[x][y]=cur;
    cnt++;
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x,y-1);
    dfs(x-1,y);
}
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>s[i];
    }
    rep(i,0,n){
        rep(j,0,m){
            if(s[i][j]=='.' && v[i][j]==0){
                cnt=0;
                dfs(i,j);
                val[cur]=cnt;
                cur++;
            }
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            if(s[i][j]=='.') cout<<".";
            else{
                int ans=0;
                set<int> s;
                if(i) s.insert(v[i-1][j]);
                if(j) s.insert(v[i][j-1]);
                if(i<n-1) s.insert(v[i+1][j]);
                if(j<m-1) s.insert(v[i][j+1]);
                for(auto i:s){
                    ans+=val[i];
                }
                cout<<(ans+1)%10;
            }
        }
        cout<<endl;
    }
}

signed main()
{
    /*ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}