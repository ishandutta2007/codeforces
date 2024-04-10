#include <bits/stdc++.h>
#define N 505
using namespace std;
int board[N][N],n,m;
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=m;j++){
            if(s[j-1]=='S')
                board[i][j]=1;
            if(s[j-1]=='W')
                board[i][j]=2;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(board[i][j]!=2)
                continue;
            for(int k=0;k<4;k++){
                if(board[i+dx[k]][j+dy[k]]==1){
                    cout<<"No";
                    return 0;
                }
            }
        }
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!board[i][j])
                cout<<'D';
            else if(board[i][j]==1)
                cout<<'S';
            else
                cout<<'W';
        }
        cout<<'\n';
    }
    return 0;
}