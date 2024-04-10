#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int adj[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
long long a[1001][1001],k;
int n,m;
int parx[1001][1001],pary[1001][1001],size[1001][1001];
bool vis[1002][1002],use[1001][1001];
int maxi=1,inc=0;
vector<pair<long long,pair<int,int> > >sorti;
pair<int,int>curr;
pair<int,int>find(int x,int y){
    if(parx[x][y]!=x || pary[x][y]!=y){
        int temp=parx[x][y];
        parx[x][y]=find(temp,pary[x][y]).first;
        pary[x][y]=find(temp,pary[x][y]).second;
    }
    return make_pair(parx[x][y],pary[x][y]);
}
void addlink(int x1,int y1,int x2,int y2){
    if(find(x2,y2)==find(x1,y1)) return;
    size[find(x2,y2).first][find(x2,y2).second]+=\
    size[find(x1,y1).first][find(x1,y1).second];
    maxi=max(maxi,size[find(x2,y2).first][find(x2,y2).second]);
    pair<int,int>temp=find(x1,y1);
    parx[temp.first][temp.second]=find(x2,y2).first;
    pary[temp.first][temp.second]=find(x2,y2).second;
}
bool ingrid(int x,int y){
    return (x>0 && x<=n && y>0 && y<=m);
}
void dfs(int x,int y){
    if(inc==maxi) return;
    inc++;
    use[x][y]=true;
    for(int i=0; i<4 ;i++){
        if(ingrid(x+adj[i][0],y+adj[i][1]) && find(x+adj[i][0],y+adj[i][1])==curr){
            if(!use[x+adj[i][0]][y+adj[i][1]]) dfs(x+adj[i][0],y+adj[i][1]);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i=1; i<=n ;i++){
        for(int j=1; j<=m ;j++){
            cin >> a[i][j];
            parx[i][j]=i,pary[i][j]=j,size[i][j]=1;
            sorti.push_back(make_pair(a[i][j],make_pair(i,j)));
        }
    }
    sort(sorti.begin(),sorti.end());
    for(int i=sorti.size()-1; i>=0 ;i--){
        int xx=sorti[i].second.first,yy=sorti[i].second.second;
        vis[xx][yy]=true;
        for(int j=0; j<4 ;j++){
            if(vis[xx+adj[j][0]][yy+adj[j][1]]){
                addlink(xx,yy,xx+adj[j][0],yy+adj[j][1]);
            }
        }
        if(k%sorti[i].first==0 && maxi>=k/sorti[i].first){
            cout << "YES\n";
            curr=find(xx,yy);
            maxi=k/sorti[i].first;
            dfs(xx,yy);
            for(int g=1; g<=n ;g++){
                for(int h=1; h<=m ;h++){
                    if(use[g][h]){
                        inc++;
                        cout << sorti[i].first << ' ';
                    }
                    else cout << "0 ";
                }
                cout << '\n';
            }
            return 0;
        }
    }
    cout << "NO\n";
}