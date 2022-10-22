#include <bits/stdc++.h>
#define N 105
#define INF 5000000
using namespace std;
typedef long long ll;
int n,m,board[N][N];
int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={1,0,-1,1,-1,1,0,-1};
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<s.size();j++){
            if(s[j]=='.')
                board[i][j+1]=0;
            else if(s[j]=='*')
                board[i][j+1]=-1;
            else
                board[i][j+1]=s[j]-'0';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int sum=0;
                for(int k=0;k<8;k++)
                    if(board[i+dx[k]][j+dy[k]]==-1)
                        sum++;
            if(board[i][j]!=-1&&board[i][j]){
                if(sum!=board[i][j]){
                    cout<<"NO";
                    return 0;
                }
            }
            if(!board[i][j]&&sum){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}