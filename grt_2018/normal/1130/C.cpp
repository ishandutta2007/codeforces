#include <bits/stdc++.h>

using namespace std;

#define ST first
#define ND second

const int MAXN = 51;
int n;
vector<int>V[MAXN*MAXN];
bool ok[MAXN][MAXN];
int start,koniec;
int SC[MAXN*MAXN];
vector<int>col1[MAXN],col2[MAXN];

void dfs(int x,int id) {
    SC[x] = id;
    for(auto nbh:V[x])
        if(SC[nbh]==0) dfs(nbh,id);
}

int ans=1000*1000*1000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int a,b; cin>>a>>b;
    start = (a-1)*n+b;
    cin>>a>>b;
    koniec= (a-1)*n+b;
    string s;
    for(int i=1; i<=n;i++) {
        cin>>s;
        for(int j=1; j<=n;j++) {
            if(s[j-1]=='1') ok[i][j]=0;
            else ok[i][j]=1;
        }
    }
    for(int i=1; i<=n;i++) {
        for(int j=1; j<=n;j++) {
            if(!ok[i][j]) continue;
            if(ok[i-1][j]) {
                V[(i-1)*n+j].push_back((i-2)*n+j);
                V[(i-2)*n+j].push_back((i-1)*n+j);
            }
            if(ok[i+1][j]) {
                V[(i-1)*n+j].push_back((i)*n+j);
                V[(i)*n+j].push_back((i-1)*n+j);
            }
            if(ok[i][j-1]) {
                V[(i-1)*n+j].push_back((i-1)*n+j-1);
                V[(i-1)*n+j-1].push_back((i-1)*n+j);
            }
            if(ok[i][j+1]) {
                V[(i-1)*n+j].push_back((i-1)*n+j+1);
                V[(i-1)*n+j+1].push_back((i-1)*n+j);
            }
        }
    }
    dfs(start,1);
    if(SC[start]==SC[koniec]) {cout<<"0"; return 0;}
    dfs(koniec,2);
    for(int i=1; i<=n;i++) {
        for(int j=1; j<=n;j++) {
            if(SC[(i-1)*n+j]==1) col1[j].push_back(i);
            if(SC[(i-1)*n+j]==2) col2[j].push_back(i);
        }
    }
    for(int i=1; i<=n;i++) {
        for(int j=1; j<=n;j++) {
            int wsk=0;
            if(col2[j].size()==0) continue;
            for(int k=0; k<col1[i].size();k++) {
                while(wsk+1<col2[j].size()&&(col2[j][wsk+1]-col1[i][k])*(col2[j][wsk+1]-col1[i][k])<
                      (col2[j][wsk]-col1[i][k])*(col2[j][wsk]-col1[i][k]))
                        wsk++;
                ans=min(ans,(col2[j][wsk]-col1[i][k])*(col2[j][wsk]-col1[i][k])+
                        (i-j)*(i-j));
            }
        }
    }
    cout<<ans;
    return 0;
}