#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<ll,ll,ll> tll;
typedef vector<vector<ll>> mat;
const ll mod=998244353;
const int N=105;
int t,r,c,k,x,y,md,cnt,res,a[N][N];
char ans[N][N],cur;
string s;
void solve(){
    cin>>r>>c>>k;
    cnt=0; x=y=md=1; cur='0';
    for(int i=1;i<=r;i++) for(int j=1;j<=c;j++) ans[i][j]='-';
    for(int i=1;i<=r;i++){
        cin>>s;
        for(int j=1;j<=c;j++){
            if(s[j-1]=='R'){
                a[i][j]=1;
                cnt++;
            }
            else a[i][j]=0;
        }
    }
    res=cnt/k;
    for(int i=1;i<=k;i++){
        int curv=0;
        if(i<=cnt%k){
            while(curv<res+1){
                ans[x][y]=cur;
                if(a[x][y]) curv++;
                if(md==1){
                    y++;
                    if(y>c){
                        x++; y--;
                        md=2;
                    }
                }
                else if(md==2){
                    y--;
                    if(y<1){
                        x++; y++;
                        md=1;
                    }
                }
            }
        }
        else{
            while(curv<res){
                ans[x][y]=cur;
                if(a[x][y]) curv++;
                if(md==1){
                    y++;
                    if(y>c){
                        x++; y--;
                        md=2;
                    }
                }
                else if(md==2){
                    y--;
                    if(y<1){
                        x++; y++;
                        md=1;
                    }
                }
            }
        }
        if(i==k){
            for(int ii=1;ii<=r;ii++) for(int jj=1;jj<=c;jj++) if(ans[ii][jj]=='-'){
                ans[ii][jj]=cur;
            }
        }
        if(cur=='9') cur='a';
        else if(cur=='z') cur='A';
        else cur++;
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++) cout<<ans[i][j];
        cout<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>t;
    while(t--) solve();
    return 0;
}