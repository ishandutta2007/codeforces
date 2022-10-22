#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;


const int MAX_N = 21;
const int MAX_K = 360;

bool vst[MAX_N+1][MAX_K+1];
bool chk[MAX_N+1][MAX_K+1][4];

vector<pii> vt;


int main()
{
    int T;
    cin>>T;
    while(T--){
        int N, M;
        for(int i=1; i<=MAX_N; i++){
            for(int j=1; j<=MAX_K; j++){
                vst[i][j] = false;
                for(int k=0; k<4; k++){
                    chk[i][j][k] = 0;
                }
            }
        }
        cin>>N;
        
        for(int i=0; i<N; i++){
            char c;
            int x, y, z;
            cin>>c>>x>>y>>z;
            if(c=='C'){
                if(y<z){
                    for(int k=y+1; k<=z; k++){
                        chk[x][k][0]=true;
                        chk[x+1][k][3] = true;
                    }
                }
                else if(y>z){
                    for(int k=y+1; k<=360; k++){
                        chk[x][k][0] = true;
                        chk[x+1][k][3] = true;
                    }
                    for(int k=1; k<=z; k++){
                        chk[x][k][0] = true;
                        chk[x+1][k][3] = true;
                    }
                }
            }else{
                for(int r=x+1; r<=y; r++){
                    if(z==0){
                        chk[r][1][2] = 1;
                        chk[r][360][1] = 1;
                    }else{ 
                        chk[r][z+1][2] = 1;
                        chk[r][z][1] = 1;
                    }
                }
            }
        }
        bool tf = false;
        vt.clear();
        vt.pb({1, 1});
        vst[1][1] = true;
        while(!vt.empty()){
            pii n = vt.back(); vt.pop_back();
            if(n.first==MAX_N){
                tf = true;
                break;
            }
            if(n.first!=1 && !chk[n.first][n.second][3] && !vst[n.first-1][n.second]){
                vt.pb({n.first-1, n.second});
                vst[n.first-1][n.second] = true;
            }
            if(n.first!=MAX_N && !chk[n.first][n.second][0] && !vst[n.first+1][n.second]){
                vt.pb({n.first+1, n.second});
                vst[n.first+1][n.second] = true;
            }
            if(!chk[n.first][n.second][1] && !vst[n.first][n.second%360+1]){
                vt.pb({n.first, n.second%360+1});
                vst[n.first][n.second%360+1] = true;
            }        
            if(!chk[n.first][n.second][2] && !vst[n.first][(n.second+360-2)%360+1]){
                vt.pb({n.first, (n.second+360-2)%360+1});
                vst[n.first][(n.second+360-2)%360+1] = true;
            }
        }

        if(tf){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }

    }
    return 0;
}